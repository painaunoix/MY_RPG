/*
** EPITECH PROJECT, 2024
** init dungeon
** File description:
** file for init struct dungeon
*/

#include "../../Include/my.h"

//init struct dungeon
void init_dungeon(rpg_t *rpg)
{
    rpg->dg = malloc(sizeof(dg_t));
    rpg->dg->silver_key = 0;
    rpg->dg->gold_key = 0;
    rpg->dg->in_dungeon = 0;
    init_dg_forest(rpg);
}

void init_door_dg(rpg_t *rpg)
{
    rpg->door[0]->door = create_rectangle((sfVector2f) {65, 115},
    (sfVector2f) {3615, 1180});
    rpg->door[1]->door = create_rectangle((sfVector2f) {60, 80},
    (sfVector2f) {5475, 5170});
    rpg->door[2]->door = create_rectangle((sfVector2f) {65, 115},
    (sfVector2f) {5270, 830});
    rpg->door[3]->door = create_rectangle((sfVector2f) {60, 80},
    (sfVector2f) {7615, 7405});
    rpg->door[4]->door = create_rectangle((sfVector2f) {65, 115},
    (sfVector2f) {4430, 1495});
    rpg->door[5]->door = create_rectangle((sfVector2f) {60, 80},
    (sfVector2f) {10550, 8390});
    rpg->door[6]->door = create_rectangle((sfVector2f) {65, 115},
    (sfVector2f) {7040, 280});
    rpg->door[7]->door = create_rectangle((sfVector2f) {60, 80},
    (sfVector2f) {2185, 4640});
    rpg->door[8]->door = create_rectangle((sfVector2f) {60, 80},
    (sfVector2f) {4670, 2445});
}

void init_door_pos_dg(rpg_t *rpg)
{
    rpg->door[0]->coord = (sfVector2f) {5405, 5300};
    rpg->door[1]->coord = (sfVector2f) {3930, 6160};
    rpg->door[0]->state = 0;
    rpg->door[1]->state = 1;
    rpg->door[2]->coord = (sfVector2f) {7590, 7520};
    rpg->door[3]->coord = (sfVector2f) {4020, 6620};
    rpg->door[2]->state = 0;
    rpg->door[3]->state = 2;
    rpg->door[4]->coord = (sfVector2f) {10520, 8640};
    rpg->door[5]->coord = (sfVector2f) {4430, 7490};
    rpg->door[4]->state = 0;
    rpg->door[5]->state = 3;
    rpg->door[6]->coord = (sfVector2f) {2186, 4786};
    rpg->door[7]->coord = (sfVector2f) {4430, 7490};
    rpg->door[6]->state = 0;
    rpg->door[7]->state = 4;
    rpg->door[8]->coord = (sfVector2f) {4010, 8150};
    rpg->door[8]->state = 5;
}

//init door of dungeon
void init_door(rpg_t *rpg)
{
    rpg->door = malloc(sizeof(door_t *) * 10);
    for (int i = 0; i != 10; i++)
        rpg->door[i] = malloc(sizeof(door_t));
    for (int i = 0; i != 10; i++)
        rpg->door[i]->use = 0;
    init_door_dg(rpg);
    init_door_pos_dg(rpg);
}
