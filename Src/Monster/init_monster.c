/*
** EPITECH PROJECT, 2024
** init monster
** File description:
** file for init struct global for monster
*/

#include "../../Include/my.h"

void setup_monster_value(rpg_t *rpg)
{
    rpg->hiden->dog[0] = 8;
    rpg->hiden->dog[1] = 32;
    rpg->hiden->dog[2] = 44;
    rpg->hiden->ghost[0] = 8;
    rpg->hiden->ghost[1] = 24;
    rpg->hiden->ghost[2] = 32;
    rpg->hiden->golem[0] = 7;
    rpg->hiden->golem[1] = 8;
    rpg->hiden->slime[0] = 9;
    rpg->hiden->slime[1] = 30;
    rpg->hiden->slime[2] = 42;
    rpg->hiden->snake[0] = 14;
    rpg->hiden->snake[1] = 34;
    rpg->hiden->snake[2] = 46;
}

void init_anim_monster(rpg_t *rpg)
{
    rpg->anim_monst = malloc(sizeof(anim_monst_t));
    rpg->hiden = malloc(sizeof(hiden_t));
    rpg->hiden->dog = malloc(sizeof(int) * 3);
    rpg->hiden->slime = malloc(sizeof(int) * 3);
    rpg->hiden->ghost = malloc(sizeof(int) * 3);
    rpg->hiden->snake = malloc(sizeof(int) * 3);
    rpg->hiden->golem = malloc(sizeof(int) * 2);
    setup_monster_value(rpg);
}
