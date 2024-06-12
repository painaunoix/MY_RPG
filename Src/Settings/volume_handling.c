/*
** EPITECH PROJECT, 2024
** volume handling
** File description:
** this file is a sound and music handling
*/

#include "../../Include/my.h"

//crete array of rectangle
static sfRectangleShape **fill_volume(sfRectangleShape **tab)
{
    tab = malloc(sizeof(sfRectangleShape *) * 6);
    for (int i = 0; i != 6; i++) {
        tab[i] = create_rectangle_shape((sfVector2f) {38, 41},
        (sfVector2f) {0, 0}, BOX);
    }
    return tab;
}

//init variable of sound setting
void init_volume_set(rpg_t *rpg)
{
    rpg->set->vol_music = 5;
    rpg->set->vol_song = 5;
    rpg->set->song_rec = fill_volume(rpg->set->song_rec);
    rpg->set->music_rec = fill_volume(rpg->set->music_rec);
}

//set position of rectangle in song bar
static void set_vol_song(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->song_rec[0],
    set_pos_mid_rec(rpg, rpg->set->song_rec[0], 483.5, -49));
    sfRectangleShape_setPosition(rpg->set->song_rec[1],
    set_pos_mid_rec(rpg, rpg->set->song_rec[1], 483.5, -3));
    sfRectangleShape_setPosition(rpg->set->song_rec[2],
    set_pos_mid_rec(rpg, rpg->set->song_rec[2], 483.5, 43));
    sfRectangleShape_setPosition(rpg->set->song_rec[3],
    set_pos_mid_rec(rpg, rpg->set->song_rec[3], 483.5, 89));
    sfRectangleShape_setPosition(rpg->set->song_rec[4],
    set_pos_mid_rec(rpg, rpg->set->song_rec[4], 483.5, 135));
    sfRectangleShape_setPosition(rpg->set->song_rec[5],
    set_pos_mid_rec(rpg, rpg->set->song_rec[5], 483.5, 181));
}

//set position of rectangle in music bar
static void set_vol_music(rpg_t *rpg)
{
    sfRectangleShape_setPosition(rpg->set->music_rec[0],
    set_pos_mid_rec(rpg, rpg->set->music_rec[0], 563.5, -49));
    sfRectangleShape_setPosition(rpg->set->music_rec[1],
    set_pos_mid_rec(rpg, rpg->set->music_rec[1], 563.5, -3));
    sfRectangleShape_setPosition(rpg->set->music_rec[2],
    set_pos_mid_rec(rpg, rpg->set->music_rec[2], 563.5, 43));
    sfRectangleShape_setPosition(rpg->set->music_rec[3],
    set_pos_mid_rec(rpg, rpg->set->music_rec[3], 563.5, 89));
    sfRectangleShape_setPosition(rpg->set->music_rec[4],
    set_pos_mid_rec(rpg, rpg->set->music_rec[4], 563.5, 135));
    sfRectangleShape_setPosition(rpg->set->music_rec[5],
    set_pos_mid_rec(rpg, rpg->set->music_rec[5], 563.5, 181));
}

//check if the user click on a rectangle in mucic
static void check_vol_music(rpg_t *rpg)
{
    sfFloatRect pos_rec;

    for (int i = 0; i < 6; i++){
        pos_rec = sfRectangleShape_getGlobalBounds(rpg->set->music_rec[i]);
        if (sfFloatRect_contains(&pos_rec, rpg->win->mouse.x,
        rpg->win->mouse.y) && sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->set->open == 1){
            rpg->set->vol_music = i;
        }
    }
}

//check if the user click on a rectangle in song
static void check_vol_song(rpg_t *rpg)
{
    sfFloatRect pos_rec;

    for (int i = 0; i < 6; i++){
        pos_rec = sfRectangleShape_getGlobalBounds(rpg->set->song_rec[i]);
        if (sfFloatRect_contains(&pos_rec, rpg->win->mouse.x,
        rpg->win->mouse.y) && sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type &&
        rpg->set->open == 1){
            rpg->set->vol_song = i;
        }
    }
}

//change level of music and song
void vol_handling(rpg_t *rpg)
{
    float vol = 0;
    float vol2 = 0;

    if (rpg->game_state == 1) {
    check_vol_song(rpg);
    check_vol_music(rpg);
    for (int i = 0; i != rpg->set->vol_song; i++)
        vol += 20;
    for (int i = 0; i != rpg->set->vol_music; i++)
        vol2 += 20;
    sfMusic_setVolume(rpg->sound[rpg->player->cur_zone]->sound, vol2);
    sfMusic_setVolume(rpg->walk_sound->walk, vol);
    }
}

//draw rectangle of music and song
void draw_volume(rpg_t *rpg)
{
    if (rpg->game_state == 1){
        set_vol_music(rpg);
        set_vol_song(rpg);
    }
    if (rpg->game_state == 0){
        vol_song_menu(rpg);
        vol_music_menu(rpg);
    }
    for (int i = 0; i <= rpg->set->vol_song; i++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->set->song_rec[i], NULL);
    for (int i = 0; i <= rpg->set->vol_music; i++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->set->music_rec[i], NULL);
}
