/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//draw Menu
void draw_menu(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->menu->fond, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->menu->Title, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->menu->Play, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->menu->Continue, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->menu->Setting, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->menu->Quit, NULL);
}

//draw animation in background in the menu
int animation_menu(rpg_t *rpg)
{
    if (rpg->menu->fond_rect.left < 13248) {
        rpg->menu->fond_rect.left += 576;
    } else {
        rpg->menu->fond_rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->menu->fond, rpg->menu->fond_rect);
}
