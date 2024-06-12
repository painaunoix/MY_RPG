/*
** EPITECH PROJECT, 2024
** init cadre
** File description:
** file for init struct cadre
*/

#include "../../Include/my.h"

//init struct cadre
void init_cadre(rpg_t *rpg)
{
    rpg->cadre = malloc(sizeof(cadre_t));
    rpg->cadre->cadre_tex = texture(CADRE);
    rpg->cadre->cadre = create_rectangle_shape((sfVector2f)
    {80, 80}, (sfVector2f) {0, 0}, CADRE);
    rpg->cadre->cadre2 = create_rectangle_shape((sfVector2f)
    {80, 80}, (sfVector2f) {0, 0}, CADRE);
    rpg->cadre->item2 = sfRectangleShape_create();
    rpg->cadre->item = sfRectangleShape_create();
    rpg->cadre->itm1 = NULL;
    rpg->cadre->itm2 = NULL;
}
