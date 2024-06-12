/*
** EPITECH PROJECT, 2024
** health.c
** File description:
** health
*/

#include "../../Include/my.h"

//draw the heart of the player
void draw_health(rpg_t *rpg)
{
    for (int i = 0; i != rpg->health->total_pv; i++) {
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->health->pv_tab[i], NULL);
    }
}

//set pos of every heart
void set_health(rpg_t *rpg)
{
    sfVector2f pos = rpg->win->center;

    pos.y -= 440;
    pos.x -= 850;
    for (int i = 0; i != rpg->health->total_pv; i++) {
        if (i == 5) {
            pos.y += 50;
            pos.x = rpg->win->center.x - 850;
        }
        sfRectangleShape_setPosition(rpg->health->pv_tab[i], pos);
        pos.x += 50;
    }
    for (int i = 0; i != rpg->health->total_pv; i++)
        sfRectangleShape_setTexture(rpg->health->pv_tab[i],
        rpg->health->pv_empty, sfTrue);
    for (int i = 0; i != rpg->health->pv; i++)
        sfRectangleShape_setTexture(rpg->health->pv_tab[i],
        rpg->health->pv_fill, sfTrue);
    draw_health(rpg);
}
