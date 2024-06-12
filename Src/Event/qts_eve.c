/*
** EPITECH PROJECT, 2024
** quests.c
** File description:
** quests eve
*/

#include "../../Include/my.h"

//open quests menu
void open_quests(rpg_t *rpg)
{
    rpg->player->player_can_move = sfFalse;
    rpg->inv->open = 0;
    rpg->map->open = 0;
    rpg->qts->open = 1;
    set_middle_qts(rpg);
}

//close quests menu
void close_quests(rpg_t *rpg)
{
    rpg->qts->open = 0;
    rpg->player->player_can_move = sfTrue;
}

//handle quests menu
void check_quests(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeyP &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->qts->open == 0
    && rpg->game_state == 1 && rpg->map->open == 0 &&
    rpg->esc->esc_check == 0 && rpg->inv->open == 0 &&
    rpg->set->open == 0 && rpg->com->wait_in == sfFalse) {
        open_quests(rpg);
        return;
    }
    if (rpg->win->event.key.code == sfKeyP &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->qts->open == 1)
        close_quests(rpg);
}
