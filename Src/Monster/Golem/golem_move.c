/*
** EPITECH PROJECT, 2024
** golem_move.c
** File description:
** golem_move
*/

#include "../../../Include/my.h"

void move_golem(rpg_t *rpg, sfVector2f player_pos, sfVector2f golem_pos, int i)
{
    if (golem_pos.x > player_pos.x - 32) {
        golem_pos.x -= 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->golem[i]->golem,
        rpg->golem[i]->golem_tx, sfFalse);
    }
    if (golem_pos.x < player_pos.x - 32) {
        golem_pos.x += 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->golem[i]->golem,
        rpg->golem[i]->golem_right, sfFalse);
    }
    if (golem_pos.y > player_pos.y - 30)
        golem_pos.y -= 2;
    if (golem_pos.y < player_pos.y - 30)
        golem_pos.y += 2;
    sfSprite_setPosition(rpg->golem[i]->golem, golem_pos);
}

void move_to_player_static4(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(rpg->golem[i]->zone);
    sfVector2f golem_pos = sfSprite_getPosition(rpg->golem[i]->golem);
    sfVector2f player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfVector2f new_golem = {player_pos.x - 120, player_pos.y - 60};

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL))
        move_golem(rpg, new_golem, golem_pos, i);
}

void move_to_player_golem(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; i <= 5; i++) {
        sfCircleShape_setPosition(rpg->golem[i]->zone,
        sfSprite_getPosition(rpg->golem[i]->golem));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->golem[i]->seconds > 0.03) {
            move_to_player_static4(rpg, i);
            sfClock_restart(rpg->golem[i]->clock);
        }
    }
}

void move_to_player_golem_dg(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 6; rpg->golem[i] != NULL; i++) {
        sfCircleShape_setPosition(rpg->golem[i]->zone,
        sfSprite_getPosition(rpg->golem[i]->golem));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->golem[i]->seconds > 0.03) {
            move_to_player_static4(rpg, i);
            sfClock_restart(rpg->golem[i]->clock);
        }
    }
}
