/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** check if frame is click with tool
*/

#include "../../Include/my.h"

//check if player try to put same item in same frame
int is_itm_use(rpg_t *rpg)
{
    if (my_strcmp(rpg->sl_inv[rpg->inv->move_sp]->name, rpg->cadre->itm1) == 0
    || my_strcmp(rpg->sl_inv[rpg->inv->move_sp]->name, rpg->cadre->itm2) == 0)
        return (1);
    return (0);
}

//check if the player click on frame
void is_frame_click(rpg_t *rpg)
{
    sfFloatRect pos_itm = sfRectangleShape_getGlobalBounds(rpg->cadre->cadre);
    sfFloatRect pos_itm2 = sfRectangleShape_getGlobalBounds
    (rpg->cadre->cadre2);

    if (sfFloatRect_contains(&pos_itm, rpg->win->mouse.x,
    rpg->win->mouse.y) && sfEvtMouseButtonReleased == rpg->win->event.type &&
    rpg->inv->move_sp != -1 && is_itm_use(rpg) == 0) {
        rpg->cadre->item2 = create_rectangle_shape((sfVector2f)
        {50, 50}, (sfVector2f) {0, 0}, rpg->sl_inv[rpg->inv->move_sp]->name);
        rpg->cadre->itm2 = my_strdup(rpg->sl_inv[rpg->inv->move_sp]->name);
    }
    if (sfFloatRect_contains(&pos_itm2, rpg->win->mouse.x,
    rpg->win->mouse.y) && sfEvtMouseButtonReleased == rpg->win->event.type &&
    rpg->inv->move_sp != -1 && is_itm_use(rpg) == 0) {
        rpg->cadre->item = create_rectangle_shape((sfVector2f)
        {50, 50}, (sfVector2f) {0, 0}, rpg->sl_inv[rpg->inv->move_sp]->name);
        rpg->cadre->itm1 = my_strdup(rpg->sl_inv[rpg->inv->move_sp]->name);
    }
}
