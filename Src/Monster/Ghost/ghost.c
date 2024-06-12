/*
** EPITECH PROJECT, 2024
** ghost.c
** File description:
** ghost
*/

#include "../../../Include/my.h"

static void set_texture_ghost(rpg_t *rpg, int i)
{
    rpg->ghost[i]->ghost_tx = sfTexture_createFromFile(GHOST_LEFT, NULL);
    rpg->ghost[i]->ghost_right = sfTexture_createFromFile(GHOST_RIGHT, NULL);
    rpg->ghost[i]->ghost_l_red = sfTexture_createFromFile(GHOST_LEFT_R, NULL);
    rpg->ghost[i]->ghost_r_red =
    sfTexture_createFromFile(GHOST_RIGHT_R, NULL);
}

sfSprite *create_ghost(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {3.5, 3.5};
    sfVector2f center = {x, y};
    sfVector2f center2 = {170, 170};
    sfSprite *sprite;

    rpg->ghost[i]->ghost_Rect = make_rect(32, 32);
    rpg->ghost[i]->life = 5;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    set_texture_ghost(rpg, i);
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(GHOST_LEFT, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->ghost[i]->ghost_Rect);
    rpg->ghost[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->ghost[i]->zone, center2);
    sfCircleShape_setPosition(rpg->ghost[i]->zone, center);
    sfCircleShape_setRadius(rpg->ghost[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->ghost[i]->zone, sfTransparent);
    return sprite;
}

void start_create_ghost(rpg_t *rpg, int x, int y, int i)
{
    rpg->ghost[i] = malloc(sizeof(ghost_t));
    rpg->ghost[i]->ghost = create_ghost(rpg, x, y, i);
    rpg->ghost[i]->seconds = 0;
    rpg->ghost[i + 1] = NULL;
}

static void setup_ghost_wave(rpg_t *rpg)
{
    start_create_ghost(rpg, 3458, 3208, 25);
    start_create_ghost(rpg, 3728, 3208, 26);
    start_create_ghost(rpg, 3728, 2677, 27);
    start_create_ghost(rpg, 3458, 2677, 28);
    start_create_ghost(rpg, 3866, 2800, 29);
    start_create_ghost(rpg, 3866, 3068, 30);
    start_create_ghost(rpg, 3326, 2800, 31);
    start_create_ghost(rpg, 3326, 3068, 32);
}

static void setup_ghost_part2(rpg_t *rpg)
{
    start_create_ghost(rpg, 5238, 5539, 18);
    start_create_ghost(rpg, 5625, 5458, 19);
    start_create_ghost(rpg, 5544, 5137, 20);
    start_create_ghost(rpg, 5463, 4168, 21);
    start_create_ghost(rpg, 5120, 4168, 22);
    start_create_ghost(rpg, 5463, 4040, 23);
    start_create_ghost(rpg, 5120, 4040, 24);
    setup_ghost_wave(rpg);
}

void setup_ghost(rpg_t *rpg)
{
    rpg->ghost = malloc(sizeof(ghost_t *) * 34);
    start_create_ghost(rpg, 2805, 5515, 0);
    start_create_ghost(rpg, 4670, 5925, 1);
    start_create_ghost(rpg, 2093, 5720, 2);
    start_create_ghost(rpg, 3890, 5475, 3);
    start_create_ghost(rpg, 5555, 6040, 4);
    start_create_ghost(rpg, 5355, 5500, 5);
    start_create_ghost(rpg, 2485, 6558, 6);
    start_create_ghost(rpg, 3129, 5991, 7);
    start_create_ghost(rpg, 4441, 5250, 8);
    start_create_ghost(rpg, 3231, 5230, 9);
    start_create_ghost(rpg, 3645, 4867, 10);
    start_create_ghost(rpg, 3930, 5137, 11);
    start_create_ghost(rpg, 4266, 5392, 12);
    start_create_ghost(rpg, 3009, 4759, 13);
    start_create_ghost(rpg, 2457, 4837, 14);
    start_create_ghost(rpg, 2742, 5218, 15);
    start_create_ghost(rpg, 2250, 5359, 16);
    start_create_ghost(rpg, 5091, 5287, 17);
    setup_ghost_part2(rpg);
}

void draw_ghost(rpg_t *rpg)
{
    for (int i = 0; i <= 7; i++) {
        if (rpg->ghost[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->ghost[i]->ghost, NULL);
        }
    }
}

static void anim_ghost_split(rpg_t *rpg, int i)
{
    if (rpg->ghost[i]->ghost_Rect.left < 128 - 32) {
        rpg->ghost[i]->ghost_Rect.left += 32;
    } else {
        rpg->ghost[i]->ghost_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->ghost[i]->ghost,
    rpg->ghost[i]->ghost_Rect);
    sfClock_restart(rpg->anim_monst->clock_ghost);
}

void anim_ghost(rpg_t *rpg)
{
    for (int i = 0; rpg->ghost[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_ghost > 0.2) {
            anim_ghost_split(rpg, i);
        }
    }
}
