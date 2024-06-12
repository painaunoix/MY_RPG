/*
** EPITECH PROJECT, 2024
** init escape
** File description:
** file for init struct escape
*/

#include "../../Include/my.h"

//init strcuct escap
void init_escap(rpg_t *rpg)
{
    rpg->esc = malloc(sizeof(escape_t));
    rpg->esc->opt_txt = create_texte_esc((sfVector2f) {50, 45},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), "OPTIONS");
    rpg->esc->inv_txt = create_texte_esc((sfVector2f) {30, 45},
    (sfVector2f) {0, 0}, sfColor_fromRGB(136, 89, 70), "INVENTORY");
    rpg->esc->set_txt = create_texte_esc((sfVector2f) {30, 45},
    (sfVector2f) {0, 0}, sfColor_fromRGB(136, 89, 70), "SETTINGS");
    rpg->esc->quit_txt = create_texte_esc((sfVector2f) {30, 45},
    (sfVector2f) {0, 0}, sfColor_fromRGB(136, 89, 70), "QUIT");
    rpg->esc->back = create_sprite((sfVector2f) {3, 3}, (sfVector2f) {0, 0},
        FOND_ESCAPE);
    rpg->esc->cross_r = create_rectangle_shape((sfVector2f) {60, 60},
        (sfVector2f) {0, 0}, CROSS_ESCAPE);
    rpg->esc->inv_r = create_rectangle_shape((sfVector2f) {300, 100},
        (sfVector2f) {0, 0}, CASE_ESCAPE);
    rpg->esc->quit_r = create_rectangle_shape((sfVector2f) {300, 100},
        (sfVector2f) {0, 0}, CASE_ESCAPE);
    rpg->esc->set_r = create_rectangle_shape((sfVector2f) {300, 100},
        (sfVector2f) {0, 0}, CASE_ESCAPE);
    rpg->esc->esc_check = 0;
}
