/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//check if player click on play button
void hover_play(rpg_t *rpg, sfColor base, sfColor hover, sfText *text)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect play_rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->game_state = 1;
            rpg->set->open = 0;
            sfMusic_play(rpg->sound[0]->sound);
            rpg->player->player_can_move = sfTrue;
            sfMusic_stop(rpg->menu->song);
            sfText_setFillColor(text, sfRed);
        } else {
            sfText_setFillColor(text, hover);
        }
    } else {
        sfText_setFillColor(text, base);
    }
}

//check if player click on continue button
void hover_continue(rpg_t *rpg, sfColor base, sfColor hover, sfText *text)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect play_rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setFillColor(text, sfRed);
            rpg->game_state = 1;
            rpg->set->open = 0;
            sfMusic_play(rpg->sound[0]->sound);
            rpg->player->player_can_move = sfTrue;
            sfMusic_stop(rpg->menu->song);
            sfText_setFillColor(text, sfRed);
            put_in_stru(rpg);
        } else {
            sfText_setFillColor(text, hover);
        }
    } else {
        sfText_setFillColor(text, base);
    }
}

//check if player click on setting button
void hover_setting(rpg_t *rpg, sfColor base, sfColor hover, sfText *text)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect play_rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setFillColor(text, sfRed);
            rpg->set_open = 1;
        } else {
            sfText_setFillColor(text, hover);
        }
    } else {
        sfText_setFillColor(text, base);
    }
}

//check if player click on quit button
void hover_quit(rpg_t *rpg, sfColor base, sfColor hover, sfText *text)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect play_rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setFillColor(text, sfRed);
            sfRenderWindow_close(rpg->win->window);
        } else {
            sfText_setFillColor(text, hover);
        }
    } else {
        sfText_setFillColor(text, base);
    }
}
