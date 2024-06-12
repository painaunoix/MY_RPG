/*
** EPITECH PROJECT, 2024
** cursor.c
** File description:
** cursor
*/

#include "../../Include/my.h"

//check if a menu is open and dispaly cursor or not
void not_dsiplay_cursor(rpg_t *rpg)
{
    if (rpg->esc->esc_check == 1 || rpg->inv->open == 1 ||
    rpg->set->open == 1 || rpg->trader->open == 1 || rpg->qts->open == 1 ||
    rpg->die->die == sfTrue || rpg->game_state == 0) {
        sfSprite_setPosition(rpg->cursor->curs, (sfVector2f)
        {rpg->win->mouse.x - 5, rpg->win->mouse.y - 3});
        sfRenderWindow_drawSprite(rpg->win->window, rpg->cursor->curs, NULL);
    } else
        sfRenderWindow_setMouseCursorVisible(rpg->win->window, sfFalse);
}

void not_dsiplay_cursor_menu(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);

    if (rpg->game_state == 0) {
        sfSprite_setPosition(rpg->cursor->curs, (sfVector2f)
        {mouse.x - 5, mouse.y - 3});
        sfRenderWindow_drawSprite(rpg->win->window, rpg->cursor->curs, NULL);
    }
    sfRenderWindow_setMouseCursorVisible(rpg->win->window, sfFalse);
}
