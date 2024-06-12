/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** is com
*/

#include "../../Include/my.h"

void is_com_2(rpg_t *rpg, char **arr)
{
    if (my_strcmp(arr[0], "pos") == 0)
        pos_player(rpg);
    if (my_strcmp(arr[0], "god") == 0) {
        rpg->debug->die = !rpg->debug->die;
        change_coli(rpg);
    }
    if (my_strcmp(arr[0], "tuto") == 0)
        rpg->tuto->step = 6;
}

//check witch command is enter by user
void is_com(rpg_t *rpg)
{
    char **arr = my_str_to_word_array(rpg->com->input);

    if (my_strcmp(arr[0], "get") == 0)
        get_itm(rpg, arr);
    if (my_strcmp(arr[0], "goto") == 0)
        goto_com(rpg, arr);
    if (my_strcmp(rpg->com->input, "draw red") == 0)
        rpg->debug->disp = !rpg->debug->disp;
    if (my_strcmp(arr[0], "coli") == 0)
        change_coli(rpg);
    if (my_strcmp(arr[0], "set") == 0)
        set_var(rpg, arr);
    if (my_strcmp(arr[0], "heal") == 0)
        rpg->health->pv = rpg->health->total_pv;
    is_com_2(rpg, arr);
}
