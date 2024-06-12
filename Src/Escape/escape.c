/*
** EPITECH PROJECT, 2024
** menu escape
** File description:
** escape
*/

#include "../../Include/my.h"

//init text for escape menu
sfText *create_texte_esc(sfVector2f size, sfVector2f position, sfColor color,
    char *str)
{
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, size.x);
    sfText_setFont(text, sfFont_createFromFile(FONT_ESCAPE));
    sfText_setPosition(text, position);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    sfText_setStyle(text, sfTextBold);
    sfText_setCharacterSize(text, size.y);
    return text;
}

//draw all in escape menu
void draw_esacpe(rpg_t *rpg)
{
    hover_quit_esc(rpg, sfWhite, rpg->esc->quit_r);
    hover_inv_esc(rpg, sfWhite, rpg->esc->inv_r);
    hover_cross(rpg, sfWhite, rpg->esc->cross_r);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->esc->back, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->esc->cross_r, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->esc->inv_r, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->esc->quit_r, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->esc->set_r, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->esc->inv_txt, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->esc->opt_txt, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->esc->quit_txt, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->esc->set_txt, NULL);
}

//set position of all rectangle in escape menu
void set_pos_esc(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->esc->back,
        set_pos_mid_sprite(rpg, rpg->esc->back, 250));
    sfRectangleShape_setPosition(rpg->esc->cross_r,
        set_pos_mid_rec(rpg, rpg->esc->cross_r, 275, 220));
    sfRectangleShape_setPosition(rpg->esc->inv_r,
        set_pos_mid_rec(rpg, rpg->esc->inv_r, 400, 0));
    sfRectangleShape_setPosition(rpg->esc->quit_r,
        set_pos_mid_rec(rpg, rpg->esc->quit_r, 640, 0));
    sfRectangleShape_setPosition(rpg->esc->set_r,
        set_pos_mid_rec(rpg, rpg->esc->set_r, 520, 0));
    sfText_setPosition(rpg->esc->inv_txt,
        set_pos_mid_txt(rpg, rpg->esc->inv_txt, 415, 0));
    sfText_setPosition(rpg->esc->opt_txt,
        set_pos_mid_txt(rpg, rpg->esc->opt_txt, 280, 0));
    sfText_setPosition(rpg->esc->quit_txt,
        set_pos_mid_txt(rpg, rpg->esc->quit_txt, 655, 0));
    sfText_setPosition(rpg->esc->set_txt,
        set_pos_mid_txt(rpg, rpg->esc->set_txt, 535, 0));
}
