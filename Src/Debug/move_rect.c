/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move rect for find place
*/

#include "../../Include/my.h"

//moving rectangle by press arrow
void move_rect(sfRectangleShape *rect, rpg_t *rpg)
{
    sfVector2f pos = sfRectangleShape_getPosition(rect);

    if (sfKeyboard_isKeyPressed(sfKeyUp)) {
        pos.y -= 5;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown)) {
        pos.y += 5;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft)) {
        pos.x -= 5;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    if (sfKeyboard_isKeyPressed(sfKeyRight)) {
        pos.x += 5;
        printf("x = %f y = %f\n", pos.x, pos.y);
    }
    sfRectangleShape_setPosition(rect, pos);
}
