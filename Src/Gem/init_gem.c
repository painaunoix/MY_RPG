/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init struct gem
*/

#include "../../Include/my.h"

//init gem struct
void init_gem(rpg_t *rpg)
{
    rpg->gem = malloc(sizeof(gem_t));
    rpg->gem->speed = sfClock_create();
    rpg->gem->old_spd = rpg->player->player_speed;
    rpg->gem->act_spd = sfFalse;
    rpg->gem->stg = sfClock_create();
    rpg->gem->old_stg = rpg->player->atk;
    rpg->gem->act_stg = sfFalse;
    rpg->mana->mana = 100;
    rpg->gem->arm = sfClock_create();
    rpg->gem->act_arm = sfFalse;
    rpg->gem->sp_arm = create_sprite((sfVector2f) {1.5, 1.5}, (sfVector2f)
    {0, 0}, BUFF_ARM);
    rpg->gem->sp_stg = create_sprite((sfVector2f) {1.5, 1.5}, (sfVector2f)
    {0, 0}, BUFF_STG);
    rpg->gem->sp_spd = create_sprite((sfVector2f) {1.5, 1.5}, (sfVector2f)
    {0, 0}, BUFF_SPD);
    rpg->gem->is_act = 0;
}
