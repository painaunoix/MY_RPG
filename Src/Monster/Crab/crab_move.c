/*
** EPITECH PROJECT, 2024
** crab_move.c
** File description:
** crab_move
*/

#include "../../../Include/my.h"

//check in witch direction the crab need to move
void crab_intersect(rpg_t *rpg, int i, sfVector2f crab_pos,
    sfVector2f player_pos)
{
    sfVector2f pos = {0, 0};

    rpg->crab[i]->is_moving = 1;
    if (crab_pos.x > player_pos.x)
        pos.x = -2;
    if (crab_pos.x < player_pos.x)
        pos.x = 2;
    if (crab_pos.y > player_pos.y)
        pos.y = -2;
    if (crab_pos.y < player_pos.y)
        pos.y = 2;
    sfSprite_move(rpg->crab[i]->crab, pos);
}

//detect player with crab
void move_to_player_crab(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos =
    sfCircleShape_getGlobalBounds(rpg->crab[i]->zone);
    sfVector2f crab_pos =
    sfSprite_getPosition(rpg->crab[i]->crab);
    sfVector2f player_pos =
    sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)) {
        crab_intersect(rpg, i, crab_pos, player_pos);
    } else
        rpg->crab[i]->is_moving = 0;
}

void move_crab(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; rpg->crab[i] != NULL; i++) {
        sfCircleShape_setPosition(rpg->crab[i]->zone,
        sfSprite_getPosition(rpg->crab[i]->crab));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->crab[i]->seconds > 0.03) {
            move_to_player_crab(rpg, i);
            sfClock_restart(rpg->crab[i]->clock);
        }
    }
}

void moving_crab(rpg_t *rpg, int i, sfVector2f crab_pos)
{
    crab_pos = sfSprite_getPosition(rpg->crab[i]->crab);
    if (crab_pos.x < 3600 && rpg->crab[i]->is_moving == 0) {
        rpg->crab[i]->change = 0;
        crab_pos.x++;
        sfSprite_setPosition(rpg->crab[i]->crab, crab_pos);
    }
    if (crab_pos.x > 3700 && rpg->crab[i]->is_moving == 0) {
        rpg->crab[i]->change = 1;
        crab_pos.x--;
        sfSprite_setPosition(rpg->crab[i]->crab, crab_pos);
        return;
    }
    if (rpg->crab[i]->change == 1 && rpg->crab[i]->is_moving == 0) {
        crab_pos.x--;
        sfSprite_setPosition(rpg->crab[i]->crab, crab_pos);
    }
    if (rpg->crab[i]->change == 0 && rpg->crab[i]->is_moving == 0) {
        crab_pos.x++;
        sfSprite_setPosition(rpg->crab[i]->crab, crab_pos);
    }
}

void moving_crab_all(rpg_t *rpg)
{
    moving_crab(rpg, 0, (sfVector2f) {0, 0});
}
