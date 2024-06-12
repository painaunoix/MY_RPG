/*
** EPITECH PROJECT, 2024
** cadre.c
** File description:
** cadre
*/

#include "../../Include/my.h"

//draw frame
void draw_cadre(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->cadre->cadre, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->cadre->cadre2, NULL);
    if (rpg->cadre->item != NULL)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->cadre->item, NULL);
    if (rpg->cadre->item2 != NULL)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->cadre->item2, NULL);
}

//set the position of the frame
void set_cadre(rpg_t *rpg)
{
    sfVector2f pos = rpg->win->center;
    sfVector2f pos_2 = rpg->win->center;
    sfVector2f pos_it1 = rpg->win->center;
    sfVector2f pos_it2 = rpg->win->center;

    pos.y -= 430;
    pos.x += 740;
    pos_2.y -= 430;
    pos_2.x += 640;
    pos_it1.y -= 415;
    pos_it1.x += 655;
    pos_it2.y -= 415;
    pos_it2.x += 755;
    sfRectangleShape_setPosition(rpg->cadre->cadre, pos);
    sfRectangleShape_setPosition(rpg->cadre->cadre2, pos_2);
    if (rpg->cadre->item != NULL)
        sfRectangleShape_setPosition(rpg->cadre->item, pos_it1);
    if (rpg->cadre->item2 != NULL)
        sfRectangleShape_setPosition(rpg->cadre->item2, pos_it2);
    draw_cadre(rpg);
}
