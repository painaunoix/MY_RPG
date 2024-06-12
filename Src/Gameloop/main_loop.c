/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

void dungeon_loop(rpg_t *rpg)
{
    dg_loop(rpg);
    dg_loop_water(rpg);
    dg_loop_snake(rpg);
    dg_loop_mountain(rpg);
    dg_loop_lava(rpg);
}

//move all monster to player
void move_monster_all(rpg_t *rpg)
{
    move_crab(rpg);
    if (rpg->dg->in_dungeon == 0 && rpg->die->die == sfFalse) {
        move_to_player_slime(rpg);
        move_to_player_ghost(rpg);
        move_to_player_snake(rpg);
        move_to_player_dog(rpg);
        move_to_player_golem(rpg);
    }
    if (rpg->dg->in_dungeon == 1 && rpg->die->die == sfFalse)
        move_to_player_ghost_dg(rpg);
    if (rpg->dg->in_dungeon == 2 && rpg->die->die == sfFalse)
        move_to_player_slime_dg(rpg);
    if (rpg->dg->in_dungeon == 3 && rpg->die->die == sfFalse)
        move_to_player_snake_dg(rpg);
    if (rpg->dg->in_dungeon == 4 && rpg->die->die == sfFalse)
        move_to_player_dog_dg(rpg);
    if (rpg->dg->in_dungeon == 5 && rpg->die->die == sfFalse)
        move_to_player_golem_dg(rpg);
    moving_crab_all(rpg);
}

//link zone with player and update interaction with player
void game2(rpg_t *rpg)
{
    player(rpg);
    link_hitbox(rpg);
    for (int i = 0; rpg->grap_pillar[i]; i++)
        grap_move(rpg, i);
    interact_chest(rpg);
    check_walk(rpg);
    check_attack(rpg);
    att_zone_link(rpg);
    is_chest_open(rpg);
    move_monster_all(rpg);
    is_door_taken(rpg);
    is_cave_taken(rpg);
    interact_big_torch(rpg);
    dungeon_loop(rpg);
    if (rpg->dg->in_dungeon == 5 && rpg->boss->start_boss == 1)
        boss_attack(rpg);
    trigger_start_boss(rpg);
    trigger_end_game(rpg);
    link_hitbox_boss(rpg);
    swap_zone(rpg);
}

//link zone with player and update interaction with player
void game(rpg_t *rpg)
{
    if (rpg->game_state == 0) {
        hover_play(rpg, sfColor_fromRGB(200, 200, 200), sfWhite,
            rpg->menu->Play);
        hover_continue(rpg, sfColor_fromRGB(200, 200, 200),
            sfWhite, rpg->menu->Continue);
        hover_setting(rpg, sfColor_fromRGB(200, 200, 200),
            sfWhite, rpg->menu->Setting);
        hover_quit(rpg, sfColor_fromRGB(200, 200, 200), sfWhite,
            rpg->menu->Quit);
    }
    if (rpg->game_state == 1)
        game2(rpg);
}
