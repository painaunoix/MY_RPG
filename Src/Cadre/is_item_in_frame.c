/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** check if item is in frame
*/

#include "../../Include/my.h"

//check if the str is an item in the frame
int is_in_frame(rpg_t *rpg, char *str)
{
    if (my_strcmp(str, rpg->cadre->itm1) == 0)
        return (0);
    if (my_strcmp(str, rpg->cadre->itm2) == 0)
        return (0);
    return (-1);
}
