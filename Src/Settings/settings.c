/*
** EPITECH PROJECT, 2024
** setting menu
** File description:
** settings handling
*/

#include "../../Include/my.h"

//change window
void screen_handling(rpg_t *rpg, sfUint32 style)
{
    sfVideoMode size = {1920, 1080, 16};
    char *name = "Arnald's Story";

    sfRenderWindow_close(rpg->win->window);
    rpg->win->window = sfRenderWindow_create(size, name, style, NULL);
    sfRenderWindow_setFramerateLimit(rpg->win->window, 60);
}

//check if th user is on the cross on the setting menu
static void hover_cross_set(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfRectangleShape_setOutlineColor(rec, sfRed);
            sfRectangleShape_setOutlineThickness(rec, 5);
            rpg->set->open = 0;
            rpg->esc->esc_check = 1;
        } else {
            sfRectangleShape_setOutlineColor(rec, hover);
            sfRectangleShape_setOutlineThickness(rec, 5);
        }
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

void hover_full_set(rpg_t *rpg, sfColor hover, sfRectangleShape *rec)
{
    sfFloatRect cross_rect = sfRectangleShape_getGlobalBounds(rec);

    if (sfFloatRect_contains(&cross_rect, rpg->win->mouse.x,
    rpg->win->mouse.y) == sfTrue) {
        check_full_scr(rpg, hover, rec);
    } else {
        sfRectangleShape_setOutlineThickness(rec, 0);
    }
}

//init struct set
void init_settings(rpg_t *rpg)
{
    rpg->set = malloc(sizeof(set_t));
    rpg->set->open = 0;
    rpg->set->chck_scr = 1;
    rpg->set->cross_r = create_rectangle_shape((sfVector2f) {60, 60},
        (sfVector2f) {0, 0}, CROSS_ESCAPE);
    rpg->set->boxt_r = create_rectangle_shape((sfVector2f) {60, 60},
        (sfVector2f) {0, 0}, VALIDE);
    rpg->set->back = create_sprite((sfVector2f) {3, 3}, (sfVector2f) {0, 0},
        SETTINGS);
    rpg->set->full_scr = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Full screen");
    rpg->set->music = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Music");
    rpg->set->song = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Song");
    rpg->set->setting = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "SETTINGS");
}

//set position for settings menu
void set_pos_set(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->cross_r,
        set_pos_mid_rec(rpg, rpg->set->cross_r, 350, 220));
    sfRectangleShape_setPosition(rpg->set->boxt_r,
        set_pos_mid_rec(rpg, rpg->set->boxt_r, 650, -200));
    sfSprite_setPosition(rpg->set->back,
        set_pos_mid_sprite(rpg, rpg->set->back, 325));
    sfText_setPosition(rpg->set->full_scr,
        set_pos_mid_txt(rpg, rpg->set->full_scr, 650, -50));
    sfText_setPosition(rpg->set->music,
        set_pos_mid_txt(rpg, rpg->set->music, 555, -200));
    sfText_setPosition(rpg->set->song,
        set_pos_mid_txt(rpg, rpg->set->song, 475, -200));
    sfText_setPosition(rpg->set->setting,
        set_pos_mid_txt(rpg, rpg->set->setting, 355, 0));
}

//draw settings menu
void draw_setting(rpg_t *rpg)
{
    set_pos_set(rpg);
    hover_cross_set(rpg, sfWhite, rpg->set->cross_r);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->set->back, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->full_scr, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->music, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->song, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->set->setting, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->set->cross_r,
        NULL);
    change_texture(rpg);
}
