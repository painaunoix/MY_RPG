/*
** EPITECH PROJECT, 2024
** init window
** File description:
** file for init struct window
*/

#include "../../Include/my.h"

//create the window
void init_window(rpg_t *rpg)
{
    sfVideoMode size = {1920, 1080, 16};
    char *name = "Arnald's-Story";

    rpg->win = malloc(sizeof(win_t));
    rpg->win->window = sfRenderWindow_create(size, name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->window, 60);
    rpg->win->mouse.x = 0;
    rpg->win->mouse.y = 0;
}
