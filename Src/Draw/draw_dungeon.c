/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

void draw_monster(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 0) {
        draw_slime(rpg);
        draw_ghost(rpg);
        draw_trader(rpg);
        draw_crab(rpg);
        draw_snake(rpg);
        draw_golem(rpg);
        draw_dog(rpg);
    }
}

void draw_final_dungeon(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 5) {
        draw_dg_lava(rpg);
        draw_golem_dg(rpg);
    }
}

void draw_dungeon2(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 3) {
        draw_dg_sand(rpg);
        draw_snake_dg(rpg);
        draw_hud_arena_sand(rpg, rpg->dg->dg_sand->arena->start_fight,
        rpg->dg->dg_sand->arena->win);
    }
    if (rpg->dg->in_dungeon == 4) {
        draw_dg_mountain(rpg);
        draw_dog_dg(rpg);
        draw_hud_arena_mountain(rpg, rpg->dg->dg_mountain->arena->start_fight,
        rpg->dg->dg_mountain->arena->win);
    }
}

void draw_dungeon(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 1) {
        draw_dg_forest(rpg);
        draw_ghost_dg(rpg);
        draw_hud_arena_forest(rpg, rpg->dg->dg_forest->arena->start_fight,
        rpg->dg->dg_forest->arena->win);
    }
    if (rpg->dg->in_dungeon == 2) {
        draw_dg_water(rpg);
        draw_slime_dg(rpg);
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->grap_pillar[14]->pillar, NULL);
        draw_hud_arena_water(rpg, rpg->dg->dg_water->arena->start_fight,
        rpg->dg->dg_water->arena->win);
    }
    draw_dungeon2(rpg);
    draw_final_dungeon(rpg);
}

void draw_dungeon_hud(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon > 0) {
        draw_dg_hud(rpg);
    }
}
