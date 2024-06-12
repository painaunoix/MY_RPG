/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//draw forest dungeon
void draw_dg_forest(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->dg->dg_forest->map, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_forest->silver_key1, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_forest->silver_key2, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_forest->gold_key, NULL);
    for (int i = 0; rpg->dg->dg_forest->door[i]; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->dg->dg_forest->door[i]->door, NULL);
    }
    trigger_arena(rpg->dg->dg_forest->arena->trigger,
    &rpg->dg->dg_forest->arena->start_fight, rpg);
}

//init door in the forest dungeon
static void setup_door_dg_f(rpg_t *rpg, int x, int y, char *file)
{
    static int nb = 0;

    rpg->dg->dg_forest->door[nb] = malloc(sizeof(dg_door_for_t));
    rpg->dg->dg_forest->door[nb]->door = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {x, y}, file);
    rpg->dg->dg_forest->door[nb]->open = 0;
    rpg->dg->dg_forest->door[nb + 1] = NULL;
    nb++;
}

//init all door in the forest dungeon
static void setup_all_door_dg_f(rpg_t *rpg)
{
    rpg->dg->dg_forest->door = malloc(sizeof(dg_door_for_t *) * 9);
    setup_door_dg_f(rpg, 3993, 5682, DOOR_EMPTY);
    setup_door_dg_f(rpg, 3148, 4992, DOOR_EMPTY);
    setup_door_dg_f(rpg, 4683, 5145, DOOR_SILVER);
    setup_door_dg_f(rpg, 5298, 4839, DOOR_SILVER);
    setup_door_dg_f(rpg, 3609, 4608, DOOR_EMPTY);
    setup_door_dg_f(rpg, 3609, 3993, DOOR_GOLD);
    setup_door_dg_f(rpg, 3609, 1152, DOOR_EMPTY);
    setup_door_dg_f(rpg, 3609, 2073, DOOR_GOLD);
    rpg->dg->dg_forest->door[2]->door_img =
    sfImage_createFromFile(DG_FIRST_DOOR);
    rpg->dg->dg_forest->door[3]->door_img =
    sfImage_createFromFile(DG_SECOND_DOOR);
    rpg->dg->dg_forest->door[5]->door_img =
    sfImage_createFromFile(DG_BOSS_DOOR);
    rpg->dg->dg_forest->door[7]->door_img =
    sfImage_createFromFile(DG_END_DOOR);
}

//init all in forest dungeon
void init_dg_forest(rpg_t *rpg)
{
    rpg->dg->dg_forest = malloc(sizeof(dg_forest_t));
    rpg->dg->dg_forest->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, DUNGEON_F_MAP);
    rpg->dg->dg_forest->red_map = sfImage_createFromFile(DUNGEON_F_RED);
    rpg->dg->dg_forest->door_empty = texture(DOOR_EMPTY);
    rpg->dg->dg_forest->door_silver = texture(DOOR_SILVER);
    rpg->dg->dg_forest->door_gold = texture(DOOR_GOLD);
    rpg->dg->dg_forest->key_rect = make_rect(8, 16);
    rpg->dg->dg_forest->silver_key1 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {2520, 5070}, SILVER_KEY, rpg->dg->dg_forest->key_rect);
    rpg->dg->dg_forest->silver_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {5290, 5330}, SILVER_KEY, rpg->dg->dg_forest->key_rect);
    rpg->dg->dg_forest->gold_key = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {5260, 4080}, GOLD_KEY, rpg->dg->dg_forest->key_rect);
    rpg->dg->dg_forest->gold_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {3560, 2500}, GOLD_KEY, rpg->dg->dg_forest->key_rect);
    setup_all_door_dg_f(rpg);
    create_arena_forest(rpg);
}

void draw_ghost_dg(rpg_t *rpg)
{
    for (int i = 8; i <= 24; i++) {
        if (rpg->ghost[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->ghost[i]->ghost, NULL);
        }
    }
}

void draw_ghost_wave(rpg_t *rpg)
{
    for (int i = 25; rpg->ghost[i]; i++) {
        if (rpg->ghost[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->ghost[i]->ghost, NULL);
        }
    }
}
