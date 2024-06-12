/*
** EPITECH PROJECT, 2024
** mana.c
** File description:
** mana
*/

#include "../../Include/my.h"

//draw mana bar
void draw_mana(rpg_t *rpg)
{
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->mana->mana_bar, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->mana->mana_sp, NULL);
}

void adapte_mana(rpg_t *rpg)
{
    sfVector2f size = sfRectangleShape_getSize(rpg->mana->mana_bar);

    if (size.x < 104)
        return;
    size.x -= 104;
    sfRectangleShape_setSize(rpg->mana->mana_bar, size);
}

void mana_up(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->mana->cl_mana);
    sfVector2f size = sfRectangleShape_getSize(rpg->mana->mana_bar);
    float second = sfTime_asSeconds(time);

    if (second > 1.5) {
        size.x += 2 + rpg->skill->mana;
        sfClock_restart(rpg->mana->cl_mana);
    }
    if (size.x > 208)
        size.x = 208;
    sfRectangleShape_setSize(rpg->mana->mana_bar, size);
}

//move mana bar if the healt is greatter than 5
void set_mana(rpg_t *rpg)
{
    sfVector2f pos = rpg->win->center;
    sfVector2f pos_bar = rpg->win->center;

    mana_up(rpg);
    if (rpg->health->total_pv >= 6) {
        pos_bar.y -= 328;
        pos_bar.x -= 820;
        pos.y -= 340;
        pos.x -= 850;
    } else {
        pos_bar.y -= 368;
        pos_bar.x -= 820;
        pos.y -= 380;
        pos.x -= 850;
    }
    sfRectangleShape_setPosition(rpg->mana->mana_bar, pos_bar);
    sfRectangleShape_setPosition(rpg->mana->mana_sp, pos);
    draw_mana(rpg);
}
