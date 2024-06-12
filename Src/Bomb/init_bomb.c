/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init bomb
*/

#include "../../Include/my.h"

static void anim_bomb_split(rpg_t *rpg, int i)
{
    if (rpg->bomb[i]->rec.left < 288 - 32) {
        rpg->bomb[i]->rec.left += 32;
        sfClock_restart(rpg->bomb[i]->cl);
    } else {
        rpg->bomb[i]->use2 = sfFalse;
        rpg->bomb[i]->rec.left = 0;
        rpg->bomb[i]->use = sfFalse;
    }
    sfSprite_setTextureRect(rpg->bomb[i]->bomb,
    rpg->bomb[i]->rec);
}

void anim_bomb(rpg_t *rpg)
{
    sfTime time;
    float second;

    for (int i = 0; rpg->bomb[i] != NULL; i++) {
        time = sfClock_getElapsedTime(rpg->bomb[i]->cl);
        second = sfTime_asSeconds(time);
        if (second > 0.2 && rpg->bomb[i]->use == sfTrue) {
            anim_bomb_split(rpg, i);
        }
    }
}

void is_player_bomb(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect rock;

    for (int i = 0; rpg->bomb[i]; i++) {
        rock = sfRectangleShape_getGlobalBounds(rpg->bomb[i]->rect);
        if (sfFloatRect_intersects(&player, &rock, NULL) &&
        rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
        sfEvtKeyReleased && is_in_frame(rpg, ITM_BOMB) == 0) {
            rpg->bomb[i]->use = sfTrue;
        }
    }
}

void init_bomb_2(rpg_t *rpg)
{
    rpg->bomb[1]->rock = create_sprite((sfVector2f) {0.17, 0.17}, (sfVector2f)
    {10126, 6346}, ROCK);
    rpg->bomb[2]->rock = create_sprite((sfVector2f) {0.25, 0.25}, (sfVector2f)
    {4303, 1645}, ROCK);
    rpg->bomb[0]->bomb = create_sprite_rect((sfVector2f) {3, 3}, (sfVector2f)
    {6998, 5130}, BOMB, rpg->bomb[0]->rec);
    rpg->bomb[1]->bomb = create_sprite_rect((sfVector2f) {3, 3}, (sfVector2f)
    {10181, 6417}, BOMB, rpg->bomb[1]->rec);
    rpg->bomb[2]->bomb = create_sprite_rect((sfVector2f) {3, 3}, (sfVector2f)
    {4406, 1791}, BOMB, rpg->bomb[2]->rec);
    rpg->bomb[0]->img_rock = sfImage_createFromFile(RED_CAVE);
    rpg->bomb[1]->img_rock = sfImage_createFromFile(RED_ROCK);
    rpg->bomb[2]->img_rock = sfImage_createFromFile(RED_DG);
}

void init_bomb(rpg_t *rpg)
{
    rpg->bomb = malloc(sizeof(bomb_t *) * 4);
    for (int i = 0; i != 3; i++) {
        rpg->bomb[i] = malloc(sizeof(bomb_t));
        rpg->bomb[i]->rec = make_rect(22, 32);
        rpg->bomb[i]->use = sfFalse;
        rpg->bomb[i]->use2 = sfTrue;
        rpg->bomb[i]->cl = sfClock_create();
        rpg->bomb[i + 1] = NULL;
    }
    rpg->bomb[0]->rect = create_rectangle((sfVector2f) {80, 80}, (sfVector2f)
    {7004, 5178});
    rpg->bomb[1]->rect = create_rectangle((sfVector2f) {220, 320}, (sfVector2f)
    {10121, 6306});
    rpg->bomb[2]->rect = create_rectangle((sfVector2f) {400, 80}, (sfVector2f)
    {4253, 1946});
    rpg->bomb[0]->rock = create_sprite((sfVector2f) {0.06, 0.06}, (sfVector2f)
    {7009, 5128}, ROCK);
    init_bomb_2(rpg);
}

static void display_bomb_2(rpg_t *rpg)
{
    if (rpg->dg->in_dungeon == 3) {
        if (rpg->bomb[2]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[2]->rock,
            NULL);
        if (rpg->bomb[2]->use == sfTrue && rpg->bomb[2]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[2]->bomb,
            NULL);
    }
}

void display_bomb(rpg_t *rpg)
{
    is_player_bomb(rpg);
    anim_bomb(rpg);
    if (rpg->dg->in_dungeon == 0) {
        if (rpg->bomb[0]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[0]->rock,
            NULL);
        if (rpg->bomb[1]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[1]->rock,
            NULL);
        if (rpg->bomb[0]->use == sfTrue && rpg->bomb[0]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[0]->bomb,
            NULL);
        if (rpg->bomb[1]->use == sfTrue && rpg->bomb[1]->use2 == sfTrue)
            sfRenderWindow_drawSprite(rpg->win->window, rpg->bomb[1]->bomb,
            NULL);
    }
    display_bomb_2(rpg);
}
