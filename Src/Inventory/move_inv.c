/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set item found in chest to inv slot
*/

#include "../../Include/my.h"

//swap from map to inventory
void move_from_map(rpg_t *rpg)
{
    rpg->player->player_can_move = sfFalse;
    rpg->inv->open = 1;
    set_middle_inv(rpg);
    set_middle_tab(rpg);
    rpg->map->open = 0;
    return;
}

//swap from inventory to map
void move_from_inventory(rpg_t *rpg)
{
    rpg->player->player_can_move = sfFalse;
    rpg->map->open = 1;
    set_middle_map(rpg);
    rpg->inv->open = 0;
    return;
}

//select window to swap
void move_inventory(rpg_t *rpg)
{
    if ((rpg->win->event.key.code == sfKeyLeft || rpg->win->event.key.code ==
    sfKeyRight) &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->map->open == 1) {
        move_from_map(rpg);
        return;
    }
    if ((rpg->win->event.key.code == sfKeyLeft || rpg->win->event.key.code ==
    sfKeyRight) &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->inv->open == 1) {
        move_from_inventory(rpg);
        return;
    }
}
