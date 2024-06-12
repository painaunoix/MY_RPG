/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//create all clock
void create_clock(rpg_t *rpg)
{
    rpg->player->clock = sfClock_create();
    rpg->chest_opn->clock = sfClock_create();
    rpg->anim_monst->clock_slime = sfClock_create();
    rpg->dg->dg_forest->clock_key = sfClock_create();
    rpg->anim_monst->clock_ghost = sfClock_create();
    rpg->anim_monst->clock_crab = sfClock_create();
    rpg->anim_monst->clock_snake = sfClock_create();
    rpg->anim_monst->clock_golem = sfClock_create();
    rpg->anim_monst->clock_dog = sfClock_create();
    rpg->b_torch->clock = sfClock_create();
    rpg->boss->clock = sfClock_create();
    rpg->boss->clock_move = sfClock_create();
    rpg->boss->clock_attack = sfClock_create();
    rpg->boss->clock_start_atk = sfClock_create();
    rpg->boss->clock_start_atk_anim = sfClock_create();
    rpg->boss->clock_trigger = sfClock_create();
}

//create clock for monster
void setup_clock(rpg_t *rpg)
{
    create_clock(rpg);
    for (int i = 0; rpg->slime[i]; i++)
        rpg->slime[i]->clock = sfClock_create();
    for (int i = 0; rpg->ghost[i]; i++)
        rpg->ghost[i]->clock = sfClock_create();
    for (int i = 0; rpg->crab[i]; i++)
        rpg->crab[i]->clock = sfClock_create();
    for (int i = 0; rpg->snake[i]; i++)
        rpg->snake[i]->clock = sfClock_create();
    for (int i = 0; rpg->golem[i]; i++)
        rpg->golem[i]->clock = sfClock_create();
    for (int i = 0; rpg->dog[i]; i++)
        rpg->dog[i]->clock = sfClock_create();
}

//get time of dog clock
static void run_clock_dog(rpg_t *rpg)
{
    rpg->anim_monst->time_dog =
    sfClock_getElapsedTime(rpg->anim_monst->clock_dog);
    rpg->anim_monst->seconds_dog =
    sfTime_asSeconds(rpg->anim_monst->time_dog);
    for (int i = 0; rpg->dog[i]; i++) {
        rpg->dog[i]->time = sfClock_getElapsedTime(rpg->dog[i]->clock);
        rpg->dog[i]->seconds = sfTime_asSeconds(rpg->dog[i]->time);
    }
}

//get time of golem clock
static void run_clock_golem(rpg_t *rpg)
{
    rpg->anim_monst->time_golem =
    sfClock_getElapsedTime(rpg->anim_monst->clock_golem);
    rpg->anim_monst->seconds_golem =
    sfTime_asSeconds(rpg->anim_monst->time_golem);
    for (int i = 0; rpg->golem[i]; i++) {
        rpg->golem[i]->time = sfClock_getElapsedTime(rpg->golem[i]->clock);
        rpg->golem[i]->seconds = sfTime_asSeconds(rpg->golem[i]->time);
    }
}

//get time of snake clock
static void run_clock_snake(rpg_t *rpg)
{
    rpg->anim_monst->time_snake =
    sfClock_getElapsedTime(rpg->anim_monst->clock_snake);
    rpg->anim_monst->seconds_snake =
    sfTime_asSeconds(rpg->anim_monst->time_snake);
    for (int i = 0; rpg->snake[i]; i++) {
        rpg->snake[i]->time = sfClock_getElapsedTime(rpg->snake[i]->clock);
        rpg->snake[i]->seconds = sfTime_asSeconds(rpg->snake[i]->time);
    }
}

//get time of ghost clock
static void run_clock_ghost(rpg_t *rpg)
{
    rpg->anim_monst->time_ghost =
    sfClock_getElapsedTime(rpg->anim_monst->clock_ghost);
    rpg->anim_monst->seconds_ghost =
    sfTime_asSeconds(rpg->anim_monst->time_ghost);
    for (int i = 0; rpg->ghost[i]; i++) {
        rpg->ghost[i]->time = sfClock_getElapsedTime(rpg->ghost[i]->clock);
        rpg->ghost[i]->seconds = sfTime_asSeconds(rpg->ghost[i]->time);
    }
}

//get time of crab clock
static void run_clock_crab(rpg_t *rpg)
{
    rpg->anim_monst->time_crab =
    sfClock_getElapsedTime(rpg->anim_monst->clock_crab);
    rpg->anim_monst->seconds_crab =
    sfTime_asSeconds(rpg->anim_monst->time_crab);
    for (int i = 0; rpg->crab[i]; i++) {
        rpg->crab[i]->time = sfClock_getElapsedTime(rpg->crab[i]->clock);
        rpg->crab[i]->seconds = sfTime_asSeconds(rpg->crab[i]->time);
    }
}

//get time of slime and attack clock
static void run_clock_part2(rpg_t *rpg)
{
    if (rpg->attack->attack == 1) {
        rpg->attack->time = sfClock_getElapsedTime(rpg->attack->clock);
        rpg->attack->seconds = sfTime_asSeconds(rpg->attack->time);
    }
    rpg->anim_monst->time_slime =
    sfClock_getElapsedTime(rpg->anim_monst->clock_slime);
    rpg->anim_monst->seconds_slime =
    sfTime_asSeconds(rpg->anim_monst->time_slime);
    for (int i = 0; rpg->slime[i]; i++) {
        rpg->slime[i]->time = sfClock_getElapsedTime(rpg->slime[i]->clock);
        rpg->slime[i]->seconds = sfTime_asSeconds(rpg->slime[i]->time);
    }
}

//call function for get clock time
void run_clock(rpg_t *rpg)
{
    rpg->player->time = sfClock_getElapsedTime(rpg->player->clock);
    rpg->player->seconds = sfTime_asSeconds(rpg->player->time);
    rpg->chest_opn->time = sfClock_getElapsedTime(rpg->chest_opn->clock);
    rpg->chest_opn->seconds = sfTime_asSeconds(rpg->chest_opn->time);
    rpg->b_torch->time = sfClock_getElapsedTime(rpg->b_torch->clock);
    rpg->b_torch->seconds = sfTime_asSeconds(rpg->b_torch->time);
    rpg->dg->dg_forest->time_key =
    sfClock_getElapsedTime(rpg->dg->dg_forest->clock_key);
    rpg->dg->dg_forest->seconds_key =
    sfTime_asSeconds(rpg->dg->dg_forest->time_key);
    run_clock_part2(rpg);
    run_clock_ghost(rpg);
    run_clock_crab(rpg);
    run_clock_snake(rpg);
    run_clock_golem(rpg);
    run_clock_dog(rpg);
}

//call function for get every clock time
void run_clock_all(rpg_t *rpg)
{
    run_clock(rpg);
}
