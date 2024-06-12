/*
** EPITECH PROJECT, 2024
** button_upgrade.c
** File description:
** button_upgrade
*/

#include "../../Include/my.h"

//check if player click to increase heal
static void hover_set_health(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->health < 6 && rpg->skill->point > 0) {
            rpg->skill->health++;
            rpg->skill->point--;
            rpg->health->total_pv++;
            rpg->health->pv++;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if player click to increase mana
static void hover_set_mana(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->mana < 6 && rpg->skill->point > 0) {
            rpg->skill->mana++;
            rpg->skill->point--;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if player click to increase armor
void hover_set_armor(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->armor < 6 && rpg->skill->point > 0) {
            rpg->skill->armor++;
            rpg->skill->point--;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if player click to increase strenght
void hover_set_strenght(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->strenght < 6 && rpg->skill->point > 0) {
            rpg->skill->strenght++;
            rpg->skill->point--;
            rpg->player->atk += 0.25;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if player click to increase luck
void hover_set_luck(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->luck < 6 && rpg->skill->point > 0) {
            rpg->skill->luck++;
            rpg->skill->point--;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//check if player click to increase speed
void hover_set_speed(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->skill->speed < 6 && rpg->skill->point > 0) {
            rpg->skill->speed++;
            rpg->skill->point--;
            rpg->player->player_speed += 0.35;
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//call every function to increase talents
void hover_all_skills(rpg_t *rpg)
{
    if (rpg->inv->open == 1) {
        hover_set_health(rpg, sfWhite, rpg->inv->skills[0]);
        hover_set_mana(rpg, sfWhite, rpg->inv->skills[1]);
        hover_set_armor(rpg, sfWhite, rpg->inv->skills[2]);
        hover_set_strenght(rpg, sfWhite, rpg->inv->skills[3]);
        hover_set_luck(rpg, sfWhite, rpg->inv->skills[4]);
        hover_set_speed(rpg, sfWhite, rpg->inv->skills[5]);
    }
}
