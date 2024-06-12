/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hit player
*/

#include "../../Include/my.h"

void init_hit(rpg_t *rpg)
{
    rpg->hit = malloc(sizeof(hit_t));
    rpg->hit->dmg = malloc(sizeof(sfClock *) * 8);
    for (int i = 0; i != 7; i++)
        rpg->hit->dmg[i] = sfClock_create();
}

void make_armor(rpg_t *rpg, int atk, char *str, int i)
{
    int nb = 0;

    if (hit_hiden(rpg, str, i) == 0) {
        srand(time(NULL));
        nb = rand() % 100;
        if (nb < 100 - (rpg->skill->armor * 10) + rpg->gem->is_act)
            rpg->health->pv -= atk;
        if (rpg->health->pv < 0)
            rpg->health->pv = 0;
    }
}

static void dog_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect dog;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[0]);
    float second = sfTime_asSeconds(time);

    for (int i = 0; rpg->dog[i]; i++) {
        dog = sfSprite_getGlobalBounds(rpg->dog[i]->dog);
        if (sfFloatRect_intersects(&player, &dog, NULL) && second > 1.5 &&
        rpg->dog[i]->life > 0) {
            make_armor(rpg, 2, "dog", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[0]);
        }
    }
}

void ghost_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect ghost;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[1]);
    float second = sfTime_asSeconds(time);

    for (int i = 0; rpg->ghost[i]; i++) {
        ghost = sfSprite_getGlobalBounds(rpg->ghost[i]->ghost);
        if (sfFloatRect_intersects(&player, &ghost, NULL) && second > 1.5 &&
        rpg->ghost[i]->life > 0) {
            make_armor(rpg, 1, "ghost", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[1]);
        }
    }
}

void snake_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect snake;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[2]);
    float second = sfTime_asSeconds(time);

    for (int i = 0; rpg->snake[i]; i++) {
        snake = sfSprite_getGlobalBounds(rpg->snake[i]->snake);
        if (sfFloatRect_intersects(&player, &snake, NULL) && second > 2 &&
        rpg->snake[i]->life > 0) {
            make_armor(rpg, 2, "snake", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[2]);
        }
    }
}

static void golem_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect golem;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[3]);
    float second = sfTime_asSeconds(time);

    for (int i = 0; rpg->golem[i]; i++) {
        golem = sfSprite_getGlobalBounds(rpg->golem[i]->golem);
        if (sfFloatRect_intersects(&player, &golem, NULL) && second > 3 &&
        rpg->golem[i]->life > 0) {
            make_armor(rpg, 3, "golem", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[3]);
        }
    }
    dog_hit(rpg);
    ghost_hit(rpg);
    snake_hit(rpg);
    boss_hit(rpg);
    proj_hit(rpg);
}

static void reset_healt(rpg_t *rpg)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect restart = sfText_getGlobalBounds(rpg->die->restart);

    if (sfFloatRect_contains(&restart, rpg->win->mouse.x, rpg->win->mouse.y)
    == sfTrue) {
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            sfText_setFillColor(rpg->die->restart, sfRed);
            sfSprite_setPosition(rpg->player->player, rpg->health->pos);
            rpg->player->player_can_move = sfTrue;
            rpg->die->die = sfFalse;
            rpg->dg->in_dungeon = 0;
            rpg->boss->start_boss = 0;
            rpg->health->pv = rpg->health->total_pv;
            sfText_setFillColor(rpg->die->restart, sfRed);
        } else {
            sfText_setFillColor(rpg->die->restart, sfWhite);
        }
    } else {
        sfText_setFillColor(rpg->die->restart, sfBlack);
    }
}

static int player_die(rpg_t *rpg)
{
    if (rpg->health->pv <= 0) {
        rpg->player->player_can_move = sfFalse;
        rpg->die->die = sfTrue;
        reset_healt(rpg);
        return (1);
    }
    if (rpg->com->wait_in == sfFalse && rpg->esc->esc_check != 1 &&
    rpg->inv->open != 1 && rpg->set->open != 1 && rpg->trader->open != 1 &&
    rpg->qts->open != 1 && rpg->die->die != sfTrue &&
    rpg->chest_opn->open != 1 && rpg->map->open != 1 &&
    rpg->tuto_item->tuto_open != 1) {
        rpg->player->player_can_move = sfTrue;
    }
}

void slime_hit(rpg_t *rpg)
{
    sfFloatRect player = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
    sfFloatRect slime;
    sfTime time = sfClock_getElapsedTime(rpg->hit->dmg[4]);
    float second = sfTime_asSeconds(time);

    if (player_die(rpg) == 1 || rpg->die->die == sfTrue)
        return;
    if (rpg->debug->die == sfFalse)
        return;
    for (int i = 0; rpg->slime[i]; i++) {
        slime = sfSprite_getGlobalBounds(rpg->slime[i]->slime);
        if (sfFloatRect_intersects(&player, &slime, NULL) && second > 1 &&
        rpg->slime[i]->life > 0) {
            make_armor(rpg, 1, "slime", i);
            set_health(rpg);
            sfClock_restart(rpg->hit->dmg[4]);
        }
    }
    golem_hit(rpg);
}
