/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init tutao
*/

#include "../../Include/my.h"

void init_tuto(rpg_t *rpg)
{
    rpg->tuto = malloc(sizeof(tuto_t));
    rpg->tuto->step = 1;
    rpg->tuto->step1 = create_texte_esc((sfVector2f) {50, 50}, (sfVector2f)
    {0, 0}, sfBlack, "Move your player using the keys\n              Z Q S D");
    rpg->tuto->step2 = create_texte_esc((sfVector2f) {50, 50}, (sfVector2f)
    {0, 0}, sfBlack, "Go to the chest and press E next to it");
    rpg->tuto->step3 = create_texte_esc((sfVector2f) {50, 50}, (sfVector2f)
    {0, 0}, sfBlack, "Open your inventory with I");
    rpg->tuto->step4 = create_texte_esc((sfVector2f) {50, 50}, (sfVector2f)
    {0, 0}, sfBlack,
    "Place the Axe in the top right corner by clicking on it and drag it");
    rpg->tuto->step5 = create_texte_esc((sfVector2f) {50, 50}, (sfVector2f)
    {0, 0}, sfBlack,
    "Close your inventory and go fight the crab by press SPACE");
}
