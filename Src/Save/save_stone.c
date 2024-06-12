/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** save stone
*/

#include "../../Include/my.h"

void player_save(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect stone;

    for (int i = 0; rpg->stone[i]; i++) {
        stone = sfRectangleShape_getGlobalBounds(rpg->stone[i]->rec);
        if (sfFloatRect_intersects(&player, &stone, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased) {
            save_game(rpg);
        }
    }
}

void change_pos_stone(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->stone[0]->rec,
    (sfVector2f) {5635, 6695});
    sfRectangleShape_setPosition(rpg->stone[1]->rec,
    (sfVector2f) {2945, 7340});
    sfRectangleShape_setPosition(rpg->stone[2]->rec,
    (sfVector2f) {5985, 5370});
    sfRectangleShape_setPosition(rpg->stone[3]->rec,
    (sfVector2f) {10185, 4885});
    sfRectangleShape_setPosition(rpg->stone[4]->rec,
    (sfVector2f) {5180, 8820});
    sfRectangleShape_setPosition(rpg->stone[5]->rec,
    (sfVector2f) {8795, 4635});
    sfRectangleShape_setPosition(rpg->stone[6]->rec,
    (sfVector2f) {1645, 4675});
    sfRectangleShape_setPosition(rpg->stone[7]->rec,
    (sfVector2f) {5235, 3835});
    sfRectangleShape_setPosition(rpg->stone[8]->rec,
    (sfVector2f) {8770, 8040});
    sfRectangleShape_setPosition(rpg->stone[9]->rec,
    (sfVector2f) {9570, 8290});
}

void init_save_tone(rpg_t *rpg)
{
    rpg->stone = malloc(sizeof(stone_t *) * 10 + sizeof(NULL));
    for (int i = 0; i != 10; i++) {
        rpg->stone[i] = malloc(sizeof(stone_t));
        rpg->stone[i]->rec = create_rectangle_shape((sfVector2f)
        {150, 150}, (sfVector2f) {0, 0}, SAVE);
        rpg->stone[i + 1] = NULL;
    }
    change_pos_stone(rpg);
}

void draw_save_stone(rpg_t *rpg)
{
    for (int i = 0; rpg->stone[i]; i++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->stone[i]->rec, NULL);
}
