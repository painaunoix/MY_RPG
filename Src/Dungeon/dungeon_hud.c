/*
** EPITECH PROJECT, 2024
** init dungeon
** File description:
** file for init struct dungeon
*/

#include "../../Include/my.h"

void draw_dg_hud(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_hud->gold_key, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_hud->silver_key, NULL);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_hud->silver_text, NULL);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_hud->gold_text, NULL);
}

void set_pos_hud_dg(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->dg->dg_hud->gold_key,
    set_pos_mid_sprite_off(rpg, rpg->dg->dg_hud->gold_key, 500, -830));
    sfSprite_setPosition(rpg->dg->dg_hud->silver_key,
    set_pos_mid_sprite_off(rpg, rpg->dg->dg_hud->silver_key, 550, -830));
    sfText_setString(rpg->dg->dg_hud->silver_text,
    my_itos(rpg->dg->silver_key));
    sfText_setString(rpg->dg->dg_hud->gold_text,
    my_itos(rpg->dg->gold_key));
    sfText_setPosition(rpg->dg->dg_hud->silver_text,
    set_pos_mid_txt(rpg, rpg->dg->dg_hud->silver_text, 550, -790));
    sfText_setPosition(rpg->dg->dg_hud->gold_text,
    set_pos_mid_txt(rpg, rpg->dg->dg_hud->gold_text, 500, -790));
}

void init_dg_hud(rpg_t *rpg)
{
    sfIntRect key_rect;

    rpg->dg->dg_hud = malloc(sizeof(dg_hud_t));
    key_rect = make_rect(8, 16);
    rpg->dg->dg_hud->gold_key = create_sprite_rect((sfVector2f) {5, 5},
    (sfVector2f) {0, 0}, GOLD_KEY, key_rect);
    rpg->dg->dg_hud->silver_key = create_sprite_rect((sfVector2f) {5, 5},
    (sfVector2f) {0, 0}, SILVER_KEY, key_rect);
    rpg->dg->dg_hud->silver_text = create_texte_esc((sfVector2f) {30, 30},
    (sfVector2f) {0, 0}, sfWhite, "0");
    rpg->dg->dg_hud->gold_text = create_texte_esc((sfVector2f) {30, 30},
    (sfVector2f) {0, 0}, sfWhite, "0");
}
