/*
** EPITECH PROJECT, 2024
** init player
** File description:
** file for init struct player
*/

#include "../../Include/my.h"

void is_slime_atk_dg(rpg_t *rpg)
{
    sfFloatRect zone_pos;
    sfFloatRect player_pos1;

    rpg->attack->attack = 1;
    for (int i = 9; rpg->slime[i]; i++) {
        zone_pos =
        sfSprite_getGlobalBounds(rpg->slime[i]->slime);
        player_pos1 =
        sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
        if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)
        && rpg->slime[i]->life > 0) {
            sfSprite_setTexture(rpg->slime[i]->slime,
            rpg->attack->slime_degat, sfFalse);
            knock_monster(rpg, i);
        }
    }
}

void is_ghost_atk_dg(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect ghost;

    for (int i = 8; rpg->ghost[i]; i++) {
        ghost = sfSprite_getGlobalBounds(rpg->ghost[i]->ghost);
        if (sfFloatRect_intersects(&ghost, &atk, NULL) &&
        rpg->ghost[i]->life > 0) {
            change_ghost_texture(rpg, i);
            knock_ghost(rpg, i);
        }
    }
}

void is_snake_atk_dg(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect snake;

    for (int i = 14; rpg->snake[i]; i++) {
        snake = sfSprite_getGlobalBounds(rpg->snake[i]->snake);
        if (sfFloatRect_intersects(&snake, &atk, NULL) &&
        rpg->snake[i]->life > 0) {
            change_snake_texture(rpg, i);
            knock_snake(rpg, i);
        }
    }
}

void is_golem_atk_dg(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect golem;

    for (int i = 7; rpg->golem[i]; i++) {
        golem = sfSprite_getGlobalBounds(rpg->golem[i]->golem);
        if (sfFloatRect_intersects(&golem, &atk, NULL) &&
        rpg->golem[i]->life > 0) {
            change_golem_texture(rpg, i);
            knock_golem(rpg, i);
        }
    }
}

void is_dog_atk_dg(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect dog;

    for (int i = 8; rpg->dog[i]; i++) {
        dog = sfSprite_getGlobalBounds(rpg->dog[i]->dog);
        if (sfFloatRect_intersects(&dog, &atk, NULL) &&
        rpg->dog[i]->life > 0) {
            change_dog_texture(rpg, i);
            knock_dog(rpg, i);
        }
    }
}
