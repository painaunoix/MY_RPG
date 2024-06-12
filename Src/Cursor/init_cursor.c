/*
** EPITECH PROJECT, 2024
** init cursor
** File description:
** file for init struct cursor
*/

#include "../../Include/my.h"

//init struct cursor
void init_cursor(rpg_t *rpg)
{
    rpg->cursor = malloc(sizeof(cursor_t));
    rpg->cursor->curs_tex = texture(CURSOR);
    rpg->cursor->curs = sfSprite_create();
    sfSprite_setTexture(rpg->cursor->curs, rpg->cursor->curs_tex, sfTrue);
    sfSprite_setScale(rpg->cursor->curs, (sfVector2f) {0.3, 0.3});
}
