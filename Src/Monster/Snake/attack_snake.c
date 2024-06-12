/*
** EPITECH PROJECT, 2024
** attack_snake.c
** File description:
** attack_snake
*/

#include "../../../Include/my.h"

void knock_snake(rpg_t *rpg, int i)
{
    rpg->snake[i]->life -= rpg->player->atk;
    if (rpg->snake[i]->life <= 0) {
        rpg->coin->coin += 2;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
        if (rpg->qts->snake <= 4)
            rpg->qts->snake++;
        if (rpg->qts->snake == 5)
            rpg->coin->coin += 10;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->snake[i]->snake, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->snake[i]->snake, (sfVector2f) {-20, 0});
}

void change_snake_texture(rpg_t *rpg, int i)
{
    if (sfSprite_getTexture(rpg->snake[i]->snake) ==
    rpg->snake[i]->snake_tx)
        sfSprite_setTexture(rpg->snake[i]->snake,
        rpg->snake[i]->snake_r_red, sfFalse);
    if (sfSprite_getTexture(rpg->snake[i]->snake) ==
    rpg->snake[i]->snake_right)
        sfSprite_setTexture(rpg->snake[i]->snake,
        rpg->snake[i]->snake_l_red, sfFalse);
}

void is_snake_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect snake;

    for (int i = 0; i <= 13; i++) {
        snake = sfSprite_getGlobalBounds(rpg->snake[i]->snake);
        if (sfFloatRect_intersects(&snake, &atk, NULL) &&
        rpg->snake[i]->life > 0) {
            change_snake_texture(rpg, i);
            knock_snake(rpg, i);
        }
    }
}
