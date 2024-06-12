/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** attack ghost
*/

#include "../../Include/my.h"

void proj_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect proj;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[6]);
    float second = sfTime_asSeconds(time);

    for (int i = 0; rpg->boss->proj[i]; i++) {
        proj = sfSprite_getGlobalBounds(rpg->boss->proj[i]->projectile);
        if (sfFloatRect_intersects(&player, &proj, NULL) && second > 1.5 &&
        rpg->boss->proj[i]->life > 0) {
            make_armor(rpg, 1, "proj", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[6]);
        }
    }
}

void boss_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect boss;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[5]);
    float second = sfTime_asSeconds(time);

    boss = sfRectangleShape_getGlobalBounds(rpg->boss->hitbox);
    if (sfFloatRect_intersects(&player, &boss, NULL) && second > 1.5 &&
    rpg->boss->life > 0) {
        make_armor(rpg, 3, "boss", 0);
        set_health(rpg);
        sfClock_restart(rpg->hit->dmg[5]);
    }
}
