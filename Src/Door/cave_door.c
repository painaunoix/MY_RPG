/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make transition to cave and world map
*/

#include "../../Include/my.h"

void init_cave_door(rpg_t *rpg)
{
    rpg->cave[0]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {9735, 5945});
    rpg->cave[1]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {11820, 5750});
    rpg->cave[2]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {11845, 6820});
    rpg->cave[3]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {10580, 6870});
    rpg->cave[4]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {7020, 5045});
    rpg->cave[5]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {8510, 4550});
    rpg->cave[6]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {4125, 4295});
    rpg->cave[7]->door = create_rectangle((sfVector2f) {65, 115},
        (sfVector2f) {3475, 4445});
}

void init_cave_pos(rpg_t *rpg)
{
    rpg->cave[0]->coord = (sfVector2f) {11760, 5900};
    rpg->cave[1]->coord = (sfVector2f) {9660, 6110};
    rpg->cave[2]->coord = (sfVector2f) {10520, 7060};
    rpg->cave[3]->coord = (sfVector2f) {11783, 6973};
    rpg->cave[4]->coord = (sfVector2f) {8450, 4720};
    rpg->cave[5]->coord = (sfVector2f) {6934, 5225};
    rpg->cave[6]->coord = (sfVector2f) {3410, 4630};
    rpg->cave[7]->coord = (sfVector2f) {4055, 4431};
}

void is_cave_taken(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect door;

    for (int i = 0; i != 8; i++) {
        door = sfRectangleShape_getGlobalBounds(rpg->cave[i]->door);
        if (sfFloatRect_intersects(&player, &door, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased && rpg->dg->in_dungeon == 0) {
            sfSprite_setPosition(rpg->player->player, rpg->cave[i]->coord);
        }
    }
}

void init_door_cave(rpg_t *rpg)
{
    rpg->cave = malloc(sizeof(door_cave_t *) * 8);
    for (int i = 0; i != 8; i++)
        rpg->cave[i] = malloc(sizeof(door_cave_t));
    init_cave_door(rpg);
    init_cave_pos(rpg);
}
