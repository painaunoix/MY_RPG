/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** pos
*/

#include "../../Include/my.h"

//command pos print the position of the player
void pos_player(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->player);

    printf("x = %f y = %f\n", pos.x, pos.y);
}
