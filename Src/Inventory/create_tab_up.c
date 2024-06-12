/*
** EPITECH PROJECT, 2024
** create_tab_up.c
** File description:
** create_tab_up
*/

#include "../../Include/my.h"

//malloc array of Rectangle
sfRectangleShape **fill_tab_up(sfRectangleShape **tab)
{
    tab = malloc(sizeof(sfRectangleShape *) * 6);
    for (int i = 0; i != 6; i++) {
        tab[i] = create_rectangle_shape((sfVector2f) {33, 35},
        (sfVector2f) {0, 0}, BOX);
    }
    return tab;
}

//set pos at the middle of every talents
void set_middle_tab(rpg_t *rpg)
{
    set_tab_rec_mid(rpg->skill->tab_up[0],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[0][0], 700, -299));
    set_tab_rec_mid(rpg->skill->tab_up[1],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[1][0], 765, -299));
    set_tab_rec_mid(rpg->skill->tab_up[2],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[2][0], 828, -299));
    set_tab_rec_mid(rpg->skill->tab_up[3],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[3][0], 703, 105));
    set_tab_rec_mid(rpg->skill->tab_up[4],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[4][0], 765, 105));
    set_tab_rec_mid(rpg->skill->tab_up[5],
    set_pos_mid_rec(rpg, rpg->skill->tab_up[5][0], 828, 105));
    sfText_setPosition(rpg->skill->skill_txt, set_pos_mid_txt(rpg,
    rpg->skill->skill_txt, 650, -20));
    sfText_setPosition(rpg->skill->nb_point, set_pos_mid_txt(rpg,
    rpg->skill->nb_point, 650, 115));
}

//draw skill point
static void draw_skill_point(rpg_t *rpg)
{
    sfText_setString(rpg->skill->nb_point, my_itos(rpg->skill->point));
    sfRenderWindow_drawText(rpg->win->window, rpg->skill->nb_point, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->skill->skill_txt, NULL);
}

//draw skill up
void draw_skill_up(rpg_t *rpg)
{
    draw_skill_point(rpg);
    for (int y = 0; y != rpg->skill->health; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[0][y], NULL);
    for (int y = 0; y != rpg->skill->mana; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[1][y], NULL);
    for (int y = 0; y != rpg->skill->armor; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[2][y], NULL);
    for (int y = 0; y != rpg->skill->strenght; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[3][y], NULL);
    for (int y = 0; y != rpg->skill->luck; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[4][y], NULL);
    for (int y = 0; y != rpg->skill->speed; y++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->skill->tab_up[5][y], NULL);
}
