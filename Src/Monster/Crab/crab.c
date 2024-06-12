/*
** EPITECH PROJECT, 2024
** ghost.c
** File description:
** ghost
*/

#include "../../../Include/my.h"

//set stcuct crab
static void set_init_crab(rpg_t *rpg, int i)
{
    rpg->crab[i]->crab_Rect = make_rect(9, 32);
    rpg->crab[i]->life = 5;
    rpg->crab[i]->change = 0;
    rpg->crab[i]->is_moving = 0;
}

//create crab
static sfSprite *create_crab(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {3, 3};
    sfVector2f center = {x, y};
    sfVector2f center2 = {170, 170};
    sfSprite *sprite;

    set_init_crab(rpg, i);
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    rpg->crab[i]->crab_tx = sfTexture_createFromFile(CRAB, NULL);
    rpg->crab[i]->crab_tx_red = sfTexture_createFromFile(CRAB_RED, NULL);
    sfSprite_setTexture(sprite, rpg->crab[i]->crab_tx, sfTrue);
    sfSprite_setTextureRect(sprite, rpg->crab[i]->crab_Rect);
    rpg->crab[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->crab[i]->zone, center2);
    sfCircleShape_setPosition(rpg->crab[i]->zone, center);
    sfCircleShape_setRadius(rpg->crab[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->crab[i]->zone, sfTransparent);
    return sprite;
}

//create crab
static void start_create_crab(rpg_t *rpg, int x, int y, int i)
{
    rpg->crab[i] = malloc(sizeof(crab_t));
    rpg->crab[i]->crab = create_crab(rpg, x, y, i);
    rpg->crab[i]->seconds = 0;
    rpg->crab[i + 1] = NULL;
}

//create crab
void setup_crab(rpg_t *rpg)
{
    rpg->crab = malloc(sizeof(crab_t *) * 2);
    start_create_crab(rpg, 3650, 9600, 0);
}

//draw crab
void draw_crab(rpg_t *rpg)
{
    for (int i = 0; rpg->crab[i] != NULL; i++) {
        if (rpg->crab[i]->life > 0)
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->crab[i]->crab, NULL);
    }
}

//anim crab
static void anim_crab_split(rpg_t *rpg, int i)
{
    if (rpg->crab[i]->crab_Rect.left < 96) {
        rpg->crab[i]->crab_Rect.left += 32;
    } else {
        rpg->crab[i]->crab_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->crab[i]->crab,
    rpg->crab[i]->crab_Rect);
    sfClock_restart(rpg->anim_monst->clock_crab);
}

//anim crab
void anim_crab(rpg_t *rpg)
{
    for (int i = 0; rpg->crab[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_crab > 0.1) {
            anim_crab_split(rpg, i);
        }
    }
}
