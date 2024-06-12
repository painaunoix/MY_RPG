/*
** EPITECH PROJECT, 2024
** boat_move.c
** File description:
** movement for boat
*/

#include "../../Include/my.h"

int is_second(sfClock *clock, float nb)
{
    sfTime time = sfClock_getElapsedTime(clock);
    float seconds = sfTime_asSeconds(time);

    if (seconds > nb) {
        sfClock_restart(clock);
        return 1;
    }
    return 0;
}

static void reset_proj(rpg_t *rpg)
{
    for (int i = 0; rpg->boss->proj[i]; i++)
        rpg->boss->proj[i]->life = 1;
    sfSprite_setPosition(rpg->boss->proj[0]->projectile,
    (sfVector2f) {6879, 2007});
    sfSprite_setPosition(rpg->boss->proj[1]->projectile,
    (sfVector2f) {8027, 2011});
    sfSprite_setPosition(rpg->boss->proj[2]->projectile,
    (sfVector2f) {7461, 1087});
}

void link_hitbox_boss(rpg_t *rpg)
{
    sfVector2f boss = sfSprite_getPosition(rpg->boss->boss);

    boss.x += 180;
    boss.y += 150;
    sfRectangleShape_setPosition(rpg->boss->hitbox, boss);
}

int boss_attack(rpg_t *rpg)
{
    rpg->boss->player_pos = sfRectangleShape_getPosition(rpg->player->hitbox);
    if (rpg->boss->boss_atk == 0)
        move_to_player_boss(rpg, rpg->boss->player_pos);
    move_to_player_proj(rpg, rpg->boss->player_pos);
    if (is_second(rpg->boss->clock_start_atk, 5) == 1 &&
    rpg->boss->start_boss == 1) {
        reset_proj(rpg);
        rpg->boss->boss_atk = 1;
        sfSprite_setTexture(rpg->boss->boss,
        rpg->boss->boss_atk_tx, sfFalse);
    }
}

static void init_proj(rpg_t *rpg, int i, int x, int y)
{
    rpg->boss->proj[i] = malloc(sizeof(proj_t));
    rpg->boss->proj[i]->projectile = create_sprite_rect(
    (sfVector2f) {5, 5}, (sfVector2f) {x, y}, BOSS_P, rpg->boss->flame_rect);
    rpg->boss->proj[i]->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->boss->proj[i]->zone, (sfVector2f) {500, 500});
    sfCircleShape_setPosition(rpg->boss->proj[i]->zone,
    (sfVector2f) {7139, 1296});
    sfCircleShape_setRadius(rpg->boss->proj[i]->zone, 600);
    sfCircleShape_setFillColor(rpg->boss->proj[i]->zone, sfTransparent);
    sfCircleShape_setOutlineThickness(rpg->boss->proj[i]->zone, 5);
    sfCircleShape_setOutlineColor(rpg->boss->proj[i]->zone, sfWhite);
    rpg->boss->proj[i]->life = 1;
    rpg->boss->proj[i + 1] = NULL;
}

void trigger_start_boss(rpg_t *rpg)
{
    sfFloatRect trigger = sfRectangleShape_getGlobalBounds(rpg->boss->trigger);
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);

    if (sfFloatRect_intersects(&trigger, &player, NULL) &&
    rpg->boss->start_boss == 0 && rpg->dg->in_dungeon == 5) {
        sfSprite_setPosition(rpg->boss->boss, (sfVector2f) {7242, 1456});
        rpg->boss->life = 60;
        remake_heal_bar(rpg);
        rpg->boss->start_boss = 1;
    }
}

static void init_boss_spli(rpg_t *rpg)
{
    rpg->boss->zone = sfCircleShape_create();
    sfCircleShape_setOrigin(rpg->boss->zone, (sfVector2f) {300, 300});
    sfCircleShape_setPosition(rpg->boss->zone, (sfVector2f) {7139, 1296});
    sfCircleShape_setRadius(rpg->boss->zone, 600);
    sfCircleShape_setFillColor(rpg->boss->zone, sfTransparent);
    sfCircleShape_setOutlineThickness(rpg->boss->zone, 5);
    sfCircleShape_setOutlineColor(rpg->boss->zone, sfWhite);
    rpg->boss->proj = malloc(sizeof(proj_t *) * 4);
    init_proj(rpg, 0, 6879, 2007);
    init_proj(rpg, 1, 8027, 2011);
    init_proj(rpg, 2, 7461, 1087);
    rpg->boss->bar = create_sprite((sfVector2f) {1, 1}, (sfVector2f)
    {0, 0}, LOAD_BORDER);
    rpg->boss->healt_bar = create_rectangle((sfVector2f) {1200, 60},
    (sfVector2f) {0, 0});
    sfRectangleShape_setFillColor(rpg->boss->healt_bar, sfRed);
    sfRectangleShape_setOutlineColor(rpg->boss->healt_bar, sfRed);
    init_end(rpg);
}

void init_boss(rpg_t *rpg)
{
    rpg->boss = malloc(sizeof(boss_t));
    rpg->boss->life = 60;
    rpg->boss->start_boss = 0;
    rpg->boss->boss_atk = 0;
    rpg->boss->trigger = create_rectangle((sfVector2f) {200, 200},
    (sfVector2f) {7425, 2330});
    rpg->boss->hitbox = create_rectangle((sfVector2f) {170, 170},
    (sfVector2f) {0, 0});
    rpg->boss->boss_rect = make_rect(403, 500);
    rpg->boss->flame_rect = make_rect(32, 32);
    rpg->boss->boss_left = texture(BOSS_LEFT);
    rpg->boss->boss_right = texture(BOSS_RIGHT);
    rpg->boss->boss_left_r = texture(BOSS_LEFT_R);
    rpg->boss->boss_right_r = texture(BOSS_RIGHT_R);
    rpg->boss->boss_atk_tx = texture(BOSS_ATK);
    rpg->boss->boss = create_sprite_rect((sfVector2f) {1, 1},
    (sfVector2f) {7242, 1456}, BOSS_LEFT, rpg->boss->boss_rect);
    init_boss_spli(rpg);
}
