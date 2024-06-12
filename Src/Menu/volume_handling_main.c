/*
** EPITECH PROJECT, 2024
** B-MUL-200-MLH-2-1-myrpg-aymeric.bretin
** File description:
** volume_handling_main
*/

#include "../../Include/my.h"

//set position of rectangle in song bar
void vol_song_menu(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->song_rec[0],
    (sfVector2f) {207, 158});
    sfRectangleShape_setPosition(rpg->set->song_rec[1],
    (sfVector2f) {252, 158});
    sfRectangleShape_setPosition(rpg->set->song_rec[2],
    (sfVector2f) {297, 158});
    sfRectangleShape_setPosition(rpg->set->song_rec[3],
    (sfVector2f) {342, 158});
    sfRectangleShape_setPosition(rpg->set->song_rec[4],
    (sfVector2f) {387, 158});
    sfRectangleShape_setPosition(rpg->set->song_rec[5],
    (sfVector2f) {432, 158});
}

//set position of rectangle in music bar
void vol_music_menu(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->music_rec[0],
    (sfVector2f) {207, 238});
    sfRectangleShape_setPosition(rpg->set->music_rec[1],
    (sfVector2f) {252, 238});
    sfRectangleShape_setPosition(rpg->set->music_rec[2],
    (sfVector2f) {297, 238});
    sfRectangleShape_setPosition(rpg->set->music_rec[3],
    (sfVector2f) {342, 238});
    sfRectangleShape_setPosition(rpg->set->music_rec[4],
    (sfVector2f) {387, 238});
    sfRectangleShape_setPosition(rpg->set->music_rec[5],
    (sfVector2f) {432, 238});
}

//check if the user click on a rectangle in mucic
static void check_vol_music_menu(rpg_t *rpg)
{
    sfFloatRect pos_rec;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);

    for (int i = 0; i < 6; i++){
        pos_rec = sfRectangleShape_getGlobalBounds(rpg->set->music_rec[i]);
        if (sfFloatRect_contains(&pos_rec, mouse.x,
        mouse.y) && sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type){
            rpg->set->vol_music = i;
        }
    }
}

//check if the user click on a rectangle in song
static void check_vol_song_menu(rpg_t *rpg)
{
    sfFloatRect pos_rec;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);

    for (int i = 0; i < 6; i++){
        pos_rec = sfRectangleShape_getGlobalBounds(rpg->set->song_rec[i]);
        if (sfFloatRect_contains(&pos_rec, mouse.x,
        mouse.y) && sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type){
            rpg->set->vol_song = i;
        }
    }
}

//change level of music and song
void vol_handling_main(rpg_t *rpg)
{
    float vol = 0;
    float vol2 = 0;

    if (rpg->game_state == 0) {
    check_vol_song_menu(rpg);
    check_vol_music_menu(rpg);
    for (int i = 0; i != rpg->set->vol_song; i++)
        vol += 20;
    for (int i = 0; i != rpg->set->vol_music; i++)
        vol2 += 20;
    sfMusic_setVolume(rpg->menu->song, vol);
    }
}
