/*
** EPITECH PROJECT, 2024
** map.c
** File description:
** map
*/

#include "../../Include/my.h"

//draw mini map frame
void draw_map_cadre(rpg_t *rpg)
{
    rpg->inv->open = 0;
    rpg->qts->open = 0;
    rpg->esc->esc_check = 0;
    rpg->set->open = 0;
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->map->bck, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->map->title, NULL);
}

//draw mini map
void draw_minimap(rpg_t *rpg)
{
    sfView_setCenter(rpg->map->view, rpg->win->center);
    sfRenderWindow_setView(rpg->win->window, rpg->map->view);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->w_map->map, NULL);
    sfView_setViewport(rpg->map->view, (sfFloatRect)
    {0.191f, 0.255f, 0.618f, 0.635f});
    sfRenderWindow_drawSprite(rpg->win->window, rpg->map->head, NULL);
}

void draw_top_map(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->w_map->m_top, NULL);
}

//set pos of player head on mini map
void set_middle_map(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->map->bck,
    set_pos_mid_rec(rpg, rpg->map->bck, 200, 0));
    sfText_setPosition(rpg->map->title,
    set_pos_mid_txt(rpg, rpg->map->title, 215, 0));
    sfSprite_setPosition(rpg->map->head, rpg->win->center);
}
