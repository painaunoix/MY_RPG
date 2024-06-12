/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make transition to dungeon and world map
*/

#include "../../Include/my.h"

void door_dg(rpg_t *rpg, int i)
{
    if (i == 0 && rpg->dg->in_dungeon == 1) {
        rpg->dg->in_dungeon = rpg->door[i]->state;
        sfSprite_setPosition(rpg->player->player, rpg->door[i]->coord);
        rpg->door[1]->use = 1;
    }
    if (i == 2 && rpg->dg->in_dungeon == 2) {
        rpg->dg->in_dungeon = rpg->door[i]->state;
        sfSprite_setPosition(rpg->player->player, rpg->door[i]->coord);
        rpg->door[3]->use = 1;
    }
    if (i == 4 && rpg->dg->in_dungeon == 3) {
        rpg->dg->in_dungeon = rpg->door[i]->state;
        sfSprite_setPosition(rpg->player->player, rpg->door[i]->coord);
        rpg->door[5]->use = 1;
    }
    if (i == 6 && rpg->dg->in_dungeon == 4) {
        rpg->dg->in_dungeon = rpg->door[i]->state;
        sfSprite_setPosition(rpg->player->player, rpg->door[i]->coord);
        rpg->door[7]->use = 1;
    }
}

void door_map(rpg_t *rpg, int i)
{
    if ((i == 1 || i == 3 || i == 5 || i == 7 || i == 8)
    && rpg->dg->in_dungeon == 0 && rpg->door[i]->use == 0) {
        rpg->dg->in_dungeon = rpg->door[i]->state;
        sfSprite_setPosition(rpg->player->player, rpg->door[i]->coord);
    }
    door_dg(rpg, i);
}

//check if the user want to use a dungeon door
void is_door_taken(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect door;

    for (int i = 0; i != 9; i++) {
        door = sfRectangleShape_getGlobalBounds(rpg->door[i]->door);
        if (sfFloatRect_intersects(&player, &door, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased) {
            door_map(rpg, i);
        }
    }
}
