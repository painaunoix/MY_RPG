/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//check if player interact with silver door
void interact_with_silver_door(rpg_t *rpg, dg_door_for_t *door)
{
    sfFloatRect zone_pos =
        sfSprite_getGlobalBounds(door->door);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL) &&
    rpg->dg->silver_key >= 1 && door->open == 0 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        door->open = 1;
        if (rpg->dg->in_dungeon == 1) {
            sfSprite_setTexture(door->door,
            rpg->dg->dg_forest->door_empty, sfFalse);
        } else {
            sfSprite_setTexture(door->door,
            rpg->dg->dg_water->door_empty, sfFalse);
        }
        rpg->dg->silver_key--;
    }
}

//check if player interact with gold door
void interact_with_gold_door(rpg_t *rpg, dg_door_for_t *door)
{
    sfFloatRect zone_pos =
        sfSprite_getGlobalBounds(door->door);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)
    && rpg->dg->gold_key >= 1 && door->open == 0 &&
    sfKeyboard_isKeyPressed(sfKeyE)) {
        door->open = 1;
        if (rpg->dg->in_dungeon == 1) {
            sfSprite_setTexture(door->door,
            rpg->dg->dg_forest->door_empty, sfFalse);
        } else {
            sfSprite_setTexture(door->door,
            rpg->dg->dg_water->door_empty, sfFalse);
        }
        rpg->dg->gold_key--;
    }
}

//check if player is on silver key
void interact_with_silver_key(rpg_t *rpg, sfSprite *silver_key)
{
    sfFloatRect zone_pos =
        sfSprite_getGlobalBounds(silver_key);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)) {
        sfSprite_setPosition(silver_key, (sfVector2f) {0, 0});
        rpg->dg->silver_key++;
    }
}

//check if player is on gold key
void interact_with_gold_key(rpg_t *rpg, sfSprite *gold_key)
{
    sfFloatRect zone_pos =
        sfSprite_getGlobalBounds(gold_key);
    sfFloatRect player_pos1 =
    sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)) {
        sfSprite_setPosition(gold_key, (sfVector2f) {0, 0});
        rpg->dg->gold_key++;
    }
}

//loop for the forest dungeon
void dg_loop(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 1) {
        interact_with_gold_door(rpg, rpg->dg->dg_forest->door[5]);
        interact_with_gold_door(rpg, rpg->dg->dg_forest->door[7]);
        interact_with_silver_door(rpg, rpg->dg->dg_forest->door[2]);
        interact_with_silver_door(rpg, rpg->dg->dg_forest->door[3]);
        interact_with_silver_key(rpg, rpg->dg->dg_forest->silver_key1);
        interact_with_silver_key(rpg, rpg->dg->dg_forest->silver_key2);
        interact_with_gold_key(rpg, rpg->dg->dg_forest->gold_key);
    }
}
