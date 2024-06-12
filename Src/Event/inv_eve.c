/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** inv eve
*/

#include "../../Include/my.h"

//open inventory menu
void open_inv(rpg_t *rpg)
{
    rpg->player->player_can_move = sfFalse;
    rpg->qts->open = 0;
    rpg->map->open = 0;
    rpg->inv->open = 1;
    set_middle_inv(rpg);
    set_middle_tab(rpg);
}

//close inventory menu
void close_inv(rpg_t *rpg)
{
    rpg->inv->move_sp = -1;
    rpg->inv->open = 0;
    rpg->player->player_can_move = sfTrue;
}

//hanlde inventory menu
void check_inv(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeyI &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->esc->esc_check == 0
    && rpg->inv->open == 0 && rpg->qts->open == 0 &&
    rpg->map->open == 0 && rpg->set->open == 0
    && rpg->com->wait_in == sfFalse) {
        open_inv(rpg);
        return;
    }
    if (rpg->win->event.key.code == sfKeyI &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->inv->open == 1)
        close_inv(rpg);
    if (rpg->inv->open == 1) {
        hover_all_skills(rpg);
    }
}
