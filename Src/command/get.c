/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get
*/

#include "../../Include/my.h"

//commande get item
void get_itm(rpg_t *rpg, char **arr)
{
    if (arr[1] == NULL)
        return;
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("armor", arr[1]) == 0)
        set_tex_sl(rpg, ITM_ARMOR);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("axe", arr[1]) == 0)
        set_tex_sl(rpg, ITM_AXE);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("duck", arr[1]) == 0)
        set_tex_sl(rpg, ITM_DUCK);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("hook", arr[1]) == 0)
        set_tex_sl(rpg, ITM_HOOK);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("speed", arr[1]) == 0)
        set_tex_sl(rpg, ITM_SPEED);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("stg", arr[1]) == 0)
        set_tex_sl(rpg, ITM_STRENGHT);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("bm", arr[1]) == 0)
        set_tex_sl(rpg, ITM_BOMB);
    if (my_strcmp("all", arr[1]) == 0 || my_strcmp("lan", arr[1]) == 0)
        set_tex_sl(rpg, ITM_TORCH);
}
