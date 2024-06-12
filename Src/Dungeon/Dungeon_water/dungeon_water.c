/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

//draw forest dungeon
void draw_dg_water(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->dg->dg_water->map, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_water->silver_key1, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_water->silver_key2, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_water->gold_key, NULL);
    for (int i = 0; rpg->dg->dg_water->door[i]; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->dg->dg_water->door[i]->door, NULL);
    }
    trigger_arena(rpg->dg->dg_water->arena->trigger,
    &rpg->dg->dg_water->arena->start_fight, rpg);
}

//init door in the water dungeon
static void setup_door_dg_w(rpg_t *rpg, int x, int y, char *file)
{
    static int nb = 0;

    rpg->dg->dg_water->door[nb] = malloc(sizeof(dg_door_for_t));
    rpg->dg->dg_water->door[nb]->door = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {x, y}, file);
    rpg->dg->dg_water->door[nb]->open = 0;
    rpg->dg->dg_water->door[nb + 1] = NULL;
    nb++;
}

//init all door in the forest dungeon
static void setup_all_door_dg_w(rpg_t *rpg)
{
    rpg->dg->dg_water->door = malloc(sizeof(dg_door_for_t *) * 5);
    setup_door_dg_w(rpg, 1767, 5907, DOOR_SILVER_L);
    setup_door_dg_w(rpg, 1767, 5445, DOOR_SILVER_L);
    setup_door_dg_w(rpg, 4455, 3603, DOOR_GOLD_L);
    setup_door_dg_w(rpg, 4455, 1605, DOOR_GOLD_L);
    rpg->dg->dg_water->door[0]->door_img =
    sfImage_createFromFile(DG_FIRST_DOOR_W);
    rpg->dg->dg_water->door[1]->door_img =
    sfImage_createFromFile(DG_SECOND_DOOR_W);
    rpg->dg->dg_water->door[2]->door_img =
    sfImage_createFromFile(DG_BOSS_DOOR_W);
    rpg->dg->dg_water->door[3]->door_img =
    sfImage_createFromFile(DG_END_DOOR_W);
}

//init all in forest dungeon
void init_dg_water(rpg_t *rpg)
{
    rpg->dg->dg_water = malloc(sizeof(dg_water_t));
    rpg->dg->dg_water->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, DUNGEON_W_MAP);
    rpg->dg->dg_water->red_map = sfImage_createFromFile(DUNGEON_W_RED);
    rpg->dg->dg_water->door_empty = texture(DOOR_EMPTY_L);
    rpg->dg->dg_water->door_silver = texture(DOOR_SILVER_L);
    rpg->dg->dg_water->door_gold = texture(DOOR_GOLD_L);
    rpg->dg->dg_water->key_rect = make_rect(8, 16);
    rpg->dg->dg_water->silver_key1 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {2094, 4056}, SILVER_KEY, rpg->dg->dg_water->key_rect);
    rpg->dg->dg_water->silver_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {6214, 4952}, SILVER_KEY, rpg->dg->dg_water->key_rect);
    rpg->dg->dg_water->gold_key = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {1153, 4947}, GOLD_KEY, rpg->dg->dg_water->key_rect);
    rpg->dg->dg_water->gold_key2 = create_sprite_rect((sfVector2f) {4, 4},
        (sfVector2f) {4493, 2245}, GOLD_KEY, rpg->dg->dg_water->key_rect);
    setup_all_door_dg_w(rpg);
    create_arena_water(rpg);
}

void draw_slime_wave(rpg_t *rpg)
{
    for (int i = 31; rpg->slime[i]; i++) {
        if (rpg->slime[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->slime[i]->slime, NULL);
        }
    }
}

void draw_slime_dg(rpg_t *rpg)
{
    for (int i = 9; i <= 30; i++) {
        if (rpg->slime[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->slime[i]->slime, NULL);
        }
    }
}

void dg_loop_water(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 2) {
        interact_with_gold_door(rpg, rpg->dg->dg_water->door[2]);
        interact_with_gold_door(rpg, rpg->dg->dg_water->door[3]);
        interact_with_silver_door(rpg, rpg->dg->dg_water->door[0]);
        interact_with_silver_door(rpg, rpg->dg->dg_water->door[1]);
        interact_with_silver_key(rpg, rpg->dg->dg_water->silver_key1);
        interact_with_silver_key(rpg, rpg->dg->dg_water->silver_key2);
        interact_with_gold_key(rpg, rpg->dg->dg_water->gold_key);
    }
}
