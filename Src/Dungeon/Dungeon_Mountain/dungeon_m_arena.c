/*
** EPITECH PROJECT, 2024
** dungeon_m_arena.c
** File description:
** dungeon_m_arena
*/

#include "../../../Include/my.h"

static void replace_dog(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->dog[32]->dog, (sfVector2f) {3458, 3208});
    sfSprite_setPosition(rpg->dog[33]->dog, (sfVector2f) {3728, 3208});
    sfSprite_setPosition(rpg->dog[34]->dog, (sfVector2f) {3728, 2677});
    sfSprite_setPosition(rpg->dog[35]->dog, (sfVector2f) {3458, 2677});
    sfSprite_setPosition(rpg->dog[36]->dog, (sfVector2f) {3866, 2800});
    sfSprite_setPosition(rpg->dog[37]->dog, (sfVector2f) {3866, 3068});
    sfSprite_setPosition(rpg->dog[38]->dog, (sfVector2f) {3326, 2800});
    sfSprite_setPosition(rpg->dog[39]->dog, (sfVector2f) {3326, 3068});
    sfSprite_setPosition(rpg->dog[40]->dog, (sfVector2f) {4088, 2710});
    sfSprite_setPosition(rpg->dog[41]->dog, (sfVector2f) {4910, 2572});
    sfSprite_setPosition(rpg->dog[42]->dog, (sfVector2f) {4910, 2848});
    sfSprite_setPosition(rpg->dog[43]->dog, (sfVector2f) {4910, 2710});
}

static void regen_dog(rpg_t *rpg)
{
    for (int i = 32; rpg->dog[i]; i++) {
        if (rpg->dog[i]->life <= 0) {
            rpg->dog[i]->life = 5;
        }
    }
    replace_dog(rpg);
}

void reset_arena_mountain(rpg_t *rpg, int nb)
{
    for (int i = 32; rpg->dog[i]; i++) {
        if (rpg->dog[i]->life <= 0) {
            nb++;
        }
        if (nb == 12 && rpg->dg->dg_mountain->arena->wave == 1) {
            rpg->dg->dg_mountain->arena->start_fight = 0;
            rpg->dg->dg_mountain->arena->win = 1;
            return;
        }
    }
}

static void draw_end_mountain(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->chest[6]->chest_close, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_mountain->gold_key2, NULL);
    interact_with_gold_key(rpg, rpg->dg->dg_mountain->gold_key2);
}

void hud_arena_m(rpg_t *rpg, char *text)
{
    draw_dog_wave(rpg);
    reset_arena_mountain(rpg, 0);
    sfText_setPosition(rpg->dg->dg_mountain->arena->text,
    set_pos_mid_txt(rpg, rpg->dg->dg_mountain->arena->text, 800, -80));
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_mountain->arena->text, NULL);
    sfText_setPosition(rpg->dg->dg_mountain->arena->nb,
    set_pos_mid_txt(rpg, rpg->dg->dg_mountain->arena->nb, 800, 80));
    text = my_itos(rpg->dg->dg_mountain->arena->wave);
    sfText_setString(rpg->dg->dg_mountain->arena->nb, text);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_mountain->arena->nb, NULL);
}

void draw_hud_arena_mountain(rpg_t *rpg, int start, int end)
{
    char *text = NULL;

    if (start == 1 && end == 0) {
        hud_arena_m(rpg, text);
    }
    if (end == 1) {
        draw_end_mountain(rpg);
    }
}

void create_arena_mountain(rpg_t *rpg)
{
    rpg->dg->dg_mountain->arena = malloc(sizeof(dg_arena_t));
    rpg->dg->dg_mountain->arena->win = 0;
    rpg->dg->dg_mountain->arena->wave = 1;
    rpg->dg->dg_mountain->arena->start_fight = 0;
    rpg->dg->dg_mountain->arena->border = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, LOAD_BORDER);
    rpg->dg->dg_mountain->arena->box = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->dg->dg_mountain->arena->box,
    (sfVector2f) {360, 830});
    sfRectangleShape_setFillColor(rpg->dg->dg_mountain->arena->box, sfRed);
    sfRectangleShape_setSize(rpg->dg->dg_mountain->arena->box,
    (sfVector2f) {60, 60});
    rpg->dg->dg_mountain->arena->text = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "Wave");
    rpg->dg->dg_mountain->arena->nb = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "0");
    rpg->dg->dg_mountain->arena->trigger = create_rectangle(
        (sfVector2f) {115, 115}, (sfVector2f) {4410, 1430});
}
