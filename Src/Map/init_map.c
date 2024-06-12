/*
** EPITECH PROJECT, 2024
** init map
** File description:
** file for init struct map
*/

#include "../../Include/my.h"

//init sctruct w_map
void init_map(rpg_t *rpg)
{
    rpg->w_map = malloc(sizeof(w_map_t));
    rpg->w_map->map = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, W_MAP);
    rpg->w_map->red_m = sfImage_createFromFile(W_MAP_RED);
    rpg->w_map->m_top = create_sprite((sfVector2f) {3.2, 3.2},
        (sfVector2f) {0, 0}, W_MAP_TOP);
}

//init struct mini map
void init_mini_map(rpg_t *rpg)
{
    rpg->map = malloc(sizeof(map_t));
    rpg->map->open = 0;
    rpg->map->view = sfView_createFromRect((sfFloatRect) {0, 0, 1920, 1080});
    sfView_zoom(rpg->map->view, 3);
    rpg->map->bck = create_rectangle_shape((sfVector2f) {1100, 700},
    (sfVector2f) {10, 10}, MAP);
    rpg->map->title = create_texte_esc((sfVector2f) {30, 70}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "MAP");
    rpg->map->head = create_sprite((sfVector2f) {10, 10},
    (sfVector2f) {0, 0}, HEAD);
    sfSprite_setOrigin(rpg->map->head, (sfVector2f) {6.5, 7.5});
    sfView_setViewport(rpg->map->view, (sfFloatRect)
    {0.191f, 0.255f, 0.618f, 0.635f});
    rpg->hell_door = create_sprite((sfVector2f) {3, 3},
    (sfVector2f) {4506, 2232}, HELL_DOOR);
}
