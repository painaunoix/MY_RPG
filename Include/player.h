/*
** EPITECH PROJECT, 2024
** player.h
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_

    #include <SFML/Graphics.h>

    #define PLAYER_LEFT_MOVE "Asset/Player/Player2.png"
    #define PLAYER_RIGHT_MOVE "Asset/Player/Player.png"
    #define PLAYER_LEFT_IDLE "Asset/Player/Player4.png"
    #define PLAYER_RIGHT_IDLE "Asset/Player/Player3.png"
    #define PLAYER_ATTACK_LEFT "Asset/Player/AttackLeft.png"
    #define PLAYER_ATTACK_RIGHT "Asset/Player/AttackRight.png"
    #define PLAYER_BOAT_LEFT "Asset/Player/Player_boat_left.png"
    #define PLAYER_BOAT_RIGHT "Asset/Player/Player_boat_right.png"

    #define WALK "Song/walk.ogg"
    #define SLASH "Song/axe_slash.ogg"

typedef struct walk_s {
    sfMusic *walk;
    sfBool start;
    sfBool stop;
} walk_t;

typedef struct player_s {
    int player_axe;
    float player_speed;
    float atk;
    sfBool player_can_move;
    sfBool player_move;
    sfSprite *player;
    sfIntRect player_rect;
    sfVector2f movement;
    sfRectangleShape *hitbox;
    sfVector2f previousPosition;
    sfTexture *player_left_move;
    sfTexture *player_left_idle;
    sfTexture *player_right_move;
    sfTexture *player_right_idle;
    sfClock *clock;
    sfTime time;
    float seconds;
    sfView *view;
    sfVector2f prev;
    int cur_zone;
} player_t;

typedef struct skills_s {
    sfRectangleShape ***tab_up;
    sfText *skill_txt;
    sfText *nb_point;
    int health;
    int strenght;
    int armor;
    int speed;
    int mana;
    int luck;
    int point;
    int xp;
} skills_t;

typedef struct health_s {
    sfRectangleShape **pv_tab;
    sfTexture *pv_fill;
    sfTexture *pv_empty;
    int pv;
    int total_pv;
    sfVector2f pos;
    sfClock *heal_pot;
} health_t;

typedef struct mana_s {
    sfRectangleShape *mana_sp;
    sfRectangleShape *mana_bar;
    sfTexture *mana_fill;
    sfTexture *mana_empty;
    int mana;
    sfClock *cl_mana;
} mana_t;

typedef struct attack_s {
    sfRectangleShape *att_zone;
    sfTexture *player_right_att;
    sfTexture *player_left_att;
    sfTexture *slime_degat;
    sfClock *clock_attack;
    sfTime time_attack;
    float seconds_attack;
    sfClock *clock;
    sfTime time;
    float seconds;
    int attack;
    sfMusic *axe_slash;
    sfBool start;
    sfBool stop;
} attack_t;

typedef struct coin_s {
    int coin;
}coin_t;

typedef struct die_s {
    sfText *restart;
    sfText *msg;
    sfBool die;
    sfRectangleShape *screen;
    sfRectangleShape *bt;
}die_t;

typedef struct tuto_s {
    int step;
    sfText *step1;
    sfText *step2;
    sfText *step3;
    sfText *step4;
    sfText *step5;
}tuto_t;

#endif /* !PLAYER_H_ */
