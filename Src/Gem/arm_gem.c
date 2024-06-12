/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** make stg gem
*/

#include "../../Include/my.h"

void draw_buff(rpg_t *rpg)
{
    if (rpg->gem->act_arm == sfTrue) {
        sfSprite_setPosition(rpg->gem->sp_arm, set_pos_mid_sprite_off(rpg,
        rpg->gem->sp_arm, 920, -800));
        sfRenderWindow_drawSprite(rpg->win->window, rpg->gem->sp_arm, NULL);
    }
    if (rpg->gem->act_spd == sfTrue) {
        sfSprite_setPosition(rpg->gem->sp_spd, set_pos_mid_sprite_off(rpg,
        rpg->gem->sp_spd, 920, -700));
        sfRenderWindow_drawSprite(rpg->win->window, rpg->gem->sp_spd, NULL);
    }
    if (rpg->gem->act_stg == sfTrue) {
        sfSprite_setPosition(rpg->gem->sp_stg, set_pos_mid_sprite_off(rpg,
        rpg->gem->sp_stg, 920, -600));
        sfRenderWindow_drawSprite(rpg->win->window, rpg->gem->sp_stg, NULL);
    }
}

int is_time_arm(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->arm);
    float second = sfTime_asSeconds(time);

    if (second > 10) {
        sfClock_restart(rpg->gem->arm);
        rpg->gem->act_arm = sfFalse;
        rpg->gem->is_act = 0;
    }
}

void is_arm_gem_use(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->gem->arm);
    float second = sfTime_asSeconds(time);

    if (rpg->win->event.key.code == sfKeySpace &&
    rpg->win->event.type == sfEvtKeyPressed && rpg->com->wait_in == sfFalse &&
    is_in_frame(rpg, ITM_ARMOR) == 0 && rpg->gem->act_arm == sfFalse
    && second > 5) {
        sfClock_restart(rpg->gem->arm);
        rpg->gem->act_arm = sfTrue;
        rpg->gem->is_act = 10;
        adapte_mana(rpg);
    }
    if (rpg->gem->act_arm == sfTrue)
        is_time_stg(rpg);
}
