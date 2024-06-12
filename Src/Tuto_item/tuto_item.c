/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init tutao
*/

#include "../../Include/my.h"

void show_tuto_item(rpg_t *rpg)
{
    if (rpg->tuto_item->tuto_open == 1) {
        rpg->player->player_can_move = sfFalse;
        sfSprite_setPosition(rpg->tuto_item->tuto_item_sprite,
        set_pos_mid_sprite_off(rpg, rpg->tuto_item->tuto_item_sprite, 200, 0));
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->tuto_item->tuto_item_sprite, NULL);
        if (rpg->tuto_item->tuto_open == 1 &&
        sfKeyboard_isKeyPressed(sfKeyE)) {
            rpg->tuto_item->tuto_open = 0;
        }
    }
}

void init_tuto_item(rpg_t *rpg)
{
    rpg->tuto_item = malloc(sizeof(tuto_item_t));
    rpg->tuto_item->tuto_bomb = texture(TUTO_BOMB);
    rpg->tuto_item->tuto_torch = texture(TUTO_TORCH);
    rpg->tuto_item->tuto_hook = texture(TUTO_HOOK);
    rpg->tuto_item->tuto_dock = texture(TUTO_DOCK);
    rpg->tuto_item->tuto_item_sprite = create_sprite((sfVector2f) {0.8, 0.8},
    (sfVector2f) {0, 0}, TUTO_DOCK);
    rpg->tuto_item->tuto_open = 0;
}
