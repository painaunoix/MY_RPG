/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

static void draw_boss(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->boss->boss, NULL);
    for (int i = 0; rpg->boss->proj[i]; i++) {
        if (rpg->boss->proj[i]->life > 0)
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->boss->proj[i]->projectile, NULL);
    }
    sfRectangleShape_setPosition(rpg->boss->healt_bar,
    set_pos_mid_rectan(rpg, rpg->boss->healt_bar, 300, -600));
    sfSprite_setPosition(rpg->boss->bar, set_pos_mid_sprite_off
    (rpg, rpg->boss->bar, 0, 0));
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->boss->healt_bar, NULL);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->boss->bar, NULL);
}

static void draw_hell_door(rpg_t *rpg)
{
    int nb = 0;

    for (int i = 0; rpg->b_torch->torch[i]; i++) {
        if (rpg->b_torch->torch[i]->state == 1)
            nb++;
    }
    if (nb == 7 && rpg->dg->in_dungeon == 0)
        sfRenderWindow_drawSprite(rpg->win->window, rpg->hell_door, NULL);
    if (rpg->dg->in_dungeon == 0)
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->chest[0]->chest_close, NULL);
}

//draw escape menu
void draw_esc(rpg_t *rpg)
{
    if (rpg->esc->esc_check == 1)
            draw_esacpe(rpg);
    if (rpg->set->open == 1){
        draw_setting(rpg);
        draw_volume(rpg);
    }
}

//draw command menu
static void draw_com(rpg_t *rpg)
{
    if (rpg->com->wait_in == sfTrue) {
        sfText_setPosition(rpg->com->com,
        set_pos_mid_txt(rpg, rpg->com->com, 900, 0));
        sfRenderWindow_drawText(rpg->win->window, rpg->com->com, NULL);
    }
}

//draw hud
static void draw_hud(rpg_t *rpg)
{
    set_health(rpg);
    set_mana(rpg);
    set_cadre(rpg);
    draw_com(rpg);
    draw_buff(rpg);
    if (rpg->die->die == sfTrue)
        screen_die(rpg);
    if (rpg->map->open == 1) {
        draw_map_cadre(rpg);
        draw_minimap(rpg);
    }
}

void draw_game_play_split(rpg_t *rpg)
{
    draw_trader(rpg);
    display_bomb(rpg);
    show_tuto_item(rpg);
    if (rpg->boss->start_boss == 1 && rpg->dg->in_dungeon == 5)
        if (rpg->boss->life > 0)
            draw_boss(rpg);
    draw_hud(rpg);
}

//call function for draw multiple things
void draw_game_play(rpg_t *rpg)
{
    draw_map(rpg);
    draw_dungeon(rpg);
    display_red(rpg);
    display_rope(rpg);
    draw_hell_door(rpg);
    if (rpg->dg->in_dungeon == 0) {
        draw_grap(rpg);
        draw_save_stone(rpg);
        draw_big_torch(rpg);
    }
    draw_player(rpg);
    draw_monster(rpg);
    if (rpg->dg->in_dungeon == 0)
        draw_top_map(rpg);
    set_pos_hud_dg(rpg);
    draw_dungeon_hud(rpg);
    draw_game_play_split(rpg);
    draw_end(rpg);
}

static void draw_game_state_zero(rpg_t *rpg)
{
    if (rpg->game_state == 0) {
        draw_menu(rpg);
        if (rpg->set_open == 1) {
            draw_setting_main(rpg);
            draw_volume(rpg);
        }
        not_dsiplay_cursor_menu(rpg);
    }
}

//call every function for draw
void draw_all(rpg_t *rpg)
{
    draw_game_state_zero(rpg);
    if (rpg->game_state == 1) {
        draw_game_play(rpg);
        if (rpg->chest_opn->open == 1)
            draw_particle(rpg);
        if (rpg->inv->open == 1) {
            draw_inventory(rpg);
            draw_skill_up(rpg);
        }
        if (rpg->qts->open == 1)
            draw_quests(rpg);
        draw_esc(rpg);
        not_dsiplay_cursor(rpg);
        change_to_boat(rpg);
        display_tuto(rpg);
    }
}
