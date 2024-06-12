/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** move grap
*/

#include "../../Include/my.h"

//check if the grap is able to touch a pillar
void check_coli_grap(rpg_t *rpg, sfFloatRect rope, sfFloatRect target, int i)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect zone = sfRectangleShape_getGlobalBounds(rpg->grap->zone);

    if (sfFloatRect_intersects(&rope, &target, NULL) &&
    sfKeyboard_isKeyPressed(sfKeyE) && rpg->grap->lunch == sfFalse &&
    sfFloatRect_intersects(&player, &target, NULL) == sfFalse &&
    is_in_frame(rpg, ITM_HOOK) == 0 && sfFloatRect_intersects(&player, &zone,
    NULL) == sfFalse && rpg->boat->in_boat == 0) {
        rpg->grap->lunch = sfTrue;
        rpg->grap->idx_target = i;
        rpg->grap->axis = rpg->player->player_axe;
    }
}

//move the player if the grap is on pillar
void grap_move(rpg_t *rpg, int i)
{
    sfFloatRect rope = sfRectangleShape_getGlobalBounds(rpg->grap->rope);
    sfFloatRect target = sfRectangleShape_getGlobalBounds
    (rpg->grap_pillar[i]->pillar);
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfVector2f pos = sfRectangleShape_getPosition(rpg->grap_pillar[i]->pillar);
    sfVector2f player_pos = sfSprite_getPosition(rpg->player->player);

    pos.x -= player.width / 2 + 25;
    check_coli_grap(rpg, rope, target, i);
    if (rpg->grap->lunch == sfTrue && player_pos.x != player.width
    / 2 + 25 && rpg->grap->axis == 2)
        sfSprite_move(rpg->player->player, (sfVector2f) {1, 0});
    if (rpg->grap->lunch == sfTrue && player_pos.x != player.width
    / 2 + 25 && rpg->grap->axis == 4)
        sfSprite_move(rpg->player->player, (sfVector2f) {-1, 0});
    if (sfFloatRect_intersects(&target, &player, NULL))
        rpg->grap->lunch = sfFalse;
}
