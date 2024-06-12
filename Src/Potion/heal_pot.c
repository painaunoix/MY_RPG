/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** heal potion
*/

#include "../../Include/my.h"

void is_pot_use(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->health->heal_pot);
    float second = sfTime_asSeconds(time);

    if (rpg->win->event.key.code == sfKeySpace && is_in_frame(rpg, POTION) == 0
    && rpg->win->event.type == sfEvtKeyReleased && second > 90) {
        rpg->health->pv += 2;
        sfClock_restart(rpg->health->heal_pot);
    }
}
