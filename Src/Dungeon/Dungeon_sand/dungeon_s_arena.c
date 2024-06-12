/*
** EPITECH PROJECT, 2024
** dungeon_s_arena.c
** File description:
** dungeon_s_arena
*/

#include "../../../Include/my.h"

static void replace_snake(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->snake[35]->snake, (sfVector2f) {3458, 3208});
    sfSprite_setPosition(rpg->snake[36]->snake, (sfVector2f) {3728, 3208});
    sfSprite_setPosition(rpg->snake[37]->snake, (sfVector2f) {3728, 2677});
    sfSprite_setPosition(rpg->snake[38]->snake, (sfVector2f) {3458, 2677});
    sfSprite_setPosition(rpg->snake[39]->snake, (sfVector2f) {3866, 2800});
    sfSprite_setPosition(rpg->snake[40]->snake, (sfVector2f) {3866, 3068});
    sfSprite_setPosition(rpg->snake[41]->snake, (sfVector2f) {3326, 2800});
    sfSprite_setPosition(rpg->snake[42]->snake, (sfVector2f) {3326, 3068});
    sfSprite_setPosition(rpg->snake[43]->snake, (sfVector2f) {4088, 2710});
    sfSprite_setPosition(rpg->snake[44]->snake, (sfVector2f) {4910, 2572});
    sfSprite_setPosition(rpg->snake[45]->snake, (sfVector2f) {4910, 2848});
    sfSprite_setPosition(rpg->snake[46]->snake, (sfVector2f) {4910, 2710});
}

static void regen_snake(rpg_t *rpg)
{
    for (int i = 35; rpg->snake[i]; i++) {
        if (rpg->snake[i]->life <= 0) {
            rpg->snake[i]->life = 5;
        }
    }
    replace_snake(rpg);
}

void reset_arena_sand(rpg_t *rpg, int nb)
{
    for (int i = 35; rpg->snake[i]; i++) {
        if (rpg->snake[i]->life <= 0) {
            nb++;
        }
        if (nb == 12 && rpg->dg->dg_sand->arena->wave == 1) {
            rpg->dg->dg_sand->arena->start_fight = 0;
            rpg->dg->dg_sand->arena->win = 1;
            return;
        }
    }
}

static void draw_end_sand(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->chest[7]->chest_close, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_sand->gold_key2, NULL);
    interact_with_gold_key(rpg, rpg->dg->dg_sand->gold_key2);
}

void hud_arena_s(rpg_t *rpg, char *text)
{
    draw_snake_wave(rpg);
    reset_arena_sand(rpg, 0);
    sfText_setPosition(rpg->dg->dg_sand->arena->text,
    set_pos_mid_txt(rpg, rpg->dg->dg_sand->arena->text, 800, -80));
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_sand->arena->text, NULL);
    sfText_setPosition(rpg->dg->dg_sand->arena->nb,
    set_pos_mid_txt(rpg, rpg->dg->dg_sand->arena->nb, 800, 80));
    text = my_itos(rpg->dg->dg_sand->arena->wave);
    sfText_setString(rpg->dg->dg_sand->arena->nb, text);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_sand->arena->nb, NULL);
}

void draw_hud_arena_sand(rpg_t *rpg, int start, int end)
{
    char *text = NULL;

    if (start == 1 && end == 0) {
        hud_arena_s(rpg, text);
    }
    if (end == 1) {
        draw_end_sand(rpg);
    }
}

void create_arena_sand(rpg_t *rpg)
{
    rpg->dg->dg_sand->arena = malloc(sizeof(dg_arena_t));
    rpg->dg->dg_sand->arena->win = 0;
    rpg->dg->dg_sand->arena->wave = 1;
    rpg->dg->dg_sand->arena->start_fight = 0;
    rpg->dg->dg_sand->arena->border = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, LOAD_BORDER);
    rpg->dg->dg_sand->arena->box = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->dg->dg_sand->arena->box,
    (sfVector2f) {360, 830});
    sfRectangleShape_setFillColor(rpg->dg->dg_sand->arena->box, sfRed);
    sfRectangleShape_setSize(rpg->dg->dg_sand->arena->box,
    (sfVector2f) {60, 60});
    rpg->dg->dg_sand->arena->text = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "Wave");
    rpg->dg->dg_sand->arena->nb = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "0");
    rpg->dg->dg_sand->arena->trigger = create_rectangle(
        (sfVector2f) {115, 115}, (sfVector2f) {4395, 3380});
}
