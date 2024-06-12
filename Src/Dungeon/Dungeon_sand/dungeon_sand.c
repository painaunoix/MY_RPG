/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//draw forest dungeon
void draw_dg_sand(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->dg->dg_sand->map, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_sand->silver_key1, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_sand->gold_key, NULL);
    for (int i = 0; rpg->dg->dg_sand->door[i]; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->dg->dg_sand->door[i]->door, NULL);
    }
    trigger_arena(rpg->dg->dg_sand->arena->trigger,
    &rpg->dg->dg_sand->arena->start_fight, rpg);
}

//init door in the water dungeon
static void setup_door_dg_s(rpg_t *rpg, int x, int y, char *file)
{
    static int nb = 0;

    rpg->dg->dg_sand->door[nb] = malloc(sizeof(dg_door_for_t));
    rpg->dg->dg_sand->door[nb]->door = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {x, y}, file);
    rpg->dg->dg_sand->door[nb]->open = 0;
    rpg->dg->dg_sand->door[nb + 1] = NULL;
    nb++;
}

//init all door in the forest dungeon
static void setup_all_door_dg_s(rpg_t *rpg)
{
    rpg->dg->dg_sand->door = malloc(sizeof(dg_door_for_t *) * 5);
    setup_door_dg_s(rpg, 1689, 4521, DOOR_EMPTY_L);
    setup_door_dg_s(rpg, 6606, 4449, DOOR_SILVER_L);
    setup_door_dg_s(rpg, 4377, 4449, DOOR_GOLD_L);
    setup_door_dg_s(rpg, 4377, 2223, DOOR_GOLD_L);
    rpg->dg->dg_sand->door[1]->door_img =
    sfImage_createFromFile(DG_FIRST_DOOR_S);
    rpg->dg->dg_sand->door[2]->door_img =
    sfImage_createFromFile(DG_BOSS_DOOR_S);
    rpg->dg->dg_sand->door[3]->door_img =
    sfImage_createFromFile(DG_END_DOOR_S);
}

//init all in forest dungeon
void init_dg_sand(rpg_t *rpg)
{
    rpg->dg->dg_sand = malloc(sizeof(dg_sand_t));
    rpg->dg->dg_sand->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, DUNGEON_S_MAP);
    rpg->dg->dg_sand->red_map = sfImage_createFromFile(DUNGEON_S_RED);
    rpg->dg->dg_sand->door_empty = texture(DOOR_EMPTY_L);
    rpg->dg->dg_sand->door_silver = texture(DOOR_SILVER_L);
    rpg->dg->dg_sand->door_gold = texture(DOOR_GOLD_L);
    rpg->dg->dg_sand->key_rect = make_rect(8, 16);
    rpg->dg->dg_sand->silver_key1 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {1773, 4056}, SILVER_KEY, rpg->dg->dg_sand->key_rect);
    rpg->dg->dg_sand->gold_key = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {6625, 3780}, GOLD_KEY, rpg->dg->dg_sand->key_rect);
    rpg->dg->dg_sand->gold_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {4424, 2446}, GOLD_KEY, rpg->dg->dg_sand->key_rect);
    setup_all_door_dg_s(rpg);
    create_arena_sand(rpg);
}

void draw_snake_wave(rpg_t *rpg)
{
    for (int i = 35; rpg->snake[i]; i++) {
        if (rpg->snake[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->snake[i]->snake, NULL);
        }
    }
}

void draw_snake_dg(rpg_t *rpg)
{
    for (int i = 14; i <= 34; i++) {
        if (rpg->snake[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->snake[i]->snake, NULL);
        }
    }
}

void dg_loop_snake(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 3) {
        interact_with_gold_door(rpg, rpg->dg->dg_sand->door[2]);
        interact_with_gold_door(rpg, rpg->dg->dg_sand->door[3]);
        interact_with_silver_door(rpg, rpg->dg->dg_sand->door[1]);
        interact_with_silver_key(rpg, rpg->dg->dg_sand->silver_key1);
        interact_with_gold_key(rpg, rpg->dg->dg_sand->gold_key);
    }
}
