/*
** EPITECH PROJECT, 2024
** golem.c
** File description:
** golem
*/

#include "../../../Include/my.h"

static void set_texture_golem(rpg_t *rpg, int i)
{
    rpg->golem[i]->golem_tx = sfTexture_createFromFile(GOLEM_LEFT, NULL);
    rpg->golem[i]->golem_right = sfTexture_createFromFile(GOLEM_RIGHT, NULL);
    rpg->golem[i]->golem_l_red = sfTexture_createFromFile(GOLEM_RIGHT_R, NULL);
    rpg->golem[i]->golem_r_red =
    sfTexture_createFromFile(GOLEM_LEFT_R, NULL);
}

sfSprite *create_golem(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {0.4, 0.4};
    sfVector2f center = {x, y};
    sfVector2f center2 = {220, 240};
    sfSprite *sprite;

    rpg->golem[i]->golem_Rect = make_rect(525, 850);
    rpg->golem[i]->life = 10;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    set_texture_golem(rpg, i);
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(GOLEM_LEFT, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->golem[i]->golem_Rect);
    rpg->golem[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->golem[i]->zone, center2);
    sfCircleShape_setPosition(rpg->golem[i]->zone, center);
    sfCircleShape_setRadius(rpg->golem[i]->zone, 400);
    sfCircleShape_setFillColor(rpg->golem[i]->zone, sfTransparent);
    return sprite;
}

void start_create_golem(rpg_t *rpg, int x, int y, int i)
{
    rpg->golem[i] = malloc(sizeof(golem_t));
    rpg->golem[i]->golem = create_golem(rpg, x, y, i);
    rpg->golem[i]->seconds = 0;
    rpg->golem[i + 1] = NULL;
}

void setup_golem(rpg_t *rpg)
{
    rpg->golem = malloc(sizeof(golem_t *) * 10);
    start_create_golem(rpg, 3595, 3248, 0);
    start_create_golem(rpg, 4550, 3528, 1);
    start_create_golem(rpg, 5288, 2774, 2);
    start_create_golem(rpg, 3728, 2451, 3);
    start_create_golem(rpg, 6146, 2197, 4);
    start_create_golem(rpg, 5013, 1978, 5);
    start_create_golem(rpg, 3943, 1773, 6);
    start_create_golem(rpg, 3814, 3870, 7);
    start_create_golem(rpg, 3814, 4319, 8);
}

void draw_golem(rpg_t *rpg)
{
    for (int i = 0; i <= 6; i++) {
        if (rpg->golem[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->golem[i]->golem, NULL);
        }
    }
}

static void anim_golem_split(rpg_t *rpg, int i)
{
    if (rpg->golem[i]->golem_Rect.left < 5100 - 850) {
        rpg->golem[i]->golem_Rect.left += 850;
    } else {
        rpg->golem[i]->golem_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->golem[i]->golem,
    rpg->golem[i]->golem_Rect);
    sfClock_restart(rpg->anim_monst->clock_golem);
}

void anim_golem(rpg_t *rpg)
{
    for (int i = 0; rpg->golem[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_golem > 0.2) {
            anim_golem_split(rpg, i);
        }
    }
}
