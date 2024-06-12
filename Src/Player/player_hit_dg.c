/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hit in dg
*/

#include "../../Include/my.h"

static int hit_hiden_6(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("boss", str) == 0) {
        if (rpg->dg->in_dungeon == 5 && rpg->boss->start_boss == 1)
            return (0);
    }
    if (my_strcmp("proj", str) == 0) {
        if (rpg->dg->in_dungeon == 5 && rpg->boss->start_boss == 1)
            return (0);
    }
    return 1;
}

int hit_hiden_5(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("dog", str) == 0) {
        if (rpg->dg->in_dungeon == 4 &&
        rpg->dg->dg_mountain->arena->start_fight == 1 &&
        i > rpg->hiden->dog[1] && i <= rpg->hiden->dog[2])
            return (0);
        if (rpg->dg->in_dungeon == 4 && i >= rpg->hiden->dog[0] && i <=
        rpg->hiden->dog[1])
            return (0);
        if (rpg->dg->in_dungeon == 0 && i >= 0 && i < rpg->hiden->dog[0])
            return (0);
    }
    return (hit_hiden_6(rpg, str, i));
}

int hit_hiden_4(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("golem", str) == 0) {
        if (rpg->dg->in_dungeon == 5 && i >= rpg->hiden->golem[0] && i <=
        rpg->hiden->golem[1]) {
            return (0);
        }
        if (rpg->dg->in_dungeon == 0 && i >= 0 && i < rpg->hiden->golem[0]) {
            return (0);
        }
    }
    return (hit_hiden_5(rpg, str, i));
}

int hit_hiden_3(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("snake", str) == 0) {
        if (rpg->dg->in_dungeon == 3 &&
        rpg->dg->dg_sand->arena->start_fight == 1 &&
        i > rpg->hiden->slime[1] && i <= rpg->hiden->slime[2])
            return (0);
        if (rpg->dg->in_dungeon == 3 && i >= rpg->hiden->snake[0] && i <=
        rpg->hiden->snake[1]) {
            return (0);
        }
        if (rpg->dg->in_dungeon == 0 && i >= 0 && i < rpg->hiden->snake[0]) {
            return (0);
        }
    }
    return (hit_hiden_4(rpg, str, i));
}

int hit_hiden_2(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("ghost", str) == 0) {
        if (rpg->dg->in_dungeon == 1 &&
        rpg->dg->dg_forest->arena->start_fight == 1 &&
        i > rpg->hiden->ghost[1] && i <= rpg->hiden->ghost[2])
            return (0);
        if (rpg->dg->in_dungeon == 1 && i >= rpg->hiden->ghost[0] && i <=
        rpg->hiden->ghost[1]) {
            return (0);
        }
        if (rpg->dg->in_dungeon == 0 && i >= 0 && i < rpg->hiden->ghost[0]) {
            return (0);
        }
    }
    return (hit_hiden_3(rpg, str, i));
}

int hit_hiden(rpg_t *rpg, char *str, int i)
{
    if (my_strcmp("slime", str) == 0) {
        if (rpg->dg->in_dungeon == 2 &&
        rpg->dg->dg_water->arena->start_fight == 1 &&
        i > rpg->hiden->slime[1] && i <= rpg->hiden->slime[2])
            return (0);
        if (rpg->dg->in_dungeon == 2 && i >= rpg->hiden->slime[0] && i <=
        rpg->hiden->slime[1])
            return (0);
        if (rpg->dg->in_dungeon == 0 && i >= 0 && i < rpg->hiden->slime[0])
            return (0);
    }
    return (hit_hiden_2(rpg, str, i));
}
