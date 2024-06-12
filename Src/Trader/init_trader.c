/*
** EPITECH PROJECT, 2024
** init trader
** File description:
** file for init struct trader
*/

#include "../../Include/my.h"

//init struct trader
void init_trader(rpg_t *rpg)
{
    rpg->trader = malloc(sizeof(trader_t));
    rpg->trader->rect = create_rectangle((sfVector2f) {120, 120},
    (sfVector2f) {2395, 7735});
    rpg->trader->rec = make_rect(141, 166 / 2);
    rpg->trader->trader = create_sprite_rect((sfVector2f) {0.5, 0.5},
    (sfVector2f) {2395, 7735}, TRADER, rpg->trader->rec);
    rpg->trader->cl = sfClock_create();
    rpg->trader->open = 0;
    rpg->trader->coin = create_texte_esc((sfVector2f) {25, 25},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "");
    rpg->trader->back = create_rectangle_shape((sfVector2f) {500, 440},
    (sfVector2f) {0, 0}, QTS);
    rpg->trader->shop = create_texte_esc((sfVector2f) {10, 50}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "SHOP");
}

void init_text(rpg_t *rpg)
{
    rpg->tra_but[2]->item = create_rectangle_shape((sfVector2f) {50,
    50}, (sfVector2f) {0, 0}, ITM_STRENGHT);
    rpg->tra_but[0]->cost = create_texte_esc((sfVector2f) {25, 25},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "100");
    rpg->tra_but[1]->cost = create_texte_esc((sfVector2f) {25, 25},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "50");
    rpg->tra_but[2]->cost = create_texte_esc((sfVector2f) {25, 25},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "80");
}

//init trader button
void init_trader_but(rpg_t *rpg)
{
    rpg->tra_but = malloc(sizeof(trader_but_t *) * 4);
    for (int i = 0; i != 4; i++) {
        rpg->tra_but[i] = malloc(sizeof(trader_but_t));
        rpg->tra_but[i]->rec = create_rectangle_shape((sfVector2f)
        {80, 80}, (sfVector2f) {0, 0}, VIDE);
        rpg->tra_but[i]->buy = create_texte_esc((sfVector2f) {30, 30},
        (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "BUY");
    }
    rpg->tra_but[0]->price = 100;
    rpg->tra_but[1]->price = 50;
    rpg->tra_but[2]->price = 80;
    rpg->tra_but[0]->name = my_strdup(ITM_SPEED);
    rpg->tra_but[1]->name = my_strdup(POTION);
    rpg->tra_but[2]->name = my_strdup(ITM_STRENGHT);
    rpg->tra_but[0]->item = create_rectangle_shape((sfVector2f) {50,
    50}, (sfVector2f) {0, 0}, ITM_SPEED);
    rpg->tra_but[1]->item = create_rectangle_shape((sfVector2f) {50,
    50}, (sfVector2f) {0, 0}, POTION);
    init_text(rpg);
}
