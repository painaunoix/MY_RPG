/*
** EPITECH PROJECT, 2024
** dog.c
** File description:
** dog
*/

#include "../../../Include/my.h"

static void set_texture_dog(rpg_t *rpg, int i)
{
    rpg->dog[i]->dog_tx = sfTexture_createFromFile(DOG_LEFT, NULL);
    rpg->dog[i]->dog_right = sfTexture_createFromFile(DOG_RIGHT, NULL);
    rpg->dog[i]->dog_l_red = sfTexture_createFromFile(DOG_LEFT_R, NULL);
    rpg->dog[i]->dog_r_red =
    sfTexture_createFromFile(DOG_RIGHT_R, NULL);
}

sfSprite *create_dog(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {0.8, 0.8};
    sfVector2f center = {x, y};
    sfVector2f center2 = {100, 120};
    sfSprite *sprite;

    rpg->dog[i]->dog_Rect = make_rect(196, 246);
    rpg->dog[i]->life = 8;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    set_texture_dog(rpg, i);
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(DOG_LEFT, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->dog[i]->dog_Rect);
    rpg->dog[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->dog[i]->zone, center2);
    sfCircleShape_setPosition(rpg->dog[i]->zone, center);
    sfCircleShape_setRadius(rpg->dog[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->dog[i]->zone, sfTransparent);
    return sprite;
}

void start_create_dog(rpg_t *rpg, int x, int y, int i)
{
    rpg->dog[i] = malloc(sizeof(dog_t));
    rpg->dog[i]->dog = create_dog(rpg, x, y, i);
    rpg->dog[i]->seconds = 0;
    rpg->dog[i + 1] = NULL;
}

static void setup_dog_wave(rpg_t *rpg)
{
    start_create_dog(rpg, 4339, 1812, 33);
    start_create_dog(rpg, 4589, 1812, 34);
    start_create_dog(rpg, 4089, 1812, 35);
    start_create_dog(rpg, 4339, 1206, 36);
    start_create_dog(rpg, 4589, 1206, 37);
    start_create_dog(rpg, 4089, 1206, 38);
    start_create_dog(rpg, 3816, 1506, 39);
    start_create_dog(rpg, 3816, 1756, 40);
    start_create_dog(rpg, 3816, 1256, 41);
    start_create_dog(rpg, 4872, 1256, 42);
    start_create_dog(rpg, 4872, 1756, 43);
    start_create_dog(rpg, 4872, 1506, 44);
}

static void setup_dog_dg2(rpg_t *rpg)
{
    start_create_dog(rpg, 1019, 4549, 26);
    start_create_dog(rpg, 1088, 4306, 27);
    start_create_dog(rpg, 1451, 4632, 28);
    start_create_dog(rpg, 1535, 4366, 29);
    start_create_dog(rpg, 5641, 4325, 30);
    start_create_dog(rpg, 6176, 3418, 31);
    start_create_dog(rpg, 7411, 3309, 32);
    setup_dog_wave(rpg);
}

static void setup_dog_dg(rpg_t *rpg)
{
    start_create_dog(rpg, 4473, 6132, 8);
    start_create_dog(rpg, 5580, 5181, 9);
    start_create_dog(rpg, 6618, 4716, 10);
    start_create_dog(rpg, 7242, 5352, 11);
    start_create_dog(rpg, 6565, 5714, 12);
    start_create_dog(rpg, 6718, 6440, 13);
    start_create_dog(rpg, 6661, 6809, 14);
    start_create_dog(rpg, 6206, 6427, 15);
    start_create_dog(rpg, 6361, 6752, 16);
    start_create_dog(rpg, 4266, 5172, 17);
    start_create_dog(rpg, 4566, 4233, 18);
    start_create_dog(rpg, 4546, 3181, 19);
    start_create_dog(rpg, 3732, 5712, 20);
    start_create_dog(rpg, 2871, 5025, 21);
    start_create_dog(rpg, 2187, 5991, 22);
    start_create_dog(rpg, 3087, 4026, 23);
    start_create_dog(rpg, 1841, 3481, 24);
    start_create_dog(rpg, 996, 3161, 25);
    setup_dog_dg2(rpg);
}

void setup_dog(rpg_t *rpg)
{
    rpg->dog = malloc(sizeof(dog_t *) * 46);
    start_create_dog(rpg, 3222, 4558, 0);
    start_create_dog(rpg, 2179, 4756, 1);
    start_create_dog(rpg, 3060, 4123, 2);
    start_create_dog(rpg, 5038, 4181, 3);
    start_create_dog(rpg, 5388, 4824, 4);
    start_create_dog(rpg, 6643, 4446, 5);
    start_create_dog(rpg, 7429, 4684, 6);
    start_create_dog(rpg, 7885, 4244, 7);
    setup_dog_dg(rpg);
}

void draw_dog(rpg_t *rpg)
{
    for (int i = 0; i <= 7; i++) {
        if (rpg->dog[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->dog[i]->dog, NULL);
        }
    }
}

static void anim_dog_split(rpg_t *rpg, int i)
{
    if (rpg->dog[i]->dog_Rect.left < 3936 - 246) {
        rpg->dog[i]->dog_Rect.left += 246;
    } else {
        rpg->dog[i]->dog_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->dog[i]->dog,
    rpg->dog[i]->dog_Rect);
    sfClock_restart(rpg->anim_monst->clock_dog);
}

void anim_dog(rpg_t *rpg)
{
    for (int i = 0; rpg->dog[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_dog > 0.2) {
            anim_dog_split(rpg, i);
        }
    }
}
