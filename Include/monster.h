/*
** EPITECH PROJECT, 2024
** monster.h
** File description:
** monster
*/

#ifndef MONSTER_H_
    #define MONSTER_H_

    #include <SFML/Graphics.h>

    #define SLIME "Asset/Monster/Slime/Slime.png"
    #define SLIME_BLUE "Asset/Monster/Slime/SlimeBlue.png"
    #define SLIME_D "Asset/Monster/Slime/Slime_Degat.png"

    #define GHOST "Asset/Monster/Ghost/Ghost.png"
    #define GHOST_LEFT "Asset/Monster/Ghost/Ghost_Left.png"
    #define GHOST_RIGHT "Asset/Monster/Ghost/Ghost_Right.png"
    #define GHOST_LEFT_R "Asset/Monster/Ghost/Ghost_Left_Red.png"
    #define GHOST_RIGHT_R "Asset/Monster/Ghost/Ghost_Right_Red.png"

    #define CRAB "Asset/Monster/Crab/Crab.png"
    #define CRAB_RED "Asset/Monster/Crab/Red_Crab.png"

    #define SNAKE_RIGHT "Asset/Monster/Snake/Cobra_right.png"
    #define SNAKE_LEFT "Asset/Monster/Snake/Cobra_left.png"
    #define SNAKE_RIGHT_R "Asset/Monster/Snake/Cobra_left_red.png"
    #define SNAKE_LEFT_R "Asset/Monster/Snake/Cobra_right_red.png"

    #define GOLEM_RIGHT "Asset/Monster/Golem/golem_right.png"
    #define GOLEM_LEFT "Asset/Monster/Golem/golem_left.png"
    #define GOLEM_RIGHT_R "Asset/Monster/Golem/golem_right_red.png"
    #define GOLEM_LEFT_R "Asset/Monster/Golem/golem_left_red.png"

    #define DOG_RIGHT "Asset/Monster/Dog/dog_right.png"
    #define DOG_LEFT "Asset/Monster/Dog/dog_left.png"
    #define DOG_LEFT_R "Asset/Monster/Dog/dog_right_red.png"
    #define DOG_RIGHT_R "Asset/Monster/Dog/dog_left_red.png"

    #define BOSS_LEFT "Asset/Boss/Boss_Left.png"
    #define BOSS_RIGHT "Asset/Boss/Boss_Right.png"
    #define BOSS_LEFT_R "Asset/Boss/Left_red.png"
    #define BOSS_RIGHT_R "Asset/Boss/Right_red.png"
    #define BOSS_ATK "Asset/Boss/Boss_attack.png"
    #define BOSS_P "Asset/Boss/Boss_flame.png"

typedef struct proj_s {
    sfSprite *projectile;
    sfCircleShape *zone;
    int life;
} proj_t;

typedef struct boss_s {
    sfSprite *boss;
    sfTexture *boss_left;
    sfTexture *boss_right;
    sfTexture *boss_left_r;
    sfTexture *boss_right_r;
    sfTexture *boss_atk_tx;
    sfTexture *boss_proj;
    sfIntRect boss_rect;
    sfIntRect flame_rect;
    sfRectangleShape *trigger;
    sfRectangleShape *hitbox;
    sfSprite *ending;
    sfSprite *trigger_end;
    sfIntRect trigger_rect;
    int end_t;
    sfClock *clock;
    sfClock *clock_attack;
    sfClock *clock_move;
    sfClock *clock_start_atk;
    sfClock *clock_start_atk_anim;
    sfClock *clock_trigger;
    sfCircleShape *zone;
    sfVector2f player_pos;
    float life;
    int start_boss;
    int boss_atk;
    proj_t **proj;
    sfSprite *bar;
    sfRectangleShape *healt_bar;
} boss_t;

typedef struct slime_s {
    sfSprite *slime;
    sfTexture *slime_tx;
    sfCircleShape *zone;
    sfIntRect slime_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} slime_t;

typedef struct ghost_s {
    sfSprite *ghost;
    sfTexture *ghost_tx;
    sfTexture *ghost_right;
    sfTexture *ghost_r_red;
    sfTexture *ghost_l_red;
    sfCircleShape *zone;
    sfIntRect ghost_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} ghost_t;

typedef struct snake_s {
    sfSprite *snake;
    sfTexture *snake_tx;
    sfTexture *snake_right;
    sfTexture *snake_r_red;
    sfTexture *snake_l_red;
    sfCircleShape *zone;
    sfIntRect snake_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} snake_t;

typedef struct golem_s {
    sfSprite *golem;
    sfTexture *golem_tx;
    sfTexture *golem_right;
    sfTexture *golem_r_red;
    sfTexture *golem_l_red;
    sfCircleShape *zone;
    sfIntRect golem_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} golem_t;

typedef struct dog_s {
    sfSprite *dog;
    sfTexture *dog_tx;
    sfTexture *dog_right;
    sfTexture *dog_r_red;
    sfTexture *dog_l_red;
    sfCircleShape *zone;
    sfIntRect dog_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} dog_t;

typedef struct anim_monst_s {
    sfClock *clock_slime;
    sfTime time_slime;
    float seconds_slime;
    sfClock *clock_ghost;
    sfTime time_ghost;
    float seconds_ghost;
    sfClock *clock_crab;
    sfTime time_crab;
    float seconds_crab;
    sfClock *clock_snake;
    sfTime time_snake;
    float seconds_snake;
    sfClock *clock_golem;
    sfTime time_golem;
    float seconds_golem;
    sfClock *clock_dog;
    sfTime time_dog;
    float seconds_dog;
} anim_monst_t;

typedef struct crab_s {
    int change;
    int is_moving;
    sfSprite *crab;
    sfTexture *crab_tx;
    sfTexture *crab_tx_red;
    sfCircleShape *zone;
    sfIntRect crab_Rect;
    sfClock *clock;
    sfTime time;
    float seconds;
    float life;
} crab_t;

typedef struct hit_s {
    sfClock **dmg;
} hit_t;

typedef struct hiden_s {
    int *slime;
    int *ghost;
    int *snake;
    int *dog;
    int *golem;
} hiden_t;

#endif /* !MONSTER_H_ */
