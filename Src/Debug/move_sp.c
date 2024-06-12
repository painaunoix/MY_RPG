/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move rect for find place
*/

#include "../../Include/my.h"
//moving sprite by press arrow
void move_sp(sfSprite *rect, rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rect);

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        pos.y -= 3;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        pos.y += 3;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        pos.x -= 3;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        pos.x += 3;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    sfSprite_setPosition(rect, pos);
}
