/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** adapt rope for grapling
*/

#include "../../Include/my.h"

//set pos of the rope at the right or at the left of the player depends on axis
void adapt_rope(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->player);

    pos.y += 40;
    if (rpg->player->player_axe == 2)
        pos.x += 140;
    if (rpg->player->player_axe == 4)
        pos.x -= 320;
    sfRectangleShape_setPosition(rpg->grap->rope, pos);
}

//chnage coord value for a better display of the rope
sfVector2f change_target(sfVector2f target)
{
    target.x += 30;
    target.y += 30;
    return target;
}

//chnage coord value for a better display of the rope
sfVector2f change_player(sfVector2f player)
{
    player.x += 90;
    player.y += 40;
    return player;
}

//check if the rope is lunch and adapt it postision
void display_rope(rpg_t *rpg)
{
    sfVector2f pos_player = sfSprite_getPosition(rpg->player->player);
    sfVector2f pos_target = sfRectangleShape_getPosition(rpg->grap_pillar
    [rpg->grap->idx_target]->pillar);

    pos_target = change_target(pos_target);
    pos_player = change_player(pos_player);
    sfConvexShape_setPointCount(rpg->grap->dis_rope, 4);
    if (rpg->grap->lunch == sfTrue) {
        pos_player.y += 5;
        sfConvexShape_setPoint(rpg->grap->dis_rope, 0, pos_player);
        pos_target.y += 20;
        sfConvexShape_setPoint(rpg->grap->dis_rope, 1, pos_target);
        pos_target.y -= 10;
        sfConvexShape_setPoint(rpg->grap->dis_rope, 2, pos_target);
        pos_player.y -= 10;
        sfConvexShape_setPoint(rpg->grap->dis_rope, 3, pos_player);
        sfRenderWindow_drawConvexShape(rpg->win->window, rpg->grap->dis_rope,
        NULL);
    }
}
