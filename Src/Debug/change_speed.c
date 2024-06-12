/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** change speed
*/

#include "../../Include/my.h"

//change speed of the user by press 2 or 0
void change_speed(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeyNumpad2 &&
    rpg->win->event.type == sfEvtKeyReleased) {
        rpg->player->player_speed ++;
    }
    if (rpg->win->event.key.code == sfKeyNumpad0 &&
    rpg->win->event.type == sfEvtKeyReleased) {
        rpg->player->player_speed --;
    }
}
