/*
** EPITECH PROJECT, 2024
** init menu
** File description:
** file for init struct menu
*/

#include "../../Include/my.h"

//init menu button
void init_menu(rpg_t *rpg)
{
    rpg->menu->Title = create_texte(150, (sfVector2f) {280, 150},
    sfColor_fromRGB(200, 200, 200), "Arnald's Story");
    rpg->menu->Play = create_texte(70, (sfVector2f) {850, 550},
    sfColor_fromRGB(200, 200, 200), "Play");
    rpg->menu->Continue = create_texte(70, (sfVector2f) {750, 675},
    sfColor_fromRGB(200, 200, 200), "Continue");
    rpg->menu->Setting = create_texte(70, (sfVector2f) {770, 800},
    sfColor_fromRGB(200, 200, 200), "Setting");
    rpg->menu->Quit = create_texte(70, (sfVector2f) {840, 925},
    sfColor_fromRGB(200, 200, 200), "Quit");
    rpg->menu->song = sfMusic_createFromFile(MENU_SONG);
    rpg->set_open = 0;
    sfMusic_play(rpg->menu->song);
    sfMusic_setLoop(rpg->menu->song, sfTrue);
}
