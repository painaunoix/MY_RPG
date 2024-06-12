/*
** EPITECH PROJECT, 2024
** quests.c
** File description:
** quests
*/

#include "../../Include/my.h"

void finish_qts(rpg_t *rpg)
{
    if (rpg->qts->snake == 5)
        sfText_setColor(rpg->qts->txSnake, sfGreen);
    if (rpg->qts->slime == 5)
        sfText_setColor(rpg->qts->txSlime, sfGreen);
    if (rpg->qts->dog == 5)
        sfText_setColor(rpg->qts->txDog, sfGreen);
    if (rpg->qts->golem == 5)
        sfText_setColor(rpg->qts->txGolem, sfGreen);
    if (rpg->qts->ghost == 5)
        sfText_setColor(rpg->qts->txGhost, sfGreen);
}

//draw all text on quests menu
void draw_quests(rpg_t *rpg)
{
    finish_qts(rpg);
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->qts->bck, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->title, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->txSnake, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->txSlime, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->txGhost, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->txDog, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->qts->txGolem, NULL);
}

void set_middle2_qts(rpg_t *rpg)
{
    sfText_setString(rpg->qts->txDog,
        my_strcat("Kill 5 Dog in the mountain biome :", my_strcat("  ",
        my_strcat(my_itos(rpg->qts->dog), my_strcat("/", "5")))));
    sfText_setPosition(rpg->qts->txDog,
    set_pos_mid_txt(rpg, rpg->qts->txDog, 600, -130));
    sfText_setString(rpg->qts->txGolem,
        my_strcat("Kill 5 Golem in the snow biome :", my_strcat("  ",
        my_strcat(my_itos(rpg->qts->golem), my_strcat("/", "5")))));
    sfText_setPosition(rpg->qts->txGolem,
    set_pos_mid_txt(rpg, rpg->qts->txGolem, 685, -145));
}

//set position in inventiry menu
void set_middle_qts(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->qts->bck,
    set_pos_mid_rec(rpg, rpg->qts->bck, 200, 0));
    sfText_setPosition(rpg->qts->title,
    set_pos_mid_txt(rpg, rpg->qts->title, 215, 0));
    sfText_setString(rpg->qts->txSlime,
        my_strcat("Kill 5 Slime in the plane biome :", my_strcat("  ",
        my_strcat(my_itos(rpg->qts->slime), my_strcat("/", "5")))));
    sfText_setPosition(rpg->qts->txSlime,
    set_pos_mid_txt(rpg, rpg->qts->txSlime, 345, -150));
    sfText_setString(rpg->qts->txGhost,
        my_strcat("Kill 5 Ghost in the forest biome :", my_strcat("  ",
        my_strcat(my_itos(rpg->qts->ghost), my_strcat("/", "5")))));
    sfText_setPosition(rpg->qts->txGhost,
    set_pos_mid_txt(rpg, rpg->qts->txGhost, 430, -140));
    sfText_setString(rpg->qts->txSnake,
        my_strcat("Kill 5 Snakes in the desert biome :", my_strcat("  ",
        my_strcat(my_itos(rpg->qts->snake), my_strcat("/", "5")))));
    sfText_setPosition(rpg->qts->txSnake,
    set_pos_mid_txt(rpg, rpg->qts->txSnake, 515, -122));
    set_middle2_qts(rpg);
}
