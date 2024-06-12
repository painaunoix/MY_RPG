/*
** EPITECH PROJECT, 2024
** menu.h
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>

    #define MENU_FONT "Font/Crang.ttf"
    #define FONT_ESCAPE "Font/Pixellari.ttf"

    #define MENU_SONG "Song/Menu.ogg"

    #define MENU "Asset/Menu/Menu_gif.png"
    #define LOAD_BORDER "Asset/Menu/LoadBar_Border.png"
    #define LOGO "Asset/Menu/logo.png"

    #define FOND_ESCAPE "Asset/Echape/Fond.png"
    #define CASE_ESCAPE "Asset/Echape/Case.png"
    #define CROSS_ESCAPE "Asset/Echape/Cross.png"

    #define INV "Asset/Inventory/Inventory.png"
    #define UP "Asset/Inventory/Plus_button.png"
    #define BOX "Asset/Inventory/Box2.png"

    #define SETTINGS "Asset/Setting/Setting.png"
    #define VIDE "Asset/Setting/BoxVide.png"
    #define VALIDE "Asset/Setting/BoxValide.png"

    #define QTS "Asset/Quest/Quests.png"

typedef struct menu_s {
    sfMusic *song;
    sfText *Title;
    sfText *Play;
    sfText *Continue;
    sfText *Setting;
    sfText *Quit;
    sfSprite *fond;
    sfIntRect fond_rect;
    sfClock *clock;
    sfTime time;
    float seconds;
} menu_t;

typedef struct escape_s {
    sfText *inv_txt;
    sfText *set_txt;
    sfText *quit_txt;
    sfText *opt_txt;
    sfSprite *back;
    sfRectangleShape *set_r;
    sfRectangleShape *inv_r;
    sfRectangleShape *quit_r;
    sfRectangleShape *cross_r;
    int esc_check;
} escape_t;

typedef struct inv_s {
    int open;
    sfRectangleShape *bck;
    sfRectangleShape **skills;
    sfRectangleShape **slots;
    sfText *title;
    sfText *healt;
    sfText *strenght;
    sfText *armor;
    sfText *speed;
    sfText *mana;
    sfText *luck;
    int move_sp;
} inv_t;

typedef struct set_s {
    int open;
    int chck_scr;
    int vol_song;
    int vol_music;
    sfSprite *back;
    sfText *setting;
    sfText *music;
    sfText *song;
    sfText *full_scr;
    sfRectangleShape *cross_r;
    sfRectangleShape *boxt_r;
    sfRectangleShape **song_rec;
    sfRectangleShape **music_rec;
} set_t;

typedef struct slot_inv_s {
    sfRectangleShape *slot;
    sfSprite *sp;
    sfBool tex_set;
    sfBool disp;
    char *name;
}slot_inv_t;

typedef struct loading_s {
    sfClock *clock;
    sfTime time;
    float seconds;
    int in;
    sfRectangleShape *loading_bar;
    sfSprite *load_border;
    sfText *info;
    sfSprite *logo;
} loading_t;

typedef struct quests_s {
    int open;
    sfRectangleShape *bck;
    sfText *title;
    int ghost;
    sfText *txGhost;
    int slime;
    sfText *txSlime;
    int snake;
    sfText *txSnake;
    int dog;
    sfText *txDog;
    int golem;
    sfText *txGolem;
} quests_t;

#endif /* !MENU_H_ */
