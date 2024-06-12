/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** display target
*/

#include "../../Include/my.h"

//set pillar position and texture
sfRectangleShape *create_pillar(rpg_t *rpg, int x, int y)
{
    sfRectangleShape *rec;

    rec = sfRectangleShape_create();
    sfRectangleShape_setPosition(rec, (sfVector2f) {x, y});
    sfRectangleShape_setSize(rec, (sfVector2f) {60, 100});
    sfRectangleShape_setTexture(rec, texture(PILLAR), sfTrue);
    return rec;
}

//malloc pillar struct
void pillard(rpg_t *rpg, int x, int y, int i)
{
    rpg->grap_pillar[i] = malloc(sizeof(grap_pillar_t));
    rpg->grap_pillar[i]->pillar = create_pillar(rpg, x, y);
    rpg->grap_pillar[i + 1] = NULL;
}

//draw every target for grapplin
void draw_grap(rpg_t *rpg)
{
    for (int i = 0; i != 14; i++) {
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->grap_pillar[i]->pillar, NULL);
    }
}
