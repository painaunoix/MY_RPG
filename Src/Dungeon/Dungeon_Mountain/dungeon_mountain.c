/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//draw forest dungeon
void draw_dg_mountain(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_mountain->map, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_mountain->silver_key1, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_mountain->gold_key, NULL);
    for (int i = 0; rpg->dg->dg_mountain->door[i]; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->dg->dg_mountain->door[i]->door, NULL);
    }
    trigger_arena(rpg->dg->dg_mountain->arena->trigger,
    &rpg->dg->dg_mountain->arena->start_fight, rpg);
}

//init door in the water dungeon
static void setup_door_dg_m(rpg_t *rpg, int x, int y, char *file)
{
    static int nb = 0;

    rpg->dg->dg_mountain->door[nb] = malloc(sizeof(dg_door_for_t));
    rpg->dg->dg_mountain->door[nb]->door = create_sprite(
        (sfVector2f) {3.2, 3.2}, (sfVector2f) {x, y}, file);
    rpg->dg->dg_mountain->door[nb]->open = 0;
    rpg->dg->dg_mountain->door[nb + 1] = NULL;
    nb++;
}

//init all door in the forest dungeon
static void setup_all_door_dg_m(rpg_t *rpg)
{
    rpg->dg->dg_mountain->door = malloc(sizeof(dg_door_for_t *) * 4);
    setup_door_dg_m(rpg, 6528, 5982, DOOR_SILVER_L);
    setup_door_dg_m(rpg, 4377, 2757, DOOR_GOLD_L);
    setup_door_dg_m(rpg, 5838, 840, DOOR_GOLD_L);
    rpg->dg->dg_mountain->door[0]->door_img =
    sfImage_createFromFile(DG_FIRST_DOOR_M);
    rpg->dg->dg_mountain->door[1]->door_img =
    sfImage_createFromFile(DG_BOSS_DOOR_M);
    rpg->dg->dg_mountain->door[2]->door_img =
    sfImage_createFromFile(DG_END_DOOR_M);
}

//init all in forest dungeon
void init_dg_mountain(rpg_t *rpg)
{
    rpg->dg->dg_mountain = malloc(sizeof(dg_mountain_t));
    rpg->dg->dg_mountain->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, DUNGEON_M_MAP);
    rpg->dg->dg_mountain->red_map = sfImage_createFromFile(DUNGEON_M_RED);
    rpg->dg->dg_mountain->door_empty = texture(DOOR_EMPTY_L);
    rpg->dg->dg_mountain->door_silver = texture(DOOR_SILVER_L);
    rpg->dg->dg_mountain->door_gold = texture(DOOR_GOLD_L);
    rpg->dg->dg_mountain->key_rect = make_rect(8, 16);
    rpg->dg->dg_mountain->silver_key1 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {1332, 4569}, SILVER_KEY, rpg->dg->dg_mountain->key_rect);
    rpg->dg->dg_mountain->gold_key = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {6574, 6681}, GOLD_KEY, rpg->dg->dg_mountain->key_rect);
    rpg->dg->dg_mountain->gold_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {4421, 1171}, GOLD_KEY, rpg->dg->dg_mountain->key_rect);
    setup_all_door_dg_m(rpg);
    create_arena_mountain(rpg);
}

void draw_dog_wave(rpg_t *rpg)
{
    for (int i = 32; rpg->dog[i]; i++) {
        if (rpg->dog[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->dog[i]->dog, NULL);
        }
    }
}

void draw_dog_dg(rpg_t *rpg)
{
    for (int i = 8; i <= 31; i++) {
        if (rpg->dog[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->dog[i]->dog, NULL);
        }
    }
}

void dg_loop_mountain(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 4) {
        interact_with_gold_door(rpg, rpg->dg->dg_mountain->door[1]);
        interact_with_gold_door(rpg, rpg->dg->dg_mountain->door[2]);
        interact_with_silver_door(rpg, rpg->dg->dg_mountain->door[0]);
        interact_with_silver_key(rpg, rpg->dg->dg_mountain->silver_key1);
        interact_with_gold_key(rpg, rpg->dg->dg_mountain->gold_key);
    }
}
