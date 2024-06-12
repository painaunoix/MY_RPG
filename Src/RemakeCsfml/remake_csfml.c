/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

sfText *create_texte(int size, sfVector2f position, sfColor color, char *str)
{
    sfText *text = sfText_create();

    sfText_setCharacterSize(text, size);
    sfText_setFont(text, sfFont_createFromFile(MENU_FONT));
    sfText_setPosition(text, position);
    sfText_setString(text, str);
    sfText_setColor(text, color);
    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 15);
    return text;
}

//check if a text is click
void hover_text(rpg_t *rpg, sfColor base, sfColor hover, sfText *text)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect play_rect = sfText_getGlobalBounds(text);

    if (sfFloatRect_contains(&play_rect, mouse.x, mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            rpg->game_state = 1;
            sfText_setFillColor(text, sfRed);
        } else {
            sfText_setFillColor(text, hover);
        }
    } else {
        sfText_setFillColor(text, base);
    }
}

sfIntRect make_rect(int height, int widht)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = widht;
    rect.left = 0;
    rect.top = 0;
    return rect;
}

sfVector2f set_pos_mid_rectan(rpg_t *rpg, sfRectangleShape *rec, int y, int x)
{
    sfVector2f mid_pos = rpg->win->center;
    sfFloatRect size = sfRectangleShape_getGlobalBounds(rec);
    sfVector2f pos;

    pos.x = mid_pos.x + x;
    pos.y = mid_pos.y + y;
    return pos;
}
