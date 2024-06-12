/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

void move_to_player_static(rpg_t *rpg, int i)
{
    sfFloatRect zone_pos =
    sfCircleShape_getGlobalBounds(rpg->slime[i]->zone);
    sfVector2f slime_pos =
    sfSprite_getPosition(rpg->slime[i]->slime);
    sfVector2f player_pos =
    sfRectangleShape_getPosition(rpg->player->hitbox);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)) {
        if (slime_pos.x > player_pos.x)
            slime_pos.x--;
        if (slime_pos.x < player_pos.x)
            slime_pos.x++;
        if (slime_pos.y > player_pos.y)
            slime_pos.y--;
        if (slime_pos.y < player_pos.y)
            slime_pos.y++;
        sfSprite_setPosition(rpg->slime[i]->slime, slime_pos);
    }
}

void move_to_player_slime(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 0; i <= 7; i++) {
        sfCircleShape_setPosition(rpg->slime[i]->zone,
        sfSprite_getPosition(rpg->slime[i]->slime));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->slime[i]->seconds > 0.03) {
            move_to_player_static(rpg, i);
            sfClock_restart(rpg->slime[i]->clock);
        }
    }
}

void move_to_player_slime_dg(rpg_t *rpg)
{
    sfVector2f player_pos;

    for (int i = 8; rpg->slime[i]; i++) {
        sfCircleShape_setPosition(rpg->slime[i]->zone,
        sfSprite_getPosition(rpg->slime[i]->slime));
        player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
        player_pos.x += 60;
        player_pos.y += 10;
        if (rpg->slime[i]->seconds > 0.03) {
            move_to_player_static(rpg, i);
            sfClock_restart(rpg->slime[i]->clock);
        }
    }
}
