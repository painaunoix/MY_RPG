/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//init all struct
void init_loading(rpg_t *rpg)
{
    init_window(rpg);
    init_load(rpg);
    game_loop(rpg);
}
