/*
** EPITECH PROJECT, 2024
** dog_move.c
** File description:
** dog_move
*/

#include "../../../Include/my.h"

void move_dog(rpg_t *rpg, sfVector2f player_pos, sfVector2f dog_pos, int i)
{
    if (dog_pos.x > player_pos.x - 32) {
        dog_pos.x -= 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->dog[i]->dog,
        rpg->dog[i]->dog_tx, sfFalse);
    }
    if (dog_pos.x < player_pos.x - 32) {
        dog_pos.x += 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->dog[i]->dog,
        rpg->dog[i]->dog_right, sfFalse);
    }
    if (dog_pos.y > player_pos.y - 30)
        dog_pos.y -= 2;
    if (dog_pos.y < player_pos.y - 30)
        dog_pos.y += 2;
    sfSprite_setPosition(rpg->dog[i]->dog, dog_pos);
}

void move_to_player_static5(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(rpg->dog[i]->zone);
    sfVector2f dog_pos = sfSprite_getPosition(rpg->dog[i]->dog);
    sfVector2f player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL))
        move_dog(rpg, player_pos, dog_pos, i);
}

void move_to_player_dog(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; i <= 7; i++) {
        sfCircleShape_setPosition(rpg->dog[i]->zone,
        sfSprite_getPosition(rpg->dog[i]->dog));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->dog[i]->seconds > 0.03) {
            move_to_player_static5(rpg, i);
            sfClock_restart(rpg->dog[i]->clock);
        }
    }
}

void move_to_player_dog_dg(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 8; rpg->dog[i] != NULL; i++) {
        sfCircleShape_setPosition(rpg->dog[i]->zone,
        sfSprite_getPosition(rpg->dog[i]->dog));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->dog[i]->seconds > 0.03) {
            move_to_player_static5(rpg, i);
            sfClock_restart(rpg->dog[i]->clock);
        }
    }
}
