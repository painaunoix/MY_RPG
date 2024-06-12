/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set item found in chest to inv slot
*/

#include "../../Include/my.h"

//set position of item in inventory slot
void set_itm_in_mid(rpg_t *rpg)
{
    sfVector2f pos_rect;

    for (int j = 0; j != 15; j++)
        if (rpg->sl_inv[j]->tex_set == sfTrue) {
            pos_rect = sfRectangleShape_getPosition(rpg->sl_inv[j]->slot);
            sfSprite_setPosition(rpg->sl_inv[j]->sp, pos_rect);
            sfSprite_setScale(rpg->sl_inv[j]->sp, (sfVector2f) {2, 2});
        }
}

//draw inventory slot
void draw_sp_slot(rpg_t *rpg)
{
    sfVector2f pos_rect;

    for (int j = 0; j != 15; j++)
        if (rpg->sl_inv[j]->tex_set == sfTrue) {
            sfRenderWindow_drawSprite(rpg->win->window, rpg->sl_inv[j]->sp,
            NULL);
        }
}

//check for don't have two time same item
int is_itm_in_slot(rpg_t *rpg, char *str)
{
    for (int i = 0; i != 15; i++)
        if (my_strcmp(str, rpg->sl_inv[i]->name) == 0)
            return (1);
    return (0);
}

//set texture to inventory slot
void set_tex_sl(rpg_t *rpg, char *file)
{
    for (int j = 0; j != 15; j++)
        if (rpg->sl_inv[j]->tex_set == sfFalse &&
        is_itm_in_slot(rpg, file) == 0) {
            sfSprite_setTexture(rpg->sl_inv[j]->sp, texture(file), sfTrue);
            rpg->sl_inv[j]->tex_set = sfTrue;
            sfSprite_setScale(rpg->sl_inv[j]->sp, (sfVector2f) {2, 2});
            rpg->sl_inv[j]->name = my_strdup(file);
        }
}

//choose witch item to add in inventory
static void choose_itm(rpg_t *rpg, int i)
{
    if (i == 0)
        set_tex_sl(rpg, ITM_AXE);
    if (i == 1)
        set_tex_sl(rpg, ITM_HOOK);
    if (i == 2)
        set_tex_sl(rpg, ITM_SPEED);
    if (i == 3)
        set_tex_sl(rpg, ITM_ARMOR);
    if (i == 4)
        set_tex_sl(rpg, ITM_STRENGHT);
    if (i == 5)
        set_tex_sl(rpg, ITM_DUCK);
    if (i == 6)
        set_tex_sl(rpg, ITM_TORCH);
    if (i == 7)
        set_tex_sl(rpg, ITM_BOMB);
}

//check if chest is open
void is_chest_open(rpg_t *rpg)
{
    for (int i = 0; rpg->chest[i]; i++)
        if (rpg->chest[i]->open == 1)
            choose_itm(rpg, i);
}
