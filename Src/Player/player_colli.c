/*
** EPITECH PROJECT, 2024
** player_colli.c
** File description:
** player_colli
*/

#include "../../Include/my.h"

//check collision for the player
int iscollision(rpg_t *rpg, sfImage *image)
{
    sfFloatRect playerBounds = sfSprite_getGlobalBounds(rpg->player->player);
    sfVector2f playerPos = sfSprite_getPosition(rpg->player->player);
    int x = 0;
    int y = 0;
    sfColor pixelColor;

    if (rpg->debug->coli == sfFalse)
        return (0);
    x = (int)(playerPos.x + playerBounds.width / 2);
    y = (int)(playerPos.y + playerBounds.height / 1.4);
    pixelColor = sfImage_getPixel(image, x, y);
    if (pixelColor.r == 255 && pixelColor.g == 0 && pixelColor.b == 0) {
        sfSprite_setPosition(rpg->player->player, rpg->player->prev);
    }
}

static void colli_dungeon_f(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 1 && rpg->boat->in_boat == 0) {
        iscollision(rpg, rpg->dg->dg_forest->red_map);
        if (rpg, rpg->dg->dg_forest->door[2]->open == 0)
            iscollision(rpg, rpg->dg->dg_forest->door[2]->door_img);
        if (rpg, rpg->dg->dg_forest->door[3]->open == 0)
            iscollision(rpg, rpg->dg->dg_forest->door[3]->door_img);
        if (rpg, rpg->dg->dg_forest->door[5]->open == 0)
            iscollision(rpg, rpg->dg->dg_forest->door[5]->door_img);
        if (rpg, rpg->dg->dg_forest->door[7]->open == 0)
            iscollision(rpg, rpg->dg->dg_forest->door[7]->door_img);
    }
    if (rpg->dg->in_dungeon == 1 && rpg->boat->in_boat == 1) {
        iscollision(rpg, rpg->boat->dg);
    }
}

static void colli_dungeon_w(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 2) {
        iscollision(rpg, rpg->dg->dg_water->red_map);
        if (rpg, rpg->dg->dg_water->door[0]->open == 0)
            iscollision(rpg, rpg->dg->dg_water->door[0]->door_img);
        if (rpg, rpg->dg->dg_water->door[1]->open == 0)
            iscollision(rpg, rpg->dg->dg_water->door[1]->door_img);
        if (rpg, rpg->dg->dg_water->door[2]->open == 0)
            iscollision(rpg, rpg->dg->dg_water->door[2]->door_img);
        if (rpg, rpg->dg->dg_water->door[3]->open == 0)
            iscollision(rpg, rpg->dg->dg_water->door[3]->door_img);
    }
}

static void colli_dungeon_s(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 3) {
        iscollision(rpg, rpg->dg->dg_sand->red_map);
        if (rpg->bomb[2]->use2 == sfTrue)
            iscollision(rpg, rpg->bomb[2]->img_rock);
        if (rpg, rpg->dg->dg_sand->door[1]->open == 0)
            iscollision(rpg, rpg->dg->dg_sand->door[1]->door_img);
        if (rpg, rpg->dg->dg_sand->door[2]->open == 0)
            iscollision(rpg, rpg->dg->dg_sand->door[2]->door_img);
        if (rpg, rpg->dg->dg_sand->door[3]->open == 0)
            iscollision(rpg, rpg->dg->dg_sand->door[3]->door_img);
    }
}

static void colli_dungeon_m(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 4) {
        iscollision(rpg, rpg->dg->dg_mountain->red_map);
        if (rpg, rpg->dg->dg_mountain->door[0]->open == 0)
            iscollision(rpg, rpg->dg->dg_mountain->door[0]->door_img);
        if (rpg, rpg->dg->dg_mountain->door[1]->open == 0)
            iscollision(rpg, rpg->dg->dg_mountain->door[1]->door_img);
        if (rpg, rpg->dg->dg_mountain->door[2]->open == 0)
            iscollision(rpg, rpg->dg->dg_mountain->door[2]->door_img);
    }
}

static void colli_dungeon_l(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 5) {
        iscollision(rpg, rpg->dg->dg_lava->red_map);
        if (rpg, rpg->dg->dg_lava->door[0]->open == 0)
            iscollision(rpg, rpg->dg->dg_lava->door[0]->door_img);
    }
}

static void colli_boat(rpg_t *rpg)
{
    if (rpg->boat->in_boat == 1) {
        iscollision(rpg, rpg->boat->img);
    }
}

void all_colli(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 0 && rpg->boat->in_boat == 0) {
        iscollision(rpg, rpg->w_map->red_m);
        if (rpg->bomb[0]->use2 == sfTrue)
            iscollision(rpg, rpg->bomb[0]->img_rock);
        if (rpg->bomb[1]->use2 == sfTrue)
            iscollision(rpg, rpg->bomb[1]->img_rock);
    }
    colli_dungeon_f(rpg);
    colli_dungeon_w(rpg);
    colli_dungeon_s(rpg);
    colli_dungeon_m(rpg);
    colli_dungeon_l(rpg);
    colli_boat(rpg);
}
