/*
** EPITECH PROJECT, 2024
** B-MUL-200-MLH-2-1-myrpg-aymeric.bretin
** File description:
** sound_walk
*/

#include "../../Include/my.h"

void sound_walk(rpg_t *rpg)
{
    rpg->walk_sound = malloc(sizeof(walk_t));
    rpg->walk_sound->walk = sfMusic_createFromFile(WALK);
    rpg->attack->axe_slash = sfMusic_createFromFile(SLASH);
    rpg->attack->start = sfFalse;
    rpg->attack->stop = sfFalse;
    rpg->walk_sound->start = sfFalse;
    rpg->walk_sound->stop = sfFalse;
}

void check_walk(rpg_t *rpg)
{
    sfSoundStatus status = sfMusic_getStatus(rpg->walk_sound->walk);

    if (rpg->walk_sound->start == sfTrue && sfStopped == status){
        sfMusic_play(rpg->walk_sound->walk);
        rpg->walk_sound->start = sfFalse;
    }
    if (rpg->walk_sound->stop == sfTrue && sfPlaying == status){
        sfMusic_stop(rpg->walk_sound->walk);
        rpg->walk_sound->stop = sfFalse;
    }
}

void check_attack(rpg_t *rpg)
{
    sfSoundStatus status = sfMusic_getStatus(rpg->attack->axe_slash);

    if (rpg->attack->start == sfTrue && sfStopped == status){
        sfMusic_play(rpg->attack->axe_slash);
        rpg->attack->start = sfFalse;
    }
    if (rpg->attack->stop == sfTrue && sfPlaying == status){
        sfMusic_stop(rpg->attack->axe_slash);
        rpg->attack->stop = sfFalse;
    }
}
