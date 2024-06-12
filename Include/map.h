/*
** EPITECH PROJECT, 2024
** map.h
** File description:
** map
*/

#ifndef MAP_H_
    #define MAP_H_

    #include <SFML/Graphics.h>

    #define W_MAP "Asset/Map/Map.png"
    #define W_MAP_TOP "Asset/Map/Top_all.png"
    #define W_MAP_RED "Asset/Map/Red_map.png"
    #define SONG_BEACH "Song/plage.ogg"
    #define SONG_PLAIN "Song/plaine.ogg"
    #define SONG_MTNG "Song/mtn.ogg"
    #define SONG_DESSERT "Song/dessert.ogg"
    #define SONG_FOREST "Song/foret.ogg"

    #define MAP "Asset/Map/Map_box.png"
    #define HEAD "Asset/Map/Player_head.png"
    #define SAVE "Asset/Map/save_rock.png"

    #define TRADER "Asset/Map/trader.png"

    #define TORCH_ON "Asset/Big_Torch/big_torch_on.png"
    #define TORCH_OFF "Asset/Big_Torch/big_torch_off.png"
    #define WATER "Asset/Map/RedBoat.png"

    #define HELL_DOOR "Asset/Map/Hell_Door.png"

typedef struct w_map_s {
    sfSprite *map;
    sfSprite *m_top;
    sfImage *red_m;
} w_map_t;

typedef struct torch_sp_s {
    sfSprite *torch;
    int state;
} torch_sp_t;

typedef struct big_torch_s {
    sfIntRect torch_Rect;
    sfTexture *texture_on;
    sfTexture *texture_off;
    torch_sp_t **torch;
    sfClock *clock;
    sfTime time;
    float seconds;
} big_torch_t;

typedef struct map_s {
    int open;
    sfRectangleShape *bck;
    sfSprite *head;
    sfText *title;
    sfView *view;
}map_t;

typedef struct trader_s {
    sfRectangleShape *rect;
    sfSprite *trader;
    sfTexture *tex;
    sfIntRect rec;
    int open;
    sfClock *cl;
    sfText *coin;
    sfRectangleShape *back;
    sfText *shop;
}trader_t;

typedef struct trader_but_s {
    sfRectangleShape *rec;
    sfText *buy;
    sfRectangleShape *item;
    sfText *cost;
    int price;
    char *name;
}trader_but_t;

typedef struct stone_s {
    sfRectangleShape *rec;
}stone_t;

typedef struct dock_s {
    sfRectangleShape *rec;
    sfVector2f pos;
}dock_t;

#endif /* !MAP_H_ */
