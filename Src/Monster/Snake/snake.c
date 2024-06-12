/*
** EPITECH PROJECT, 2024
** snake.c
** File description:
** snake
*/

#include "../../../Include/my.h"

static void set_texture_snake(rpg_t *rpg, int i)
{
    rpg->snake[i]->snake_tx = sfTexture_createFromFile(SNAKE_LEFT, NULL);
    rpg->snake[i]->snake_right = sfTexture_createFromFile(SNAKE_RIGHT, NULL);
    rpg->snake[i]->snake_l_red = sfTexture_createFromFile(SNAKE_LEFT_R, NULL);
    rpg->snake[i]->snake_r_red =
    sfTexture_createFromFile(SNAKE_RIGHT_R, NULL);
}

sfSprite *create_snake(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {5, 5};
    sfVector2f center = {x, y};
    sfVector2f center2 = {140, 140};
    sfSprite *sprite;

    rpg->snake[i]->snake_Rect = make_rect(14, 32);
    rpg->snake[i]->life = 7;
    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    set_texture_snake(rpg, i);
    sfSprite_setTexture(sprite,
    sfTexture_createFromFile(SNAKE_LEFT, NULL), sfTrue);
    sfSprite_setTextureRect(sprite, rpg->snake[i]->snake_Rect);
    rpg->snake[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->snake[i]->zone, center2);
    sfCircleShape_setPosition(rpg->snake[i]->zone, center);
    sfCircleShape_setRadius(rpg->snake[i]->zone, 200);
    sfCircleShape_setFillColor(rpg->snake[i]->zone, sfTransparent);
    return sprite;
}

void start_create_snake(rpg_t *rpg, int x, int y, int i)
{
    rpg->snake[i] = malloc(sizeof(snake_t));
    rpg->snake[i]->snake = create_snake(rpg, x, y, i);
    rpg->snake[i]->seconds = 0;
    rpg->snake[i + 1] = NULL;
}

static void setup_snake_wave(rpg_t *rpg)
{
    start_create_snake(rpg, 6736, 3991, 34);
    start_create_snake(rpg, 4721, 3801, 35);
    start_create_snake(rpg, 4355, 3801, 36);
    start_create_snake(rpg, 3989, 3801, 37);
    start_create_snake(rpg, 3989, 2979, 38);
    start_create_snake(rpg, 4355, 2979, 39);
    start_create_snake(rpg, 4721, 2979, 40);
    start_create_snake(rpg, 3860, 3186, 41);
    start_create_snake(rpg, 3860, 3438, 42);
    start_create_snake(rpg, 3860, 3690, 43);
    start_create_snake(rpg, 4888, 3186, 44);
    start_create_snake(rpg, 4888, 3438, 45);
    start_create_snake(rpg, 4888, 3690, 46);
}

static void setup_snake_dg(rpg_t *rpg)
{
    start_create_snake(rpg, 4530, 5863, 15);
    start_create_snake(rpg, 4364, 4965, 16);
    start_create_snake(rpg, 4963, 5613, 17);
    start_create_snake(rpg, 3811, 5627, 18);
    start_create_snake(rpg, 2697, 5033, 19);
    start_create_snake(rpg, 3181, 5927, 20);
    start_create_snake(rpg, 2778, 6437, 21);
    start_create_snake(rpg, 2434, 5679, 22);
    start_create_snake(rpg, 1753, 5077, 23);
    start_create_snake(rpg, 1918, 4234, 24);
    start_create_snake(rpg, 1876, 3946, 25);
    start_create_snake(rpg, 1448, 4220, 26);
    start_create_snake(rpg, 1513, 3941, 27);
    start_create_snake(rpg, 5763, 4961, 28);
    start_create_snake(rpg, 6168, 5396, 29);
    start_create_snake(rpg, 6525, 4727, 30);
    start_create_snake(rpg, 6401, 3681, 31);
    start_create_snake(rpg, 6728, 3684, 32);
    start_create_snake(rpg, 6401, 4020, 33);
    setup_snake_wave(rpg);
}

void setup_snake(rpg_t *rpg)
{
    rpg->snake = malloc(sizeof(snake_t *) * 48);
    start_create_snake(rpg, 10565, 5160, 0);
    start_create_snake(rpg, 9899, 5250, 1);
    start_create_snake(rpg, 9707, 5666, 2);
    start_create_snake(rpg, 10574, 5745, 3);
    start_create_snake(rpg, 10232, 6175, 4);
    start_create_snake(rpg, 10164, 6799, 5);
    start_create_snake(rpg, 9802, 7254, 6);
    start_create_snake(rpg, 10653, 7233, 7);
    start_create_snake(rpg, 10417, 7653, 8);
    start_create_snake(rpg, 9949, 7905, 9);
    start_create_snake(rpg, 10042, 8460, 10);
    start_create_snake(rpg, 10705, 8229, 11);
    start_create_snake(rpg, 11469, 6764, 12);
    start_create_snake(rpg, 11979, 6176, 13);
    start_create_snake(rpg, 4259, 6210, 14);
    setup_snake_dg(rpg);
}

void draw_snake(rpg_t *rpg)
{
    for (int i = 0; i <= 13; i++) {
        if (rpg->snake[i]->life > 0) {
            sfRenderWindow_drawSprite(rpg->win->window,
            rpg->snake[i]->snake, NULL);
        }
    }
}

static void anim_snake_split(rpg_t *rpg, int i)
{
    if (rpg->snake[i]->snake_Rect.left < 256 - 32) {
        rpg->snake[i]->snake_Rect.left += 32;
    } else {
        rpg->snake[i]->snake_Rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->snake[i]->snake,
    rpg->snake[i]->snake_Rect);
    sfClock_restart(rpg->anim_monst->clock_snake);
}

void anim_snake(rpg_t *rpg)
{
    for (int i = 0; rpg->snake[i] != NULL; i++) {
        if (rpg->anim_monst->seconds_snake > 0.1) {
            anim_snake_split(rpg, i);
        }
    }
}
