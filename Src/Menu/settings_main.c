/*
** EPITECH PROJECT, 2024
** B-MUL-200-MLH-2-1-myrpg-aymeric.bretin
** File description:
** settings_main
*/

#include "../../Include/my.h"

//change window
void check_full_scr(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    if (sfEvtMouseButtonReleased == rpg->win->event.type) {
        sfRectangleShape_setOutlineColor(rec, sfRed);
        sfRectangleShape_setOutlineThickness(rec, 5);
        if (rpg->set->chck_scr == 1){
            rpg->set->chck_scr = 0;
            screen_handling(rpg, sfDefaultStyle);
            sfRenderWindow_setMouseCursorVisible(rpg->win->window, sfFalse);
        } else {
            rpg->set->chck_scr = 1;
            screen_handling(rpg, sfFullscreen);
            sfRenderWindow_setMouseCursorVisible(rpg->win->window, sfFalse);
        }
    } else {
        sfRectangleShape_setOutlineColor(rec, hover);
        sfRectangleShape_setOutlineThickness(rec, 5);
    }
}

void hover_full_main(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);

    if (sfFloatRect_contains(&cross_rect, mouse.x,
    mouse.y) == sfTrue) {
        check_full_scr(rpg, hover, rec);
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

void change_texture(rpg_t *rpg)
{
    if (rpg->set->chck_scr == 1)
        sfRectangleShape_setTexture(rpg->set->boxt_r, texture(VALIDE), sfTrue);
    else
        sfRectangleShape_setTexture(rpg->set->boxt_r, texture(VIDE), sfTrue);
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->set->boxt_r,
        NULL);
}

//set position for settings menu
void pos_set_main(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->cross_r, (sfVector2f) {472, 15});
    sfRectangleShape_setPosition(rpg->set->boxt_r, (sfVector2f) {100, 325});
    sfSprite_setPosition(rpg->set->back, (sfVector2f) {0, 0});
    sfText_setPosition(rpg->set->full_scr, (sfVector2f) {190, 325});
    sfText_setPosition(rpg->set->music, (sfVector2f) {20, 230});
    sfText_setPosition(rpg->set->song, (sfVector2f) {20, 150});
    sfText_setPosition(rpg->set->setting, (sfVector2f) {170, 30});
}

//check if th user is on the cross on the setting menu
static void hover_cross_main(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);

    if (sfFloatRect_contains(&cross_rect, mouse.x,
    mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            rpg->set_open = 0;
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//draw settings main menu
void draw_setting_main(rpg_t *rpg)
{
    pos_set_main(rpg);
    hover_cross_main(rpg, sfWhite, rpg->set->cross_r);
    hover_full_main(rpg, sfWhite, rpg->set->boxt_r);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->set->back, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->full_scr, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->music, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->song, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->setting, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->set->cross_r,
        NULL);
    change_texture(rpg);
}
