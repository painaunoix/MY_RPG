/*
** EPITECH PROJECT, 2024
** hud.h
** File description:
** hud
*/

#ifndef HUD_H_
    #define HUD_H_

    #include <SFML/Graphics.h>

    #define PV "Asset/Ui/Hearth.png"
    #define PV_EMPTY "Asset/Ui/HearthEmpty.png"
    #define MANA "Asset/Ui/Bar_Mana.png"
    #define MANA_UI "Asset/Ui/Mana_Ui.png"
    #define CADRE "Asset/Ui/Cadre.png"
    #define CURSOR "Asset/Ui/Cursor1.png"
    #define BUFF_SPD "Asset/Buff/Speed.png"
    #define BUFF_STG "Asset/Buff/Strenght.png"
    #define BUFF_ARM "Asset/Buff/Armor.png"
    #define END "Asset/Ui/End.png"

    #define TUTO_DOCK "Asset/Tutorial/Dock_Tuto.PNG"
    #define TUTO_BOMB "Asset/Tutorial/Bomb_Tuto.PNG"
    #define TUTO_HOOK "Asset/Tutorial/Hook_Tuto.PNG"
    #define TUTO_TORCH "Asset/Tutorial/Torch_Tuto.PNG"

typedef struct cadre_s {
    sfRectangleShape *cadre;
    sfRectangleShape *cadre2;
    sfRectangleShape *item;
    sfRectangleShape *item2;
    sfTexture *cadre_tex;
    char *itm1;
    char *itm2;
} cadre_t;

typedef struct cursor_s {
    sfSprite *curs;
    sfTexture *curs_tex;
}cursor_t;

#endif /* !HUD_H_ */
