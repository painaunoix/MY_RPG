/*
** EPITECH PROJECT, 2024
** item.h
** File description:
** item
*/

#ifndef ITEM_H_
    #define ITEM_H_

    #include <SFML/Graphics.h>

    #define ITM_STRENGHT "Asset/Item/Strenght_Crystal.png"
    #define ITM_DUCK "Asset/Item/Duck.png"
    #define ITM_AXE "Asset/Item/Axe.png"
    #define ITM_HOOK "Asset/Item/Hook.png"
    #define ITM_SPEED "Asset/Item/Speed_Crystal.png"
    #define ITM_ARMOR "Asset/Item/Armor_Crystal.png"
    #define ITM_BOMB "Asset/Item/Bomb.png"
    #define ITM_TORCH "Asset/Item/Torch.png"

    #define PILLAR "Asset/Grappling/Pillar.png"
    #define ROPE "Asset/Rope/Rope.png"

    #define CHEST_CLOSE "Asset/Chest/Chest Close.png"
    #define CHEST_OPEN "Asset/Chest/Chest Open.png"
    #define CHEST_PRC "Asset/Chest/Particle.png"
    #define CHEST_FOND "Asset/Chest/Fond.png"

    #define POTION "Asset/Item/heal_pot.png"

    #define BOMB "Asset/Bomb/Bomb_Sprite.png"
    #define ROCK "Asset/Bomb/Rock_Bomb.png"
    #define RED_CAVE "Asset/Bomb/Red_rock_cave.png"
    #define RED_ROCK "Asset/Bomb/Red_Sand.png"
    #define RED_DG "Asset/Dungeon_Sand/RedRock.png"

typedef struct chest_opn_s {
    sfText *item_name;
    sfText *quit_text;
    sfSprite *fond;
    sfSprite *particle;
    sfIntRect part_rect;
    sfTexture *item_texture;
    sfSprite *item;
    sfClock *clock;
    sfTime time;
    float seconds;
    int open;
} chest_opn_t;

typedef struct chest_s {
    int open;
    sfSprite *chest_close;
    sfSprite *chest_open;
} chest_t;

typedef struct grap_s {
    sfBool lunch;
    sfRectangleShape *rope;
    sfRectangleShape *zone;
    sfConvexShape *dis_rope;
    int idx_target;
    int axis;
} grap_t;

typedef struct grap_pillar_s {
    sfRectangleShape *pillar;
} grap_pillar_t;

typedef struct gem_s {
    sfClock *speed;
    int old_spd;
    sfBool act_spd;
    sfClock *stg;
    float old_stg;
    sfBool act_stg;
    sfClock *arm;
    int is_act;
    sfBool act_arm;
    sfSprite *sp_spd;
    sfSprite *sp_arm;
    sfSprite *sp_stg;
} gem_t;

typedef struct boat_s {
    sfTexture *boat_left;
    sfTexture *boat_right;
    int in_boat;
    sfImage *img;
    sfImage *dg;
} boat_t;

typedef struct bomb_s {
    sfRectangleShape *rect;
    sfSprite *bomb;
    sfSprite *rock;
    sfImage *img_rock;
    sfBool use;
    sfClock *cl;
    sfIntRect rec;
    sfBool use2;
} bomb_t;

#endif /* !ITEM_H_ */
