/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** attack ghost
*/

#include "../../Include/my.h"


void remake_heal_bar(rpg_t *rpg)
{
    int nb = 0;

    for (float i = 0; i < rpg->boss->life; i++)
        nb += 20;
    sfRectangleShape_setSize(rpg->boss->healt_bar, (sfVector2f) {nb, 60});
}

void knock_boss(rpg_t *rpg)
{
    rpg->boss->life -= rpg->player->atk;
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->boss->boss, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->boss->boss, (sfVector2f) {-20, 0});
}

void change_boss_texture(rpg_t *rpg)
{
    if (sfSprite_getTexture(rpg->boss->boss) ==
    rpg->boss->boss_left)
        sfSprite_setTexture(rpg->boss->boss,
        rpg->boss->boss_left_r, sfFalse);
    if (sfSprite_getTexture(rpg->boss->boss) ==
    rpg->boss->boss_right)
        sfSprite_setTexture(rpg->boss->boss,
        rpg->boss->boss_right_r, sfFalse);
}

void is_boss_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect boss;

    boss = sfSprite_getGlobalBounds(rpg->boss->boss);
    if (sfFloatRect_intersects(&boss, &atk, NULL) &&
        rpg->boss->life > 0 && rpg->boss->start_boss == 1) {
        change_boss_texture(rpg);
        knock_boss(rpg);
    }
    remake_heal_bar(rpg);
}

void is_prok_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect boss;

    for (int i = 0; rpg->boss->proj[i]; i++) {
        boss = sfSprite_getGlobalBounds(rpg->boss->proj[i]->projectile);
        if (sfFloatRect_intersects(&boss, &atk, NULL) &&
            rpg->boss->proj[i]->life > 0 && rpg->boss->start_boss == 1) {
            rpg->boss->proj[i]->life--;
        }
    }
}
