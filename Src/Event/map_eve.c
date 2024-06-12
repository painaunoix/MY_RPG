/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** inv eve
*/

#include "../../Include/my.h"

//open map menu
void open_map(rpg_t *rpg)
{
    rpg->player->player_can_move = sfFalse;
    rpg->esc->esc_check = 0;
    rpg->inv->open = 0;
    rpg->qts->open = 0;
    rpg->map->open = 1;
    set_middle_map(rpg);
}

//close map menu
void close_map(rpg_t *rpg)
{
    rpg->map->open = 0;
    rpg->player->player_can_move = sfTrue;
}

//handle map menu
void check_map(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeyM &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->map->open == 0
    && rpg->esc->esc_check == 0 && rpg->game_state == 1 &&
    rpg->qts->open == 0 && rpg->inv->open == 0 && rpg->set->open == 0
    && rpg->com->wait_in == sfFalse) {
        open_map(rpg);
        return;
    }
    if (rpg->win->event.key.code == sfKeyM &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->map->open == 1)
        close_map(rpg);
}
