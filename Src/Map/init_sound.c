/*
** EPITECH PROJECT, 2024
** init beach
** File description:
** init strcut for beach
*/

#include "../../Include/my.h"

//fill struct sound
sound_t *create_zone(sound_t *sound, sfVector2f scale,
    sfVector2f pos, char *name)
{
    sound = malloc(sizeof(sound_t));
    sound->rec = create_rectangle_shape(scale, pos, NULL);
    sfRectangleShape_setOutlineThickness(sound->rec, 5);
    sfRectangleShape_setOutlineColor(sound->rec, sfRed);
    sfRectangleShape_setFillColor(sound->rec, sfTransparent);
    sound->sound = sfMusic_createFromFile(name);
    return (sound);
}

//malloc struct sound
void init_sound(rpg_t *rpg)
{
    rpg->sound = malloc(sizeof(sound_t *) * 7 + sizeof(NULL));
    rpg->sound[0] = create_zone(rpg->sound[0], (sfVector2f) {4300, 1000},
    (sfVector2f) {1600, 8800}, SONG_BEACH);
    rpg->sound[1] = create_zone(rpg->sound[1], (sfVector2f) {4750, 2024},
    (sfVector2f) {1388, 6682}, SONG_PLAIN);
    rpg->sound[2] = create_zone(rpg->sound[2], (sfVector2f) {4750, 1410},
    (sfVector2f) {1480, 5210}, SONG_FOREST);
    rpg->sound[3] = create_zone(rpg->sound[3], (sfVector2f) {2977, 3783},
    (sfVector2f) {6250, 5111}, SONG_PLAIN);
    rpg->sound[4] = create_zone(rpg->sound[4], (sfVector2f) {7730, 1050},
    (sfVector2f) {1410, 3930}, SONG_MTNG);
    rpg->sound[5] = create_zone(rpg->sound[5], (sfVector2f) {3080, 4260},
    (sfVector2f) {9230, 4890}, SONG_DESSERT);
    rpg->sound[6] = create_zone(rpg->sound[6], (sfVector2f) {5880, 3220},
    (sfVector2f) {1260, 700}, SONG_MTNG);
    rpg->sound[7] = NULL;
}

//check if the player have change zone
void swap_zone(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect zone;

    for (int i = 0; rpg->sound[i] != NULL; i++){
        zone = sfRectangleShape_getGlobalBounds(rpg->sound[i]->rec);
        if (sfFloatRect_intersects(&player, &zone, NULL)
            && rpg->player->cur_zone != i){
            change_sound(rpg, rpg->sound[rpg->player->cur_zone]->sound,
                rpg->sound[i]->sound);
            rpg->player->cur_zone = i;
        }
    }
}
