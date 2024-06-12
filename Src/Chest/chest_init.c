/*
** EPITECH PROJECT, 2024
** chest init
** File description:
** file for init struct for chest
*/

#include "../../Include/my.h"

void close_chest(rpg_t *rpg, int i)
{
    if (rpg->chest_opn->open == 1 && sfKeyboard_isKeyPressed(sfKeyF)) {
        rpg->player->player_can_move = sfTrue;
        rpg->chest_opn->open = 0;
        if (i == 1 || i == 5 || i == 6 || i == 7) {
            rpg->tuto_item->tuto_open = 1;
        }
    }
}

//init all for when player open the chest
void init_chest_opn(rpg_t *rpg)
{
    rpg->chest_opn = malloc(sizeof(chest_opn_t));
    rpg->chest_opn->part_rect = make_rect(32, 32);
    rpg->chest_opn->particle = create_sprite_rect((sfVector2f) {12, 12},
        (sfVector2f) {0, 0}, CHEST_PRC, rpg->chest_opn->part_rect);
    sfSprite_setOrigin(rpg->chest_opn->particle, (sfVector2f) {16, 16});
    rpg->chest_opn->fond = create_sprite((sfVector2f) {1, 1},
        (sfVector2f) {0, 0}, CHEST_FOND);
    sfSprite_setOrigin(rpg->chest_opn->fond, (sfVector2f) {960, 540});
    rpg->chest_opn->item_name = create_texte(100, (sfVector2f) {0, 0},
    sfWhite, "Fortified Axe");
    rpg->chest_opn->item = create_sprite((sfVector2f) {5, 5},
        (sfVector2f) {0, 0}, ITM_AXE);
    sfSprite_setOrigin(rpg->chest_opn->item, (sfVector2f) {16, 16});
    rpg->chest_opn->quit_text = create_texte(60, (sfVector2f) {0, 0},
    sfWhite, "Press   F   to  close");
    rpg->chest_opn->open = 0;
    rpg->chest_opn->seconds = 0;
}

//init struct chest
void init_chest(rpg_t *rpg)
{
    rpg->chest = malloc(sizeof(chest_t) * 9);
    start_chest(rpg, 3541, 9052, 0);
    start_chest(rpg, 4507, 2692, 1);
    start_chest(rpg, 3200, 8800, 2);
    start_chest(rpg, 3300, 8800, 3);
    start_chest(rpg, 3400, 8800, 4);
    start_chest(rpg, 3626, 3055, 5);
    start_chest(rpg, 4434, 1495, 6);
    start_chest(rpg, 4435, 3415, 7);
}
