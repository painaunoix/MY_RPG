/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make speed gem
*/

#include "../../Include/my.h"

int is_time_speed(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->speed);
    float second = sfTime_asSeconds(time);

    if (second > 10) {
        sfClock_restart(rpg->gem->speed);
        rpg->gem->act_spd = sfFalse;
        rpg->player->player_speed = rpg->gem->old_spd;
    }
}

void is_speed_gem_use(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->speed);
    float second = sfTime_asSeconds(time);

    if (rpg->win->event.key.code == sfKeySpace &&
    rpg->win->event.type == sfEvtKeyPressed && rpg->com->wait_in == sfFalse &&
    is_in_frame(rpg, ITM_SPEED) == 0 && rpg->gem->act_spd == sfFalse
    && second > 5) {
        sfClock_restart(rpg->gem->speed);
        rpg->gem->act_spd = sfTrue;
        rpg->gem->old_spd = rpg->player->player_speed;
        rpg->player->player_speed += 5;
        adapte_mana(rpg);
    }
    if (rpg->gem->act_spd == sfTrue)
        is_time_speed(rpg);
}
