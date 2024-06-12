/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** attack crab
*/

#include "../../../Include/my.h"

//knock crab when player hit it
void knock_crab(rpg_t *rpg, int i)
{
    rpg->crab[i]->life -= rpg->player->atk;
    if (rpg->crab[i]->life <= 0) {
        rpg->coin->coin += 100;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->crab[i]->crab, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->crab[i]->crab, (sfVector2f) {-20, 0});
}

//check if the crab is attack
void is_crab_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect crab;

    for (int i = 0; rpg->crab[i]; i++) {
        crab = sfSprite_getGlobalBounds(rpg->crab[i]->crab);
        if (sfFloatRect_intersects(&crab, &atk, NULL) &&
        rpg->crab[i]->life > 0) {
            sfSprite_setTexture(rpg->crab[i]->crab,
            rpg->crab[i]->crab_tx_red, sfFalse);
            knock_crab(rpg, i);
        }
    }
}
