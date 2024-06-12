/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

void key_water(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->dg->dg_water->silver_key1,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_water->silver_key2,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_water->gold_key,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_water->gold_key2,
    rpg->dg->dg_forest->key_rect);
}

void key_forest(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->dg->dg_forest->silver_key1,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_forest->silver_key2,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_forest->gold_key,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_forest->gold_key2,
    rpg->dg->dg_forest->key_rect);
}

void key_sand(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->dg->dg_sand->silver_key1,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_sand->gold_key,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_sand->gold_key2,
    rpg->dg->dg_forest->key_rect);
}

void key_mountain(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->dg->dg_mountain->silver_key1,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_mountain->gold_key,
    rpg->dg->dg_forest->key_rect);
    sfSprite_setTextureRect(rpg->dg->dg_mountain->gold_key2,
    rpg->dg->dg_forest->key_rect);
}

static void key_lava(rpg_t *rpg)
{
    sfSprite_setTextureRect(rpg->dg->dg_lava->gold_key,
    rpg->dg->dg_forest->key_rect);
}

void animation_key(rpg_t *rpg)
{
    if (rpg->dg->dg_forest->key_rect.left < 176) {
        rpg->dg->dg_forest->key_rect.left += 16;
    } else {
        rpg->dg->dg_forest->key_rect.left = 0;
    }
    key_forest(rpg);
    key_water(rpg);
    key_sand(rpg);
    key_mountain(rpg);
    key_lava(rpg);
}
