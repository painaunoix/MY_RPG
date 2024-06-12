/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

static void player_attack_dungeon(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 1)
        is_ghost_atk_dg(rpg);
    if (rpg->dg->in_dungeon == 2)
        is_slime_atk_dg(rpg);
    if (rpg->dg->in_dungeon == 3)
        is_snake_atk_dg(rpg);
    if (rpg->dg->in_dungeon == 4)
        is_dog_atk_dg(rpg);
    if (rpg->dg->in_dungeon == 5) {
        is_golem_atk_dg(rpg);
    }
    is_boss_atk(rpg);
    is_prok_atk(rpg);
}

//play animation of player attack
static void animation_attack(rpg_t *rpg)
{
    if (rpg->player->player_rect.left < 384) {
        rpg->player->player_rect.left += 64;
    } else {
        rpg->player->player_rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

//knock monster
void knock_monster(rpg_t *rpg, int i)
{
    rpg->slime[i]->life -= rpg->player->atk;
    if (rpg->slime[i]->life <= 0) {
        rpg->coin->coin += 1;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
        if (rpg->qts->slime <= 4)
            rpg->qts->slime++;
        if (rpg->qts->slime == 5)
            rpg->coin->coin += 5;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->slime[i]->slime, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->slime[i]->slime, (sfVector2f) {-20, 0});
}

void is_slime_atk(rpg_t *rpg)
{
    sfFloatRect zone_pos;
    sfFloatRect player_pos1;

    for (int i = 0; i <= 8; i++) {
        zone_pos =
        sfSprite_getGlobalBounds(rpg->slime[i]->slime);
        player_pos1 =
        sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
        if (sfFloatRect_intersects(&zone_pos, &player_pos1, NULL)
        && rpg->slime[i]->life > 0) {
            sfSprite_setTexture(rpg->slime[i]->slime,
            rpg->attack->slime_degat, sfFalse);
            knock_monster(rpg, i);
        }
    }
}

//check who is attack
static void is_atk_fct(rpg_t *rpg)
{
    rpg->attack->attack = 1;
    if (rpg->dg->in_dungeon == 0) {
        is_slime_atk(rpg);
        is_ghost_atk(rpg);
        is_crab_atk(rpg);
        is_snake_atk(rpg);
        is_golem_atk(rpg);
        is_dog_atk(rpg);
    }
    player_attack_dungeon(rpg);
}

void degat_to_monster(rpg_t *rpg)
{
    is_atk_fct(rpg);
}

//link attack zone with player
void att_zone_link(rpg_t *rpg)
{
    sfVector2f pos_player = sfSprite_getPosition(rpg->player->player);

    if (rpg->player->player_axe == 2) {
        pos_player.x += 100;
        sfRectangleShape_setPosition(rpg->attack->att_zone, pos_player);
    }
    if (rpg->player->player_axe == 4) {
        pos_player.x += 30;
        sfRectangleShape_setPosition(rpg->attack->att_zone, pos_player);
    }
}

//play animation of player attack
void attack_animation(rpg_t *rpg)
{
    if (rpg->attack->attack == 1) {
        if (rpg->player->player_axe == 2) {
            sfSprite_setTexture(rpg->player->player,
            rpg->attack->player_right_att, sfTrue);
        }
        if (rpg->player->player_axe == 4) {
            sfSprite_setTexture(rpg->player->player,
            rpg->attack->player_left_att, sfTrue);
        }
        animation_attack(rpg);
    }
    slime_hit(rpg);
}
