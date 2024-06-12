/*
** EPITECH PROJECT, 2024
** boat_move.c
** File description:
** movement for boat
*/

#include "../../Include/my.h"

void trigger_end_game(rpg_t *rpg)
{
    sfFloatRect trigger = sfSprite_getGlobalBounds(rpg->boss->trigger_end);
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&trigger, &player, NULL) &&
    rpg->boss->life <= 0 && rpg->boss->end_t == 0) {
        rpg->boss->end_t = 1;
    }
}

void init_end(rpg_t *rpg)
{
    rpg->boss->end_t = 0;
    rpg->boss->trigger_rect = make_rect(32, 32);
    rpg->boss->trigger_end = create_sprite_rect((sfVector2f) {3, 3},
    (sfVector2f) {7479, 1413}, CHEST_PRC, rpg->boss->trigger_rect);
    rpg->boss->ending = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, END);
}

void move_proj(rpg_t *rpg, sfVector2f player_pos,
    sfVector2f golem_pos, sfSprite *proj)
{
    if (golem_pos.x > player_pos.x - 32)
        golem_pos.x -= 2;
    if (golem_pos.x < player_pos.x - 32)
        golem_pos.x += 2;
    if (golem_pos.y > player_pos.y - 30)
        golem_pos.y -= 2;
    if (golem_pos.y < player_pos.y - 30)
        golem_pos.y += 2;
    sfSprite_setPosition(proj, golem_pos);
}

void move_to_player_static_proj(rpg_t *rpg, sfVector2f player_pos,
    sfCircleShape *zone, sfSprite *proj)
{
    sfVector2f golem_pos = sfSprite_getPosition(proj);
    sfVector2f new_golem = {player_pos.x - 20, player_pos.y - 20};
    sfFloatRect zone_pos = sfCircleShape_getGlobalBounds(zone);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL) &&
    rpg->boss->start_boss == 1)
        move_proj(rpg, new_golem, golem_pos, proj);
}

void move_to_player_proj(rpg_t *rpg, sfVector2f player_pos)
{
    for (int i = 0; rpg->boss->proj[i]; i++) {
        move_to_player_static_proj(rpg, player_pos,
        rpg->boss->proj[i]->zone, rpg->boss->proj[i]->projectile);
    }
}
