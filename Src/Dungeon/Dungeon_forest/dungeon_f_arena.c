/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../../Include/my.h"

static void replace_ghost(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->ghost[25]->ghost, (sfVector2f) {3458, 3208});
    sfSprite_setPosition(rpg->ghost[26]->ghost, (sfVector2f) {3728, 3208});
    sfSprite_setPosition(rpg->ghost[27]->ghost, (sfVector2f) {3728, 2677});
    sfSprite_setPosition(rpg->ghost[28]->ghost, (sfVector2f) {3458, 2677});
    sfSprite_setPosition(rpg->ghost[29]->ghost, (sfVector2f) {3866, 2800});
    sfSprite_setPosition(rpg->ghost[30]->ghost, (sfVector2f) {3866, 3068});
    sfSprite_setPosition(rpg->ghost[31]->ghost, (sfVector2f) {3326, 2800});
    sfSprite_setPosition(rpg->ghost[32]->ghost, (sfVector2f) {3326, 3068});
}

static void regen_ghost(rpg_t *rpg)
{
    for (int i = 25; rpg->ghost[i]; i++) {
        if (rpg->ghost[i]->life <= 0) {
            rpg->ghost[i]->life = 5;
        }
    }
    replace_ghost(rpg);
}

void reset_arena_forest(rpg_t *rpg, int nb)
{
    for (int i = 25; rpg->ghost[i]; i++) {
        if (rpg->ghost[i]->life <= 0) {
            nb++;
        }
        if (nb == 8 && rpg->dg->dg_forest->arena->wave == 1) {
            rpg->dg->dg_forest->arena->wave = 2;
            regen_ghost(rpg);
            return;
        }
        if (nb == 8 && rpg->dg->dg_forest->arena->wave == 2) {
            rpg->dg->dg_forest->arena->wave = 3;
            regen_ghost(rpg);
            return;
        }
        if (nb == 8 && rpg->dg->dg_forest->arena->wave == 3) {
            rpg->dg->dg_forest->arena->start_fight = 0;
            rpg->dg->dg_forest->arena->win = 1;
            return;
        }
    }
}

static void draw_end_forest(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->chest[5]->chest_close, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->dg->dg_forest->gold_key2, NULL);
    interact_with_gold_key(rpg, rpg->dg->dg_forest->gold_key2);
}

void hud_arena_f(rpg_t *rpg, char *text)
{
    draw_ghost_wave(rpg);
    reset_arena_forest(rpg, 0);
    sfText_setPosition(rpg->dg->dg_forest->arena->text,
    set_pos_mid_txt(rpg, rpg->dg->dg_forest->arena->text, 800, -80));
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_forest->arena->text, NULL);
    sfText_setPosition(rpg->dg->dg_forest->arena->nb,
    set_pos_mid_txt(rpg, rpg->dg->dg_forest->arena->nb, 800, 80));
    text = my_itos(rpg->dg->dg_forest->arena->wave);
    sfText_setString(rpg->dg->dg_forest->arena->nb, text);
    sfRenderWindow_drawText(rpg->win->window,
    rpg->dg->dg_forest->arena->nb, NULL);
}

void draw_hud_arena_forest(rpg_t *rpg, int start, int end)
{
    char *text = NULL;

    if (start == 1 && end == 0) {
        hud_arena_f(rpg, text);
    }
    if (end == 1) {
        draw_end_forest(rpg);
    }
}

void trigger_arena(sfRectangleShape *rect, int *start, rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect trigger = sfRectangleShape_getGlobalBounds(rect);

    if (sfFloatRect_intersects(&player, &trigger, NULL) && *start == 0) {
        *start = 1;
    }
}

void create_arena_forest(rpg_t *rpg)
{
    rpg->dg->dg_forest->arena = malloc(sizeof(dg_arena_t));
    rpg->dg->dg_forest->arena->win = 0;
    rpg->dg->dg_forest->arena->wave = 1;
    rpg->dg->dg_forest->arena->start_fight = 0;
    rpg->dg->dg_forest->arena->border = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, LOAD_BORDER);
    rpg->dg->dg_forest->arena->box = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->dg->dg_forest->arena->box,
    (sfVector2f) {360, 830});
    sfRectangleShape_setFillColor(rpg->dg->dg_forest->arena->box, sfRed);
    sfRectangleShape_setSize(rpg->dg->dg_forest->arena->box,
    (sfVector2f) {60, 60});
    rpg->dg->dg_forest->arena->text = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "Wave");
    rpg->dg->dg_forest->arena->nb = create_texte(50,
    (sfVector2f) {0, 0}, sfWhite, "0");
    rpg->dg->dg_forest->arena->trigger = create_rectangle(
        (sfVector2f) {115, 115}, (sfVector2f) {3590, 3045});
}
