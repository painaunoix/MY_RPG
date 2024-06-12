/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** attack ghost
*/

#include "../../Include/my.h"

void draw_end(rpg_t *rpg)
{
    if (rpg->boss->life <= 0)
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->boss->trigger_end, NULL);
    if (rpg->boss->end_t == 1) {
        sfSprite_setPosition(rpg->boss->ending,
        set_pos_mid_sprite_off(rpg, rpg->boss->ending, 0, 0));
        sfRenderWindow_drawSprite(rpg->win->window, rpg->boss->ending, NULL);
    }
}

int anim_trigger(rpg_t *rpg)
{
    if (is_second(rpg->boss->clock_trigger, 0.1) == 1) {
        if (rpg->boss->trigger_rect.left < 128 - 32) {
            rpg->boss->trigger_rect.left += 32;
        } else {
            rpg->boss->trigger_rect.left = 0;
        }
    }
    sfSprite_setTextureRect(rpg->boss->trigger_end,
        rpg->boss->trigger_rect);
}

int anim_flame(rpg_t *rpg)
{
    if (is_second(rpg->boss->clock_attack, 0.05) == 1) {
        if (rpg->boss->flame_rect.left < 960 - 32) {
            rpg->boss->flame_rect.left += 32;
        } else {
            rpg->boss->flame_rect.left = 0;
        }
    }
    for (int i = 0; rpg->boss->proj[i]; i++) {
        sfCircleShape_setPosition(rpg->boss->proj[i]->zone,
        sfSprite_getPosition(rpg->boss->proj[i]->projectile));
        sfSprite_setTextureRect(rpg->boss->proj[i]->projectile,
            rpg->boss->flame_rect);
    }
}

int anim_boss(rpg_t *rpg)
{
    if (is_second(rpg->boss->clock, 0.05) == 1) {
        if (rpg->boss->boss_rect.left < 4000 - 500) {
            rpg->boss->boss_rect.left += 500;
        } else {
            rpg->boss->boss_rect.left = 0;
        }
    }
    sfCircleShape_setPosition(rpg->boss->zone,
    sfSprite_getPosition(rpg->boss->boss));
    sfSprite_setTextureRect(rpg->boss->boss,
        rpg->boss->boss_rect);
}

int anim_atk(rpg_t *rpg)
{
    if (is_second(rpg->boss->clock_start_atk_anim, 0.1) == 1) {
        if (rpg->boss->boss_rect.left < 6500 - 500) {
            rpg->boss->boss_rect.left += 500;
        } else {
            rpg->boss->boss_rect.left = 0;
            rpg->boss->boss_atk = 0;
            sfSprite_setTexture(rpg->boss->boss,
            rpg->boss->boss_left, sfFalse);
        }
    }
    sfSprite_setTextureRect(rpg->boss->boss,
        rpg->boss->boss_rect);
}
