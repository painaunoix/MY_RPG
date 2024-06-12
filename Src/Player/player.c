/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//link hitbox
void link_hitbox(rpg_t *rpg)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->player);

    if (rpg->boat->in_boat == 0) {
        pos.x += 80;
        pos.y += 25;
        sfRectangleShape_setPosition(rpg->player->hitbox, pos);
    }
    if (rpg->boat->in_boat == 1) {
        pos.x += 20;
        pos.y += 25;
        sfRectangleShape_setPosition(rpg->player->hitbox, pos);
    }
}

//check if the moving key is press
static void player_is_moving(rpg_t *rpg)
{
    if (sfKeyboard_isKeyPressed(sfKeyZ) || sfKeyboard_isKeyPressed(sfKeyD)
    || sfKeyboard_isKeyPressed(sfKeyS) || sfKeyboard_isKeyPressed(sfKeyQ))
        rpg->player->player_move = sfTrue;
    else
        rpg->player->player_move = sfFalse;
}

//handle diagonal
static void handle_dia(rpg_t *rpg, int x, int y)
{
    if (x > rpg->player->movement.x && y > rpg->player->movement.y) {
        rpg->player->movement.x = x - (rpg->player->player_speed / 1.5);
        rpg->player->movement.y = y - (rpg->player->player_speed / 1.5);
    }
    if (x < rpg->player->movement.x && y < rpg->player->movement.y) {
        rpg->player->movement.x = x + (rpg->player->player_speed / 1.5);
        rpg->player->movement.y = y + (rpg->player->player_speed / 1.5);
    }
    if (x > rpg->player->movement.x && y < rpg->player->movement.y) {
        rpg->player->movement.x = x - (rpg->player->player_speed / 1.5);
        rpg->player->movement.y = y + (rpg->player->player_speed / 1.5);
    }
    if (x < rpg->player->movement.x && y > rpg->player->movement.y) {
        rpg->player->movement.x = x + (rpg->player->player_speed / 1.5);
        rpg->player->movement.y = y - (rpg->player->player_speed / 1.5);
    }
}

//swap axis
static void player_axis(rpg_t *rpg)
{
    int x = rpg->player->movement.x;
    int y = rpg->player->movement.y;

    player_is_moving(rpg);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        rpg->player->movement.y -= rpg->player->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyS))
        rpg->player->movement.y += rpg->player->player_speed;
    if (sfKeyboard_isKeyPressed(sfKeyQ)) {
        rpg->player->movement.x -= rpg->player->player_speed;
        rpg->player->player_axe = 4;
    }
    if (sfKeyboard_isKeyPressed(sfKeyD)) {
        rpg->player->movement.x += rpg->player->player_speed;
        rpg->player->player_axe = 2;
    }
    handle_dia(rpg, x, y);
}

//make the player move
void player(rpg_t *rpg)
{
    rpg->player->movement = (sfVector2f) {0.0f, 0.0f};
    if (rpg->player->player_can_move == sfTrue)
        if (rpg->grap->lunch == sfFalse)
            player_axis(rpg);
    rpg->player->prev = sfSprite_getPosition(rpg->player->player);
    sfSprite_move(rpg->player->player, rpg->player->movement);
    all_colli(rpg);
}

//play animation idle
static void animation_idle(rpg_t *rpg)
{
    if (rpg->player->player_rect.left < 256) {
        rpg->player->player_rect.left += 64;
    } else {
        rpg->player->player_rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

//play animation move
static void animation_move(rpg_t *rpg)
{
    if (rpg->player->player_rect.left < 448) {
        rpg->player->player_rect.left += 64;
    } else {
        rpg->player->player_rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->player->player, rpg->player->player_rect);
}

//play animation run
void run_animation(rpg_t *rpg)
{
    if (rpg->player->player_move == sfTrue) {
        if (rpg->player->player_axe == 2 && rpg->attack->attack == 0)
            sfSprite_setTexture(rpg->player->player,
            sfTexture_createFromFile(PLAYER_RIGHT_MOVE, NULL), sfTrue);
        if (rpg->player->player_axe == 4 && rpg->attack->attack == 0)
            sfSprite_setTexture(rpg->player->player,
            sfTexture_createFromFile(PLAYER_LEFT_MOVE, NULL), sfTrue);
        animation_move(rpg);
        rpg->walk_sound->start = sfTrue;
    } else {
        if (rpg->player->player_axe == 2 && rpg->attack->attack == 0)
            sfSprite_setTexture(rpg->player->player,
            sfTexture_createFromFile(PLAYER_RIGHT_IDLE, NULL), sfTrue);
        if (rpg->player->player_axe == 4 && rpg->attack->attack == 0)
            sfSprite_setTexture(rpg->player->player,
            sfTexture_createFromFile(PLAYER_LEFT_IDLE, NULL), sfTrue);
        animation_idle(rpg);
        rpg->walk_sound->stop = sfTrue;
    }
}

//move view for follow the player
void move_view(rpg_t *rpg)
{
    sfFloatRect playerBounds = sfSprite_getGlobalBounds(rpg->player->player);
    sfVector2f playerPos = sfSprite_getPosition(rpg->player->player);
    sfColor pixelColor;
    sfVector2f new_pos;

    new_pos.x = playerPos.x + playerBounds.width / 2;
    new_pos.y = playerPos.y + playerBounds.height / 2;
    sfView_setCenter(rpg->player->view, new_pos);
}

//draw player sprite
void draw_player(rpg_t *rpg)
{
    adapt_rope(rpg);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->player->player, NULL);
}
