/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** inv eve
*/

#include "../../Include/my.h"

//call every event function
void event_key(rpg_t *rpg)
{
    check_esc(rpg);
    check_inv(rpg);
    is_slash_press(rpg);
    check_map(rpg);
    is_mouse_on_slot(rpg);
    is_frame_click(rpg);
    check_quests(rpg);
    talk_trader(rpg);
    player_save(rpg);
    is_pot_use(rpg);
    is_dock_use(rpg);
    change_boat(rpg);
    move_inventory(rpg);
    change_speed(rpg);
    is_speed_gem_use(rpg);
    is_arm_gem_use(rpg);
    is_stg_gem_use(rpg);
    vol_handling(rpg);
    vol_handling_main(rpg);
    hover_set_esc(rpg, sfWhite, rpg->esc->set_r);
}
