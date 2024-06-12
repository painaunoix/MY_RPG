/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set
*/

#include "../../Include/my.h"

//check if coli is on and don't allow speed greater than 20 when coli is on
void check_coli(rpg_t *rpg, int nb)
{
    if (rpg->debug->coli == sfTrue && (nb > 20 || nb < 0))
        return;
    rpg->player->player_speed = nb;
}

//command set for set variable
void set_var(rpg_t *rpg, char **arr)
{
    if (arr[1] == NULL || arr[2] == NULL)
        return;
    if (my_strcmp("atk", arr[1]) == 0)
        rpg->player->atk = my_getnbr(arr[2]);
    if (my_strcmp("co", arr[1]) == 0)
        rpg->coin->coin = my_getnbr(arr[2]);
    if (my_strcmp("speed", arr[1]) == 0)
        check_coli(rpg, my_getnbr(arr[2]));
    if (my_strcmp("po", arr[1]) == 0)
        rpg->skill->point = my_getnbr(arr[2]);
}
