/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** screen die
*/

#include "../../Include/my.h"

void init_die(rpg_t *rpg)
{
    rpg->die = malloc(sizeof(die_t));
    rpg->die->msg = create_texte_esc((sfVector2f) {100, 100},
    (sfVector2f) {0, 0}, sfBlack, "You Die");
    rpg->die->restart = create_texte_esc((sfVector2f) {100, 100},
    (sfVector2f) {0, 0}, sfBlack, "Restart");
    rpg->die->die = sfFalse;
    rpg->die->screen = create_rectangle((sfVector2f) {1920, 1080},
    (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(rpg->die->screen,
    sfColor_fromRGBA(255, 0, 0, 100));
    sfRectangleShape_setOutlineColor(rpg->die->screen, sfTransparent);
}

int screen_die(rpg_t *rpg)
{
    sfText_setPosition(rpg->die->restart, set_pos_mid_txt(rpg,
    rpg->die->restart, 500, 0));
    sfText_setPosition(rpg->die->msg, set_pos_mid_txt(rpg, rpg->die->msg,
    200, 0));
    sfRectangleShape_setPosition(rpg->die->screen,
    set_pos_mid_txt(rpg, rpg->die->msg, 0, -700));
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->die->screen,
    NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->die->msg, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->die->restart, NULL);
    return (0);
}
