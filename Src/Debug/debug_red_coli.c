/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** display red
*/

#include "../../Include/my.h"

//init struct debug
void init_debug(rpg_t *rpg)
{
    rpg->debug = malloc(sizeof(debug_t));
    rpg->debug->red = sfSprite_create();
    rpg->debug->redt = sfTexture_createFromImage(rpg->boat->img, NULL);
    sfSprite_setTexture(rpg->debug->red, rpg->debug->redt, sfTrue);
    rpg->debug->disp = sfFalse;
    rpg->debug->coli = sfTrue;
    rpg->debug->die = sfTrue;
}

//display the collision map
void display_red(rpg_t *rpg)
{
    if (rpg->debug->disp == sfTrue)
        sfRenderWindow_drawSprite(rpg->win->window, rpg->debug->red, NULL);
}
