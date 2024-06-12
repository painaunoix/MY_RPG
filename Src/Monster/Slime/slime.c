/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

static sfSprite *create_slime_dg(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {0.2, 0.2};
    sfVector2f center = {x, y};
    sfVector2f center2 = {170, 170};
    sfSprite *sprite;

    rpg->slime[i]->slime_Rect = make_rect(320, 320);
    rpg->slime[i]->life = 7;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    rpg->slime[i]->slime_tx = sfTexture_createFromFile(SLIME_BLUE, NULL);
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(SLIME_BLUE, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->slime[i]->slime_Rect);
    rpg->slime[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->slime[i]->zone, center2);
    sfCircleShape_setPosition(rpg->slime[i]->zone, center);
    sfCircleShape_setRadius(rpg->slime[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->slime[i]->zone, sfTransparent);
    return sprite;
}

static void start_create_slime_dg(rpg_t *rpg, int x, int y, int i)
{
    rpg->slime[i] = malloc(sizeof(slime_t));
    rpg->slime[i]->slime = create_slime_dg(rpg, x, y, i);
    rpg->slime[i]->seconds = 0;
    rpg->slime[i + 1] = NULL;
}

sfSprite *create_slime(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {0.2, 0.2};
    sfVector2f center = {x, y};
    sfVector2f center2 = {170, 170};
    sfSprite *sprite;

    rpg->slime[i]->slime_Rect = make_rect(320, 320);
    rpg->slime[i]->life = 3;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    rpg->slime[i]->slime_tx = sfTexture_createFromFile(SLIME, NULL);
    sfSprite_setTexture(sprite, sfTexture_createFromFile(SLIME, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->slime[i]->slime_Rect);
    rpg->slime[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->slime[i]->zone, center2);
    sfCircleShape_setPosition(rpg->slime[i]->zone, center);
    sfCircleShape_setRadius(rpg->slime[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->slime[i]->zone, sfTransparent);
    return sprite;
}

void start_create_slime(rpg_t *rpg, int x, int y, int i)
{
    rpg->slime[i] = malloc(sizeof(slime_t));
    rpg->slime[i]->slime = create_slime(rpg, x, y, i);
    rpg->slime[i]->seconds = 0;
    rpg->slime[i + 1] = NULL;
}

static void setup_slime_dg2(rpg_t *rpg)
{
    start_create_slime_dg(rpg, 2250, 4143, 28);
    start_create_slime_dg(rpg, 4045, 4188, 29);
    start_create_slime_dg(rpg, 4497, 3929, 30);
    start_create_slime_dg(rpg, 4497, 2941, 31);
    start_create_slime_dg(rpg, 4750, 2941, 32);
    start_create_slime_dg(rpg, 4250, 2941, 33);
    start_create_slime_dg(rpg, 4497, 2455, 34);
    start_create_slime_dg(rpg, 4750, 2455, 35);
    start_create_slime_dg(rpg, 4250, 2455, 36);
    start_create_slime_dg(rpg, 4088, 2572, 37);
    start_create_slime_dg(rpg, 4088, 2848, 38);
    start_create_slime_dg(rpg, 4088, 2710, 39);
    start_create_slime_dg(rpg, 4910, 2572, 40);
    start_create_slime_dg(rpg, 4910, 2848, 41);
    start_create_slime_dg(rpg, 4910, 2710, 42);
}

static void setup_slime_dg(rpg_t *rpg)
{
    start_create_slime_dg(rpg, 4034, 5709, 9);
    start_create_slime_dg(rpg, 4045, 5056, 10);
    start_create_slime_dg(rpg, 4896, 4884, 11);
    start_create_slime_dg(rpg, 4752, 5511, 12);
    start_create_slime_dg(rpg, 5523, 5490, 13);
    start_create_slime_dg(rpg, 5843, 4877, 14);
    start_create_slime_dg(rpg, 5626, 5057, 15);
    start_create_slime_dg(rpg, 6302, 5111, 16);
    start_create_slime_dg(rpg, 6021, 5151, 17);
    start_create_slime_dg(rpg, 3191, 5415, 18);
    start_create_slime_dg(rpg, 2579, 5109, 19);
    start_create_slime_dg(rpg, 2135, 4804, 20);
    start_create_slime_dg(rpg, 2732, 5877, 21);
    start_create_slime_dg(rpg, 1812, 6239, 22);
    start_create_slime_dg(rpg, 1408, 5337, 23);
    start_create_slime_dg(rpg, 1152, 5061, 24);
    start_create_slime_dg(rpg, 1905, 3894, 25);
    start_create_slime_dg(rpg, 2249, 3901, 26);
    start_create_slime_dg(rpg, 1902, 4143, 27);
    setup_slime_dg2(rpg);
}

void setup_slime(rpg_t *rpg)
{
    rpg->slime = malloc(sizeof(slime_t *) * 44);
    start_create_slime(rpg, 4508, 8355, 0);
    start_create_slime(rpg, 5408, 8338, 1);
    start_create_slime(rpg, 3753, 7350, 2);
    start_create_slime(rpg, 4705, 7400, 3);
    start_create_slime(rpg, 5385, 7540, 4);
    start_create_slime(rpg, 4255, 6910, 5);
    start_create_slime(rpg, 5125, 6773, 6);
    start_create_slime(rpg, 5954, 7616, 7);
    start_create_slime(rpg, 3766, 8090, 8);
    setup_slime_dg(rpg);
}

void draw_slime(rpg_t *rpg)
{
    for (int i = 0; i <= 8; i++) {
        if (rpg->slime[i]->life > 0)
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->slime[i]->slime, NULL);
    }
}

static void anim_slime_split(rpg_t *rpg, int i)
{
    if (rpg->slime[i]->slime_Rect.left < 3520) {
        rpg->slime[i]->slime_Rect.left += 320;
    } else {
        rpg->slime[i]->slime_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->slime[i]->slime,
    rpg->slime[i]->slime_Rect);
    sfClock_restart(rpg->anim_monst->clock_slime);
}

void anim_slime(rpg_t *rpg)
{
    for (int i = 0; rpg->slime[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_slime > 0.1) {
            anim_slime_split(rpg, i);
        }
    }
}
