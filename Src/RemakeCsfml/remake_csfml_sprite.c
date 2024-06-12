/*
** EPITECH PROJECT, 2024
** main.cic
** File description:
** main
*/

#include "../../Include/my.h"

sfSprite *create_sprite_rect(sfVector2f scale, sfVector2f pos,
    char *file, sfIntRect rect)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, sfTexture_createFromFile(file, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    return sprite;
}

sfSprite *create_sprite(sfVector2f scale, sfVector2f pos, char *file)
{
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, sfTexture_createFromFile(file, NULL), sfTrue);
    return sprite;
}

//create texte from file
sfTexture *texture(char *file)
{
    sfTexture *texture;

    if (file == NULL)
        return NULL;
    texture = sfTexture_createFromFile(file, NULL);
    return texture;
}

sfRectangleShape *create_rectangle_shape(sfVector2f scale,
    sfVector2f pos, char *file)
{
    sfRectangleShape *rec;

    rec = sfRectangleShape_create();
    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setSize(rec, scale);
    sfRectangleShape_setTexture(rec, texture(file), sfTrue);
    return rec;
}

sfRectangleShape *create_rectangle(sfVector2f scale, sfVector2f pos)
{
    sfRectangleShape *rec;

    rec = sfRectangleShape_create();
    sfRectangleShape_setPosition(rec, pos);
    sfRectangleShape_setSize(rec, scale);
    sfRectangleShape_setOutlineColor(rec, sfWhite);
    sfRectangleShape_setOutlineThickness(rec, 3);
    sfRectangleShape_setFillColor(rec, sfWhite);
    return rec;
}
