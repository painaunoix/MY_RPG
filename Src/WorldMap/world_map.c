/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//draw world map
void draw_map(rpg_t *rpg)
{
    move_view(rpg);
    sfRenderWindow_setView(rpg->win->window, rpg->player->view);
    rpg->win->mouse = sfRenderWindow_mapPixelToCoords(rpg->win->window,
    sfMouse_getPositionRenderWindow(rpg->win->window),
    sfRenderWindow_getView(rpg->win->window));
    rpg->win->center = sfView_getCenter(rpg->player->view);
    if (rpg->dg->in_dungeon == 0)
        sfRenderWindow_drawSprite(rpg->win->window, rpg->w_map->map, NULL);
}
