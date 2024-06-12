/*
** EPITECH PROJECT, 2024
** big_torch.c
** File description:
** big_torch
*/

#include "../../Include/my.h"

void draw_big_torch(rpg_t *rpg)
{
    for (int i = 0; i != 7; i++) {
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->b_torch->torch[i]->torch, NULL);
    }
}

void set_pos_big_torch(rpg_t *rpg)
{
    sfSprite_setPosition(rpg->b_torch->torch[0]->torch,
    (sfVector2f) {2367, 1980});
    sfSprite_setPosition(rpg->b_torch->torch[1]->torch,
    (sfVector2f) {3750, 1074});
    sfSprite_setPosition(rpg->b_torch->torch[2]->torch,
    (sfVector2f) {5790, 1737});
    sfSprite_setPosition(rpg->b_torch->torch[3]->torch,
    (sfVector2f) {6567, 3015});
    sfSprite_setPosition(rpg->b_torch->torch[4]->torch,
    (sfVector2f) {6138, 3474});
    sfSprite_setPosition(rpg->b_torch->torch[5]->torch,
    (sfVector2f) {4161, 3954});
    sfSprite_setPosition(rpg->b_torch->torch[6]->torch,
    (sfVector2f) {2922, 3228});
}

void interact_big_torch(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect door;

    for (int i = 0; i != 7; i++) {
        door = sfSprite_getGlobalBounds(rpg->b_torch->torch[i]->torch);
        if (sfFloatRect_intersects(&player, &door, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased && rpg->dg->in_dungeon == 0 &&
        is_in_frame(rpg, ITM_TORCH) == 0) {
            rpg->b_torch->torch[i]->state = 1;
            sfSprite_setTexture(rpg->b_torch->torch[i]->torch,
            rpg->b_torch->texture_on, sfTrue);
            sfSprite_setTextureRect(rpg->b_torch->torch[i]->torch,
            rpg->b_torch->torch_Rect);
        }
    }
}

void init_big_torch(rpg_t *rpg)
{
    rpg->b_torch = malloc(sizeof(big_torch_t));
    rpg->b_torch->torch_Rect = make_rect(444, 320);
    rpg->b_torch->texture_off = texture(TORCH_OFF);
    rpg->b_torch->texture_on = texture(TORCH_ON);
    rpg->b_torch->torch = malloc(sizeof(torch_sp_t) * 7);
    for (int i = 0; i != 7; i++) {
        rpg->b_torch->torch[i] = malloc(sizeof(torch_sp_t));
        rpg->b_torch->torch[i]->torch = create_sprite((sfVector2f)
        {0.28, 0.28}, (sfVector2f) {0, 0}, TORCH_OFF);
        rpg->b_torch->torch[i]->state = 0;
        rpg->b_torch->torch[i + 1] = NULL;
    }
    set_pos_big_torch(rpg);
}

void anim_b_torch(rpg_t *rpg)
{
    for (int i = 0; rpg->b_torch->torch[i] != NULL; i++) {
        if (rpg->b_torch->torch_Rect.left < 1280 - 320) {
            rpg->b_torch->torch_Rect.left += 320;
        } else {
            rpg->b_torch->torch_Rect.left = 0;
        }
        sfSprite_setTextureRect(rpg->b_torch->torch[i]->torch,
        rpg->b_torch->torch_Rect);
    }
}
