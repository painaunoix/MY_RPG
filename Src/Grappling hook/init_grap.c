/*
** EPITECH PROJECT, 2024
** init grap
** File description:
** file for init struct for grappling hook
*/

#include "../../Include/my.h"

//init grap struct
void init_grap(rpg_t *rpg)
{
    sfVector2f size = {375, 10};

    rpg->grap = malloc(sizeof(grap_t));
    rpg->grap->lunch = sfFalse;
    rpg->grap->rope = create_rectangle(size,
    sfSprite_getPosition(rpg->player->player));
    rpg->grap->zone = create_rectangle((sfVector2f) {180, 800},
    (sfVector2f) {4480, 4170});
    rpg->grap->dis_rope = sfConvexShape_create();
    sfConvexShape_setTexture(rpg->grap->dis_rope, texture(ROPE), sfTrue);
    rpg->grap->idx_target = 0;
    rpg->grap->axis = 0;
}

//init array of grap pillar struct
void grap_pillard(rpg_t *rpg)
{
    rpg->grap_pillar = malloc(sizeof(grap_pillar_t *) * 16);
    pillard(rpg, 6255, 6055, 0);
    pillard(rpg, 6695, 5975, 1);
    pillard(rpg, 7285, 6090, 2);
    pillard(rpg, 7695, 5975, 3);
    pillard(rpg, 8065, 5510, 4);
    pillard(rpg, 8460, 5630, 5);
    pillard(rpg, 9040, 5500, 6);
    pillard(rpg, 9430, 5630, 7);
    pillard(rpg, 4775, 4460, 8);
    pillard(rpg, 5735, 3425, 9);
    pillard(rpg, 4325, 4660, 10);
    pillard(rpg, 5300, 3495, 11);
    pillard(rpg, 2550, 2605, 12);
    pillard(rpg, 3170, 2200, 13);
    pillard(rpg, 5055, 1220, 14);
}
