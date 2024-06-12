/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make dock
*/

#include "../../Include/my.h"

void init_dock_2(rpg_t *rpg)
{
    rpg->dock[4]->rec = create_rectangle((sfVector2f) {60, 100},
    (sfVector2f) {6800, 7785});
    rpg->dock[5]->rec = create_rectangle((sfVector2f) {60, 100},
    (sfVector2f) {5645, 9000});
    rpg->dock[6]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {7480, 7755});
    rpg->dock[7]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {7145, 5380});
    rpg->dock[4]->pos = (sfVector2f) {6620 - 100, 7785};
    rpg->dock[5]->pos = (sfVector2f) {5755, 9000};
    rpg->dock[6]->pos = (sfVector2f) {7480, 7600 - 100};
    rpg->dock[7]->pos = (sfVector2f) {7100, 5230};
    rpg->dock[8]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {3600, 1880});
    rpg->dock[9]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {3595, 1615});
    rpg->dock[8]->pos = (sfVector2f) {3530, 1710};
    rpg->dock[9]->pos = (sfVector2f) {3530, 1440};
}

void init_dock(rpg_t *rpg)
{
    rpg->dock = malloc(sizeof(dock_t) * 11);
    for (int i = 0; i != 10; i++) {
        rpg->dock[i] = malloc(sizeof(dock_t));
        rpg->dock[i + 1] = NULL;
    }
    rpg->dock[0]->rec = create_rectangle((sfVector2f) {60, 100},
    (sfVector2f) {6685, 7785});
    rpg->dock[1]->rec = create_rectangle((sfVector2f) {60, 100},
    (sfVector2f) {5645, 9000});
    rpg->dock[2]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {7480, 7655});
    rpg->dock[3]->rec = create_rectangle((sfVector2f) {100, 60},
    (sfVector2f) {7145, 5275});
    rpg->dock[0]->pos = (sfVector2f) {6760, 7780};
    rpg->dock[1]->pos = (sfVector2f) {5840, 9000};
    rpg->dock[2]->pos = (sfVector2f) {7430, 7760};
    rpg->dock[3]->pos = (sfVector2f) {7100, 5390};
    init_dock_2(rpg);
}

void is_dock_use_2(rpg_t *rpg, sfFloatRect dock, int i)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&player, &dock, NULL) &&
    rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
    sfEvtKeyReleased && is_in_frame(rpg, ITM_DUCK) == 0 && i == 8 &&
    rpg->dg->in_dungeon == 1) {
        sfSprite_setPosition(rpg->player->player, rpg->dock[i]->pos);
        rpg->boat->in_boat = 1;
    }
    if (sfFloatRect_intersects(&player, &dock, NULL) &&
    rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
    sfEvtKeyReleased && is_in_frame(rpg, ITM_DUCK) == 0 && i == 9 &&
    rpg->dg->in_dungeon == 1) {
        sfSprite_setPosition(rpg->player->player, rpg->dock[i]->pos);
        rpg->boat->in_boat = 0;
    }
}

void is_dock_use(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect dock;

    for (int i = 0; rpg->dock[i]; i++) {
        dock = sfRectangleShape_getGlobalBounds(rpg->dock[i]->rec);
        if (sfFloatRect_intersects(&player, &dock, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased && is_in_frame(rpg, ITM_DUCK) == 0 && i <= 3) {
            sfSprite_setPosition(rpg->player->player, rpg->dock[i]->pos);
            rpg->boat->in_boat = 1;
        }
        if (sfFloatRect_intersects(&player, &dock, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased && is_in_frame(rpg, ITM_DUCK) == 0 && i > 3 &&
        i <= 7) {
            sfSprite_setPosition(rpg->player->player, rpg->dock[i]->pos);
            rpg->boat->in_boat = 0;
        }
        is_dock_use_2(rpg, dock, i);
    }
}
