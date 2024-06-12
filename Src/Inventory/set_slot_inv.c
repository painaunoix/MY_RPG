/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set solt inv
*/

#include "../../Include/my.h"

//swap when two slot is used
static void swap_name_sp(rpg_t *rpg, int i, int j)
{
    char *tmp = my_strdup(rpg->sl_inv[i]->name);

    rpg->sl_inv[i]->name = my_strdup(rpg->sl_inv[j]->name);
    rpg->sl_inv[j]->name = my_strdup(tmp);
}

//swap when one slot is not used
static void change_slot_null(rpg_t *rpg, int i)
{
        if (rpg->sl_inv[rpg->inv->move_sp]->name == NULL) {
            rpg->sl_inv[rpg->inv->move_sp]->disp = sfFalse;
            rpg->sl_inv[rpg->inv->move_sp]->tex_set = sfFalse;
            rpg->sl_inv[i]->disp = sfTrue;
            rpg->sl_inv[i]->tex_set = sfTrue;
        }
        rpg->inv->move_sp = -1;
}

//check if slot is click to drag item and swap item
static void slot_is_click(rpg_t *rpg, int i)
{
    if (sfMouseLeft == rpg->win->event.mouseButton.button &&
    rpg->sl_inv[i]->tex_set == sfTrue && rpg->inv->move_sp == -1 &&
    sfEvtMouseButtonReleased == rpg->win->event.type) {
        rpg->inv->move_sp = i;
        return;
    }
    if (sfMouseLeft == rpg->win->event.mouseButton.button
    && sfEvtMouseButtonReleased == rpg->win->event.type
    && rpg->inv->move_sp != -1) {
        sfSprite_setTexture(rpg->sl_inv[rpg->inv->move_sp]->sp,
        texture(rpg->sl_inv[i]->name), sfTrue);
        sfSprite_setTexture(rpg->sl_inv[i]->sp,
        texture(rpg->sl_inv[rpg->inv->move_sp]->name), sfTrue);
        swap_name_sp(rpg, i, rpg->inv->move_sp);
        change_slot_null(rpg, i);
    }
    set_itm_in_mid(rpg);
}

//check if mouse is on slot for change the color of the slot
void is_mouse_on_slot(rpg_t *rpg)
{
    sfFloatRect pos_rec;

    for (int i = 0; i != 15; i++) {
        pos_rec = sfRectangleShape_getGlobalBounds(rpg->sl_inv[i]->slot);
        if (sfFloatRect_contains(&pos_rec, rpg->win->mouse.x,
        rpg->win->mouse.y)) {
            sfRectangleShape_setFillColor(rpg->sl_inv[i]->slot,
            sfColor_fromRGBA(111, 78, 55, 170));
            slot_is_click(rpg, i);
        } else
            sfRectangleShape_setFillColor(rpg->sl_inv[i]->slot, sfTransparent);
    }
    if (rpg->inv->move_sp != -1)
        sfSprite_setPosition(rpg->sl_inv[rpg->inv->move_sp]->sp,
        (sfVector2f) {rpg->win->mouse.x - 25, rpg->win->mouse.y - 25});
}

//daw inventory slot
void draw_slot(rpg_t *rpg)
{
    for (int i = 0; i != 15; i++) {
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->sl_inv[i]->slot, NULL);
    }
    draw_sp_slot(rpg);
}

//remove the border of the inventory slot
void remove_border(rpg_t *rpg)
{
    for (int i = 0; i != 15; i++) {
        sfRectangleShape_setOutlineColor(rpg->sl_inv[i]->slot, sfTransparent);
    }
    set_itm_in_mid(rpg);
}

//set pos of inventory slot
void set_pos_inv_slot_2(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->sl_inv[7]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[7]->slot, 465, 234));
    sfRectangleShape_setPosition(rpg->sl_inv[8]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[8]->slot, 465, 348));
    sfRectangleShape_setPosition(rpg->sl_inv[9]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[9]->slot, 465, 458));
    sfRectangleShape_setPosition(rpg->sl_inv[10]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[10]->slot, 576, 7));
    sfRectangleShape_setPosition(rpg->sl_inv[11]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[11]->slot, 576, 120));
    sfRectangleShape_setPosition(rpg->sl_inv[12]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[12]->slot, 576, 234));
    sfRectangleShape_setPosition(rpg->sl_inv[13]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[13]->slot, 576, 348));
    sfRectangleShape_setPosition(rpg->sl_inv[14]->slot, set_pos_mid_rec
    (rpg, rpg->sl_inv[14]->slot, 576, 458));
    remove_border(rpg);
}

//set pos of inventory slot
void set_pos_inv_slot(rpg_t *rpg)
{
    if (rpg->inv->open == 1) {
        sfRectangleShape_setPosition(rpg->sl_inv[0]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[0]->slot, 355, 6));
        sfRectangleShape_setPosition(rpg->sl_inv[1]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[1]->slot, 355, 120));
        sfRectangleShape_setPosition(rpg->sl_inv[2]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[2]->slot, 355, 234));
        sfRectangleShape_setPosition(rpg->sl_inv[3]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[3]->slot, 355, 348));
        sfRectangleShape_setPosition(rpg->sl_inv[4]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[4]->slot, 355, 458));
        sfRectangleShape_setPosition(rpg->sl_inv[5]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[5]->slot, 465, 7));
        sfRectangleShape_setPosition(rpg->sl_inv[6]->slot, set_pos_mid_rec
        (rpg, rpg->sl_inv[6]->slot, 465, 120));
        set_pos_inv_slot_2(rpg);
    }
}
