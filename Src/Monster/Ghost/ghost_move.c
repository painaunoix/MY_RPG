/*
** EPITECH PROJECT, 2024
** ghost_move.c
** File description:
** ghost_move
*/

#include "../../../Include/my.h"

void move_ghost(rpg_t *rpg, sfVector2f player_pos, sfVector2f ghost_pos, int i)
{
    if (ghost_pos.x > player_pos.x - 32) {
        ghost_pos.x -= 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->ghost[i]->ghost,
        rpg->ghost[i]->ghost_tx, sfFalse);
    }
    if (ghost_pos.x < player_pos.x - 32) {
        ghost_pos.x += 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->ghost[i]->ghost,
        rpg->ghost[i]->ghost_right, sfFalse);
    }
    if (ghost_pos.y > player_pos.y - 30)
        ghost_pos.y -= 2;
    if (ghost_pos.y < player_pos.y - 30)
        ghost_pos.y += 2;
    sfSprite_setPosition(rpg->ghost[i]->ghost, ghost_pos);
}

void move_to_player_static2(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(rpg->ghost[i]->zone);
    sfVector2f ghost_pos = sfSprite_getPosition(rpg->ghost[i]->ghost);
    sfVector2f player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL))
        move_ghost(rpg, player_pos, ghost_pos, i);
}

void move_to_player_ghost(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; i <= 7; i++) {
        sfCircleShape_setPosition(rpg->ghost[i]->zone,
        sfSprite_getPosition(rpg->ghost[i]->ghost));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->ghost[i]->seconds > 0.03) {
            move_to_player_static2(rpg, i);
            sfClock_restart(rpg->ghost[i]->clock);
        }
    }
}

void move_to_player_ghost_dg(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 8; rpg->ghost[i] != NULL; i++) {
        sfCircleShape_setPosition(rpg->ghost[i]->zone,
        sfSprite_getPosition(rpg->ghost[i]->ghost));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->ghost[i]->seconds > 0.03) {
            move_to_player_static2(rpg, i);
            sfClock_restart(rpg->ghost[i]->clock);
        }
    }
}
