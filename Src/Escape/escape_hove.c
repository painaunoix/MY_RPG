/*
** EPITECH PROJECT, 2024
** menu escape
** File description:
** escape
*/

#include "../../Include/my.h"

//check if the player is hover settings button and change style
void hover_set_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            rpg->set->open = 1;
            rpg->esc->esc_check = 0;
            set_pos_set(rpg);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if the player is hover inventory button and change style
void hover_inv_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            rpg->player->player_can_move = sfFalse;
            rpg->esc->esc_check = 0;
            rpg->inv->open = 1;
            set_middle_inv(rpg);
            set_middle_tab(rpg);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if the player is hover quit button and change style
void hover_quit_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            sfRenderWindow_close(rpg->win->window);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if the player is hover cross button and change style
void hover_cross(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            rpg->esc->esc_check = 0;
            rpg->player->player_can_move = sfTrue;
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}
