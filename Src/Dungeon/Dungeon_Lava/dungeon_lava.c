/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//draw forest dungeon
void draw_dg_lava(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_lava->map, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_lava->gold_key, NULL);
    for (int i = 0; rpg->dg->dg_lava->door[i]; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->dg->dg_lava->door[i]->door, NULL);
    }
}

//init door in the water dungeon
static void setup_door_dg_l(rpg_t *rpg, int x, int y, char *file)
{
    static int nb = 0;

    rpg->dg->dg_lava->door[nb] = malloc(sizeof(dg_door_for_t));
    rpg->dg->dg_lava->door[nb]->door = create_sprite(
        (sfVector2f) {3.2, 3.2}, (sfVector2f) {x, y}, file);
    rpg->dg->dg_lava->door[nb]->open = 0;
    rpg->dg->dg_lava->door[nb + 1] = NULL;
    nb++;
}

//init all door in the forest dungeon
static void setup_all_door_dg_l(rpg_t *rpg)
{
    rpg->dg->dg_lava->door = malloc(sizeof(dg_door_for_t *) * 2);
    setup_door_dg_l(rpg, 7449, 2529, DOOR_GOLD_L);
    rpg->dg->dg_lava->door[0]->door_img =
    sfImage_createFromFile(DG_BOSS_DOOR_L);
}

//init all in forest dungeon
void init_dg_lava(rpg_t *rpg)
{
    rpg->dg->dg_lava = malloc(sizeof(dg_lava_t));
    rpg->dg->dg_lava->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, DUNGEON_L_MAP);
    rpg->dg->dg_lava->red_map = sfImage_createFromFile(DUNGEON_L_RED);
    rpg->dg->dg_lava->door_empty = texture(DOOR_EMPTY_L);
    rpg->dg->dg_lava->door_silver = texture(DOOR_SILVER_L);
    rpg->dg->dg_lava->door_gold = texture(DOOR_GOLD_L);
    rpg->dg->dg_lava->key_rect = make_rect(8, 16);
    rpg->dg->dg_lava->gold_key = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {2509, 4209}, GOLD_KEY, rpg->dg->dg_lava->key_rect);
    setup_all_door_dg_l(rpg);
}

void dg_loop_lava(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 5) {
        interact_with_gold_door(rpg, rpg->dg->dg_lava->door[0]);
        interact_with_gold_key(rpg, rpg->dg->dg_lava->gold_key);
    }
}

void draw_golem_dg(rpg_t *rpg)
{
    for (int i = 7; rpg->golem[i]; i++) {
        if (rpg->golem[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->golem[i]->golem, NULL);
        }
    }
}
