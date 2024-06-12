/*
** EPITECH PROJECT, 2024
** change sound
** File description:
** file for change sound and music
*/

#include "../../Include/my.h"

//swap sound
void change_sound(rpg_t *rpg, sfMusic *old, sfMusic *new)
{
    sfMusic_stop(old);
    sfMusic_play(new);
}

//swap music
void change_music(rpg_t *rpg, sfMusic *old, sfMusic *new)
{
    sfMusic_stop(old);
    sfMusic_play(new);
}
