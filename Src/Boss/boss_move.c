/*
** EPITECH PROJECT, 2024
** boat_move.c
** File description:
** movement for boat
*/

#include "../../Include/my.h"

void move_boss(rpg_t *rpg, sfVector2f player_pos, sfVector2f golem_pos)
{
    if (golem_pos.x > player_pos.x - 32) {
        golem_pos.x -= 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->boss->boss,
        rpg->boss->boss_left, sfFalse);
    }
    if (golem_pos.x < player_pos.x - 32) {
        golem_pos.x += 2;
        if (rpg->attack->attack == 0)
        sfSprite_setTexture(rpg->boss->boss,
        rpg->boss->boss_right, sfFalse);
    }
    if (golem_pos.y > player_pos.y - 30)
        golem_pos.y -= 2;
    if (golem_pos.y < player_pos.y - 30)
        golem_pos.y += 2;
    sfSprite_setPosition(rpg->boss->boss, golem_pos);
}

void move_to_player_static_boss(rpg_t *rpg, sfVector2f player_pos)
{
    sfVector2f golem_pos = sfSprite_getPosition(rpg->boss->boss);
    sfVector2f new_golem = {player_pos.x - 200, player_pos.y - 200};
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(rpg->boss->zone);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL))
        move_boss(rpg, new_golem, golem_pos);
}

void move_to_player_boss(rpg_t *rpg, sfVector2f player_pos)
{
    if (is_second(rpg->boss->clock_move, 0.005) == 1 &&
    rpg->boss->start_boss == 1) {
        move_to_player_static_boss(rpg, player_pos);
    }
}
