/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make stg gem
*/

#include "../../Include/my.h"

int is_time_stg(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->stg);
    float second = sfTime_asSeconds(time);

    if (second > 10) {
        sfClock_restart(rpg->gem->stg);
        rpg->gem->act_stg = sfFalse;
        rpg->player->atk = rpg->gem->old_stg;
    }
}

void is_stg_gem_use(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->stg);
    float second = sfTime_asSeconds(time);

    if (rpg->win->event.key.code == sfKeySpace &&
    rpg->win->event.type == sfEvtKeyPressed && rpg->com->wait_in == sfFalse &&
    is_in_frame(rpg, ITM_STRENGHT) == 0 && rpg->gem->act_stg == sfFalse
    && second > 5) {
        sfClock_restart(rpg->gem->stg);
        rpg->gem->act_stg = sfTrue;
        rpg->gem->old_stg = rpg->player->atk;
        rpg->player->atk += 5;
        adapte_mana(rpg);
    }
    if (rpg->gem->act_stg == sfTrue)
        is_time_stg(rpg);
}
