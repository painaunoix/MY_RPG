/*
** EPITECH PROJECT, 2024
** attack_golem.c
** File description:
** attack_golem
*/

#include "../../../Include/my.h"

void knock_golem(rpg_t *rpg, int i)
{
    rpg->golem[i]->life -= rpg->player->atk;
    if (rpg->golem[i]->life <= 0) {
        rpg->coin->coin += 3;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
        if (rpg->qts->golem <= 4)
            rpg->qts->golem++;
        if (rpg->qts->golem == 5)
            rpg->coin->coin += 20;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->golem[i]->golem, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->golem[i]->golem, (sfVector2f) {-20, 0});
}

void change_golem_texture(rpg_t *rpg, int i)
{
    if (sfSprite_getTexture(rpg->golem[i]->golem) ==
    rpg->golem[i]->golem_tx)
        sfSprite_setTexture(rpg->golem[i]->golem,
        rpg->golem[i]->golem_r_red, sfFalse);
    if (sfSprite_getTexture(rpg->golem[i]->golem) ==
    rpg->golem[i]->golem_right)
        sfSprite_setTexture(rpg->golem[i]->golem,
        rpg->golem[i]->golem_l_red, sfFalse);
}

void is_golem_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect golem;

    for (int i = 0; i <= 6; i++) {
        golem = sfSprite_getGlobalBounds(rpg->golem[i]->golem);
        if (sfFloatRect_intersects(&golem, &atk, NULL) &&
        rpg->golem[i]->life > 0) {
            change_golem_texture(rpg, i);
            knock_golem(rpg, i);
        }
    }
}
