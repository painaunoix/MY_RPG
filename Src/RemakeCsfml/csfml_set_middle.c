/*
** EPITECH PROJECT, 2024
** set pos middle
** File description:
** mid
*/

#include "../../Include/my.h"

//set postion of sprite in the middle of the window with offset x
sfVector2f set_pos_mid_sprite_off(rpg_t *rpg, sfSprite *sprite, int y, int x)
{
    sfVector2f mid_pos = rpg->win->center;
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);
    sfVector2f pos;

    pos.x = mid_pos.x - size.width / 2 + x;
    pos.y = mid_pos.y - 540 + y;
    return pos;
}

//set postion of sprite in the middle of the window
sfVector2f set_pos_mid_sprite(rpg_t *rpg, sfSprite *sprite, int y)
{
    sfVector2f mid_pos = rpg->win->center;
    sfFloatRect size = sfSprite_getGlobalBounds(sprite);
    sfVector2f pos;

    pos.x = mid_pos.x - size.width / 2;
    pos.y = mid_pos.y - 540 + y;
    return pos;
}

//set postion of text in the middle of the window
sfVector2f set_pos_mid_txt(rpg_t *rpg, sfText *text, int y, int x)
{
    sfVector2f mid_pos = rpg->win->center;
    sfFloatRect size = sfText_getGlobalBounds(text);
    sfVector2f pos;

    pos.x = mid_pos.x - size.width / 2 + x;
    pos.y = mid_pos.y - 540 + y;
    return pos;
}

//set postion of rectangle in the middle of the window
sfVector2f set_pos_mid_rec(rpg_t *rpg, sfRectangleShape *rec, int y, int x)
{
    sfVector2f mid_pos = rpg->win->center;
    sfFloatRect size = sfRectangleShape_getGlobalBounds(rec);
    sfVector2f pos;

    pos.x = mid_pos.x - size.width / 2 + x;
    pos.y = mid_pos.y - 540 + y;
    return pos;
}

//set postion of array of rectangle in the middle of the window
void set_tab_rec_mid(sfRectangleShape **tab, sfVector2f pos)
{
    for (int i = 0; i != 6; i++) {
        sfRectangleShape_setPosition(tab[i], pos);
        pos.x += 40.2;
    }
}
