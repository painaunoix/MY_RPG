/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** coli
*/

#include "../../Include/my.h"

//change coli status and set speed to 20 when coli is on
void change_coli(rpg_t *rpg)
{
    rpg->debug->coli = !rpg->debug->coli;
    if (rpg->debug->coli == sfTrue)
        rpg->player->player_speed = 20;
}
