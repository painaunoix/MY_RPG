/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** inv eve
*/

#include "../../Include/my.h"

//open escape menu
void open_esc(rpg_t *rpg)
{
    rpg->esc->esc_check = 1;
    set_end_in(rpg);
    set_pos_esc(rpg);
    rpg->map->open = 0;
    rpg->qts->open = 0;
    rpg->inv->open = 0;
    rpg->player->player_can_move = sfFalse;
}

//close escape menu
void close_esc(rpg_t *rpg)
{
    rpg->esc->esc_check = 0;
    rpg->map->open = 0;
    rpg->inv->open = 0;
    rpg->qts->open = 0;
    rpg->trader->open = 0;
    rpg->set->open = 0;
    rpg->inv->move_sp = -1;
    rpg->player->player_can_move = sfTrue;
}

//hnadle escape menu
void check_esc(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeyEscape && rpg->inv->open == 0 &&
    rpg->map->open == 0 && rpg->qts->open == 0 && rpg->esc->esc_check == 0 &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->set->open != 1 &&
    rpg->trader->open != 1) {
        open_esc(rpg);
        return;
    }
    if (rpg->win->event.key.code == sfKeyEscape &&
    rpg->win->event.type == sfEvtKeyReleased)
        close_esc(rpg);
}
