/*
** EPITECH PROJECT, 2024
** init player
** File description:
** file for init struct player
*/

#include "../../Include/my.h"

//init struct player
void init_player(rpg_t *rpg)
{
    rpg->player = malloc(sizeof(player_t));
    rpg->player->player_move = sfFalse;
    rpg->player->player_axe = 0;
    rpg->player->player_speed = 7;
    rpg->player->player_rect = make_rect(32, 64);
    rpg->player->player = create_sprite_rect((sfVector2f) {3, 3},
        (sfVector2f) {3650, 9600}, PLAYER_LEFT_MOVE, rpg->player->player_rect);
    rpg->player->player_right_move = texture(PLAYER_RIGHT_MOVE);
    rpg->player->player_left_move = texture(PLAYER_LEFT_MOVE);
    rpg->player->player_right_idle = texture(PLAYER_RIGHT_IDLE);
    rpg->player->player_left_idle = texture(PLAYER_LEFT_IDLE);
    rpg->player->view = sfView_createFromRect((sfFloatRect) {0, 0, 1720, 880});
    rpg->player->hitbox = create_rectangle((sfVector2f) {30, 40},
    (sfVector2f) {0, 0});
    rpg->player->player_can_move = sfFalse;
    rpg->player->atk = 1;
    rpg->player->cur_zone = 0;
}

//init struct attack
void init_att_zone(rpg_t *rpg)
{
    rpg->attack = malloc(sizeof(attack_t));
    rpg->attack->att_zone = create_rectangle((sfVector2f) {70, 80},
    sfSprite_getPosition(rpg->player->player));
    rpg->attack->attack = 0;
    rpg->attack->slime_degat = sfTexture_createFromFile(SLIME_D, NULL);
    rpg->attack->player_right_att =
    sfTexture_createFromFile(PLAYER_ATTACK_RIGHT, NULL);
    rpg->attack->player_left_att =
    sfTexture_createFromFile(PLAYER_ATTACK_LEFT, NULL);
    rpg->attack->seconds = 0;
}

//init struct coin
void init_coin(rpg_t *rpg)
{
    rpg->coin = malloc(sizeof(coin_t));
    rpg->coin->coin = 0;
}
