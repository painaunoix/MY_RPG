/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

void run_anim_b_torch(rpg_t *rpg)
{
    if (rpg->b_torch->seconds > 0.1) {
        anim_b_torch(rpg);
        sfClock_restart(rpg->b_torch->clock);
    }
}

//player animation
void anim_player(rpg_t *rpg)
{
    if (rpg->boat->in_boat == 0) {
        if (rpg->player->seconds > 0.08) {
            run_animation(rpg);
            attack_animation(rpg);
            sfClock_restart(rpg->player->clock);
        }
    }
}

//chest animation
void anim_chest(rpg_t *rpg)
{
    if (rpg->chest_opn->seconds > 0.1) {
        animation_open(rpg);
        sfClock_restart(rpg->chest_opn->clock);
    }
}

//key animation
void anim_key(rpg_t *rpg)
{
    if (rpg->dg->dg_forest->seconds_key > 0.15) {
        animation_key(rpg);
        sfClock_restart(rpg->dg->dg_forest->clock_key);
    }
}

//attack animation
static void anim_attack(rpg_t *rpg)
{
    if (rpg->attack->seconds > 0.2) {
        rpg->attack->attack = 0;
        for (int i = 0; rpg->slime[i]; i++)
            sfSprite_setTexture(rpg->slime[i]->slime,
            rpg->slime[i]->slime_tx, sfFalse);
        for (int i = 0; rpg->crab[i]; i++)
            sfSprite_setTexture(rpg->crab[i]->crab,
            rpg->crab[i]->crab_tx, sfFalse);
    }
}

//call animation function
void anim_all(rpg_t *rpg)
{
    anim_player(rpg);
    anim_chest(rpg);
    anim_attack(rpg);
    anim_slime(rpg);
    anim_ghost(rpg);
    anim_snake(rpg);
    anim_golem(rpg);
    anim_dog(rpg);
    anim_key(rpg);
    anim_crab(rpg);
    run_anim_b_torch(rpg);
    anim_trigger(rpg);
    anim_flame(rpg);
    if (rpg->boss->boss_atk == 0)
        anim_boss(rpg);
    if (rpg->boss->boss_atk == 1)
        anim_atk(rpg);
}
