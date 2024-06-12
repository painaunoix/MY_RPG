/*
** EPITECH PROJECT, 2024
** donjon.h
** File description:
** donjon
*/

#ifndef DONJON_H_
    #define DONJON_H_

    #include <SFML/Graphics.h>

    #define DUNGEON_F_MAP "Asset/Dungeon_Forest/Dungeon_Forest_Map.png"
    #define DUNGEON_F_RED "Asset/Dungeon_Forest/Dungeon_Forest_Red.png"

    #define DG_FIRST_DOOR "Asset/Dungeon_Forest/First_Door.png"
    #define DG_SECOND_DOOR "Asset/Dungeon_Forest/Second_Door.png"
    #define DG_BOSS_DOOR "Asset/Dungeon_Forest/Boss_Door.png"
    #define DG_END_DOOR "Asset/Dungeon_Forest/End_Door.png"

    #define DOOR_EMPTY "Asset/Dungeon_Forest/Door_Empty.png"
    #define DOOR_SILVER "Asset/Dungeon_Forest/Door_Silver.png"
    #define DOOR_GOLD "Asset/Dungeon_Forest/Door_Gold.png"
    #define GOLD_KEY "Asset/Dungeon_Forest/Gold_Key.png"
    #define SILVER_KEY "Asset/Dungeon_Forest/Silver_Key.png"

    #define DOOR_EMPTY_L "Asset/Dungeon_Water/DoorOpen.png"
    #define DOOR_SILVER_L "Asset/Dungeon_Water/DoorSilver.png"
    #define DOOR_GOLD_L "Asset/Dungeon_Water/DoorGolden.png"

    #define DUNGEON_W_MAP "Asset/Dungeon_Water/MapWaterDG.png"
    #define DUNGEON_W_RED "Asset/Dungeon_Water/RedDGWater.png"

    #define DG_FIRST_DOOR_W "Asset/Dungeon_Water/FirstDoor.png"
    #define DG_SECOND_DOOR_W "Asset/Dungeon_Water/SecondDoor.png"
    #define DG_BOSS_DOOR_W "Asset/Dungeon_Water/DoorBoss.png"
    #define DG_END_DOOR_W "Asset/Dungeon_Water/DoorEnd.png"

    #define DUNGEON_S_MAP "Asset/Dungeon_Sand/MapSandDG.png"
    #define DUNGEON_S_RED "Asset/Dungeon_Sand/RedSand.png"

    #define DG_FIRST_DOOR_S "Asset/Dungeon_Sand/FirstDoor.png"
    #define DG_BOSS_DOOR_S "Asset/Dungeon_Sand/DoorBoss.png"
    #define DG_END_DOOR_S "Asset/Dungeon_Sand/DoorEnd.png"
    #define DG_SAND_ROCK "Asset/Dungeon_Sand/RedRock.png"

    #define DUNGEON_M_MAP "Asset/Dungeon_Mountain/MapMountain.png"
    #define DUNGEON_M_RED "Asset/Dungeon_Mountain/RedMountain.png"

    #define DG_FIRST_DOOR_M "Asset/Dungeon_Mountain/FirstDoor.png"
    #define DG_BOSS_DOOR_M "Asset/Dungeon_Mountain/BossDoor.png"
    #define DG_END_DOOR_M "Asset/Dungeon_Mountain/EndDoor.png"

    #define DUNGEON_L_MAP "Asset/Dungeon_Lava/Map_Lava.png"
    #define DUNGEON_L_RED "Asset/Dungeon_Lava/RedLava.png"

    #define DG_BOSS_DOOR_L "Asset/Dungeon_Lava/BossDoor.png"

    #define RED_WA "Asset/Dungeon_Forest/RedWaterForest.png"


typedef struct dg_door_for_s {
    sfSprite *door;
    sfImage *door_img;
    int open;
} dg_door_for_t;

typedef struct dg_arena_s {
    int start_fight;
    int wave;
    int win;
    sfRectangleShape *trigger;
    sfSprite *border;
    sfRectangleShape *box;
    sfText *text;
    sfText *nb;
} dg_arena_t;

typedef struct dg_forest_s {
    sfSprite *map;
    sfImage *red_map;
    sfTexture *door_empty;
    sfTexture *door_silver;
    sfTexture *door_gold;
    dg_door_for_t **door;
    sfSprite *silver_key1;
    sfSprite *silver_key2;
    sfSprite *gold_key;
    sfSprite *gold_key2;
    sfClock *clock_key;
    sfTime time_key;
    float seconds_key;
    sfIntRect key_rect;
    dg_arena_t *arena;
} dg_forest_t;

typedef struct dg_water_s {
    sfSprite *map;
    sfImage *red_map;
    sfTexture *door_empty;
    sfTexture *door_silver;
    sfTexture *door_gold;
    dg_door_for_t **door;
    sfSprite *silver_key1;
    sfSprite *silver_key2;
    sfSprite *gold_key;
    sfSprite *gold_key2;
    sfClock *clock_key;
    sfTime time_key;
    float seconds_key;
    sfIntRect key_rect;
    dg_arena_t *arena;
} dg_water_t;

typedef struct dg_sand_s {
    sfSprite *map;
    sfImage *red_map;
    sfTexture *door_empty;
    sfTexture *door_silver;
    sfTexture *door_gold;
    dg_door_for_t **door;
    sfSprite *silver_key1;
    sfSprite *silver_key2;
    sfSprite *gold_key;
    sfSprite *gold_key2;
    sfClock *clock_key;
    sfTime time_key;
    float seconds_key;
    sfIntRect key_rect;
    dg_arena_t *arena;
} dg_sand_t;

typedef struct dg_mountain_s {
    sfSprite *map;
    sfImage *red_map;
    sfTexture *door_empty;
    sfTexture *door_silver;
    sfTexture *door_gold;
    dg_door_for_t **door;
    sfSprite *silver_key1;
    sfSprite *silver_key2;
    sfSprite *gold_key;
    sfSprite *gold_key2;
    sfClock *clock_key;
    sfTime time_key;
    float seconds_key;
    sfIntRect key_rect;
    dg_arena_t *arena;
} dg_mountain_t;

typedef struct dg_lava_s {
    sfSprite *map;
    sfImage *red_map;
    sfTexture *door_empty;
    sfTexture *door_silver;
    sfTexture *door_gold;
    dg_door_for_t **door;
    sfSprite *silver_key1;
    sfSprite *silver_key2;
    sfSprite *gold_key;
    sfSprite *gold_key2;
    sfClock *clock_key;
    sfTime time_key;
    float seconds_key;
    sfIntRect key_rect;
} dg_lava_t;

typedef struct dg_hud_s {
    sfSprite *silver_key;
    sfSprite *gold_key;
    sfText *gold_text;
    sfText *silver_text;
} dg_hud_t;

typedef struct dg_s {
    int silver_key;
    int gold_key;
    int in_dungeon;
    dg_forest_t *dg_forest;
    dg_water_t *dg_water;
    dg_sand_t *dg_sand;
    dg_mountain_t *dg_mountain;
    dg_lava_t *dg_lava;
    dg_hud_t *dg_hud;
} dg_t;

typedef struct door_s {
    sfRectangleShape *door;
    sfVector2f coord;
    int state;
    int use;
} door_t;

typedef struct door_cave_s {
    sfRectangleShape *door;
    sfVector2f coord;
} door_cave_t;

#endif /* !DONJON_H_ */
