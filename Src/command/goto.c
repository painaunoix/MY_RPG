/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** goto
*/

#include "../../Include/my.h"

//commade for teleport player to place
void goto_com(rpg_t *rpg, char **arr)
{
    if (arr[1] == NULL)
        return;
    if (my_strcmp("dg_des", arr[1]) == 0)
        sfSprite_setPosition(rpg->player->player, (sfVector2f) {10478, 8580});
    if (my_strcmp("dg_for", arr[1]) == 0)
        sfSprite_setPosition(rpg->player->player, (sfVector2f) {5407, 5351});
    if (my_strcmp("dg_mta", arr[1]) == 0)
        sfSprite_setPosition(rpg->player->player, (sfVector2f) {2119, 4682});
    if (my_strcmp("dg_wat", arr[1]) == 0)
        sfSprite_setPosition(rpg->player->player, (sfVector2f) {7550, 7440});
    if (my_strcmp("dg_ice", arr[1]) == 0)
        sfSprite_setPosition(rpg->player->player, (sfVector2f) {5039, 2332});
}
