/*
** EPITECH PROJECT, 2024
** inventory.c
** File description:
** inventoryy
*/

#include "../../Include/my.h"

//draw all text on inventory menu
void draw_inventory(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->inv->bck, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->title, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->healt, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->mana, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->armor, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->strenght, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->luck, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->inv->speed, NULL);
    for (int i = 0; i != 6; i++) {
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->inv->skills[i], NULL);
    }
    draw_slot(rpg);
}

//set position of up button in inventiry menu
void set_button_upgrade(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->inv->skills[0],
    set_pos_mid_rec(rpg, rpg->inv->skills[0], 694, -32.5));
    sfRectangleShape_setPosition(rpg->inv->skills[1],
    set_pos_mid_rec(rpg, rpg->inv->skills[1], 760, -32.5));
    sfRectangleShape_setPosition(rpg->inv->skills[2],
    set_pos_mid_rec(rpg, rpg->inv->skills[2], 822, -32.5));
    sfRectangleShape_setPosition(rpg->inv->skills[3],
    set_pos_mid_rec(rpg, rpg->inv->skills[3], 696, 371));
    sfRectangleShape_setPosition(rpg->inv->skills[4],
    set_pos_mid_rec(rpg, rpg->inv->skills[4], 760, 370.5));
    sfRectangleShape_setPosition(rpg->inv->skills[5],
    set_pos_mid_rec(rpg, rpg->inv->skills[5], 822, 370.5));
}

//set position in inventiry menu
void set_middle_inv(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->inv->bck,
    set_pos_mid_rec(rpg, rpg->inv->bck, 200, 0));
    sfText_setPosition(rpg->inv->title,
    set_pos_mid_txt(rpg, rpg->inv->title, 215, 0));
    sfText_setPosition(rpg->inv->healt,
    set_pos_mid_txt(rpg, rpg->inv->healt, 345, -340));
    sfText_setPosition(rpg->inv->mana,
    set_pos_mid_txt(rpg, rpg->inv->mana, 400, -350));
    sfText_setPosition(rpg->inv->armor,
    set_pos_mid_txt(rpg, rpg->inv->armor, 455, -338));
    sfText_setPosition(rpg->inv->strenght,
    set_pos_mid_txt(rpg, rpg->inv->strenght, 510, -315));
    sfText_setPosition(rpg->inv->luck,
    set_pos_mid_txt(rpg, rpg->inv->luck, 565, -350));
    sfText_setPosition(rpg->inv->speed,
    set_pos_mid_txt(rpg, rpg->inv->speed, 620, -338));
    set_button_upgrade(rpg);
    set_pos_inv_slot(rpg);
}
