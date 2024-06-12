/*
** EPITECH PROJECT, 2024
** init boat
** File description:
** file for init struct boat
*/

#include "../../Include/my.h"

//init struct boat
void init_boat(rpg_t *rpg)
{
    rpg->boat = malloc(sizeof(boat_t));
    rpg->boat->in_boat = 0;
    rpg->boat->boat_left = texture(PLAYER_BOAT_LEFT);
    rpg->boat->boat_right = texture(PLAYER_BOAT_RIGHT);
    rpg->boat->img = sfImage_createFromFile(WATER);
    rpg->boat->dg = sfImage_createFromFile(RED_WA);
}
