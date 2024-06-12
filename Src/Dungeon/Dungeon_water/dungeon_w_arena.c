/*
** EPITECH PROJECT, 2024
** dungeon_w_arena.c
** File description:
** dungeon_w_arena
*/

#include "../../../Include/my.h"

static void replace_slime(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->slime[31]->slime, (sfVector2f) {3458, 3208});
    sfSprite_setPosition(rpg->slime[32]->slime, (sfVector2f) {3728, 3208});
    sfSprite_setPosition(rpg->slime[33]->slime, (sfVector2f) {3728, 2677});
    sfSprite_setPosition(rpg->slime[34]->slime, (sfVector2f) {3458, 2677});
    sfSprite_setPosition(rpg->slime[35]->slime, (sfVector2f) {3866, 2800});
    sfSprite_setPosition(rpg->slime[36]->slime, (sfVector2f) {3866, 3068});
    sfSprite_setPosition(rpg->slime[37]->slime, (sfVector2f) {3326, 2800});
    sfSprite_setPosition(rpg->slime[38]->slime, (sfVector2f) {3326, 3068});
    sfSprite_setPosition(rpg->slime[39]->slime, (sfVector2f) {4088, 2710});
    sfSprite_setPosition(rpg->slime[40]->slime, (sfVector2f) {4910, 2572});
    sfSprite_setPosition(rpg->slime[41]->slime, (sfVector2f) {4910, 2848});
    sfSprite_setPosition(rpg->slime[42]->slime, (sfVector2f) {4910, 2710});
}

static void regen_slime(rpg_t *rpg)
{
    for (int i = 31; rpg->slime[i]; i++) {
        if (rpg->slime[i]->life <= 0) {
            rpg->slime[i]->life = 5;
        }
    }
    replace_slime(rpg);
}

void reset_arena_water(rpg_t *rpg, int nb)
{
    for (int i = 31; rpg->slime[i]; i++) {
        if (rpg->slime[i]->life <= 0) {
            nb++;
        }
        if (nb == 12 && rpg->dg->dg_water->arena->wave == 1) {
            rpg->dg->dg_water->arena->start_fight = 0;
            rpg->dg->dg_water->arena->win = 1;
            return;
        }
    }
}

static void draw_end_water(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->chest[1]->chest_close, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_water->gold_key2, NULL);
    interact_with_gold_key(rpg, rpg->dg->dg_water->gold_key2);
}

void hud_arena_w(rpg_t *rpg, char *text)
{
    draw_slime_wave(rpg);
    reset_arena_water(rpg, 0);
    sfText_setPosition(rpg->dg->dg_water->arena->text,
    set_pos_mid_txt(rpg, rpg->dg->dg_water->arena->text, 800, -80));
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_water->arena->text, NULL);
    sfText_setPosition(rpg->dg->dg_water->arena->nb,
    set_pos_mid_txt(rpg, rpg->dg->dg_water->arena->nb, 800, 80));
    text = my_itos(rpg->dg->dg_water->arena->wave);
    sfText_setString(rpg->dg->dg_water->arena->nb, text);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_water->arena->nb, NULL);
}

void draw_hud_arena_water(rpg_t *rpg, int start, int end)
{
    char *text = NULL;

    if (start == 1 && end == 0) {
        hud_arena_w(rpg, text);
    }
    if (end == 1) {
        draw_end_water(rpg);
    }
}

void create_arena_water(rpg_t *rpg)
{
    rpg->dg->dg_water->arena = malloc(sizeof(dg_arena_t));
    rpg->dg->dg_water->arena->win = 0;
    rpg->dg->dg_water->arena->wave = 1;
    rpg->dg->dg_water->arena->start_fight = 0;
    rpg->dg->dg_water->arena->border = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, LOAD_BORDER);
    rpg->dg->dg_water->arena->box = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->dg->dg_water->arena->box,
    (sfVector2f) {360, 830});
    sfRectangleShape_setFillColor(rpg->dg->dg_water->arena->box, sfRed);
    sfRectangleShape_setSize(rpg->dg->dg_water->arena->box,
    (sfVector2f) {60, 60});
    rpg->dg->dg_water->arena->text = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "Wave");
    rpg->dg->dg_water->arena->nb = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "0");
    rpg->dg->dg_water->arena->trigger = create_rectangle(
        (sfVector2f) {115, 115}, (sfVector2f) {4470, 2685});
}
