/*
** EPITECH PROJECT, 2024
** snake_move.c
** File description:
** snake_move
*/

#include "../../../Include/my.h"

void move_snake(rpg_t *rpg, sfVector2f player_pos, sfVector2f snake_pos, int i)
{
    if (snake_pos.x > player_pos.x - 32) {
        snake_pos.x -= 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->snake[i]->snake,
        rpg->snake[i]->snake_tx, sfFalse);
    }
    if (snake_pos.x < player_pos.x - 32) {
        snake_pos.x += 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->snake[i]->snake,
        rpg->snake[i]->snake_right, sfFalse);
    }
    if (snake_pos.y > player_pos.y - 30)
        snake_pos.y -= 2;
    if (snake_pos.y < player_pos.y - 30)
        snake_pos.y += 2;
    sfSprite_setPosition(rpg->snake[i]->snake, snake_pos);
}

void move_to_player_static3(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(rpg->snake[i]->zone);
    sfVector2f snake_pos = sfSprite_getPosition(rpg->snake[i]->snake);
    sfVector2f player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL))
        move_snake(rpg, player_pos, snake_pos, i);
}

void move_to_player_snake(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; i <= 13; i++) {
        sfCircleShape_setPosition(rpg->snake[i]->zone,
        sfSprite_getPosition(rpg->snake[i]->snake));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->snake[i]->seconds > 0.03) {
            move_to_player_static3(rpg, i);
            sfClock_restart(rpg->snake[i]->clock);
        }
    }
}

void move_to_player_snake_dg(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 14; rpg->snake[i] != NULL; i++) {
        sfCircleShape_setPosition(rpg->snake[i]->zone,
        sfSprite_getPosition(rpg->snake[i]->snake));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->snake[i]->seconds > 0.03) {
            move_to_player_static3(rpg, i);
            sfClock_restart(rpg->snake[i]->clock);
        }
    }
}
