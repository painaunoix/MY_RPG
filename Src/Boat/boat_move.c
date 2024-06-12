/*
** EPITECH PROJECT, 2024
** boat_move.c
** File description:
** movement for boat
*/

#include "../../Include/my.h"

//change sprite axis
void change_to_boat(rpg_t *rpg)
{
    if (rpg->boat->in_boat == 1) {
        if (rpg->player->player_axe == 4)
            sfSprite_setTexture(rpg->player->player, rpg->boat->boat_left,
            sfTrue);
        if (rpg->player->player_axe == 2)
            sfSprite_setTexture(rpg->player->player,
            rpg->boat->boat_right, sfTrue);
    }
}

//change sprite of player for swap beteew boat and without
void change_boat(rpg_t *rpg)
{
    return;
}
