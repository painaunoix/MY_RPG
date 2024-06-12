/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** attack ghost
*/

#include "../../../Include/my.h"

void knock_ghost(rpg_t *rpg, int i)
{
    rpg->ghost[i]->life -= rpg->player->atk;
    if (rpg->ghost[i]->life <= 0) {
        rpg->coin->coin += 1;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
        if (rpg->qts->ghost <= 4)
            rpg->qts->ghost++;
        if (rpg->qts->ghost == 5)
            rpg->coin->coin += 13;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->ghost[i]->ghost, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->ghost[i]->ghost, (sfVector2f) {-20, 0});
}

void change_ghost_texture(rpg_t *rpg, int i)
{
    if (sfSprite_getTexture(rpg->ghost[i]->ghost) ==
    rpg->ghost[i]->ghost_tx)
        sfSprite_setTexture(rpg->ghost[i]->ghost,
        rpg->ghost[i]->ghost_r_red, sfFalse);
    if (sfSprite_getTexture(rpg->ghost[i]->ghost) ==
    rpg->ghost[i]->ghost_right)
        sfSprite_setTexture(rpg->ghost[i]->ghost,
        rpg->ghost[i]->ghost_l_red, sfFalse);
}

void is_ghost_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect ghost;

    for (int i = 0; i <= 7; i++) {
        ghost = sfSprite_getGlobalBounds(rpg->ghost[i]->ghost);
        if (sfFloatRect_intersects(&ghost, &atk, NULL) &&
        rpg->ghost[i]->life > 0) {
            change_ghost_texture(rpg, i);
            knock_ghost(rpg, i);
        }
    }
}
