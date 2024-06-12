/*
** EPITECH PROJECT, 2024
** init mana
** File description:
** file for init struct mana
*/
#include "../../Include/my.h"

//init struct mana
void init_mana(rpg_t *rpg)
{
    rpg->mana = malloc(sizeof(mana_t));
    rpg->mana->mana_empty = texture(MANA);
    rpg->mana->mana_fill = texture(MANA_UI);
    rpg->mana->mana_sp = create_rectangle_shape((sfVector2f)
    {240, 40}, (sfVector2f) {0, 0}, MANA_UI);
    rpg->mana->mana_bar = create_rectangle_shape((sfVector2f)
    {208, 23}, (sfVector2f) {0, 0}, MANA);
    rpg->mana->cl_mana = sfClock_create();
}
