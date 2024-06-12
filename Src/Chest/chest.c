/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//init animation chest open
static void chest_open(rpg_t *rpg, char *name, char *file)
{
    sfVector2f pos_text_1 = rpg->win->center;
    sfVector2f pos_text_2 = rpg->win->center;
    sfFloatRect rect;

    rpg->chest_opn->open = 1;
    rpg->player->player_can_move = sfFalse;
    sfSprite_setPosition(rpg->chest_opn->particle, rpg->win->center);
    sfSprite_setTexture(rpg->chest_opn->item, texture(file), sfTrue);
    sfSprite_setPosition(rpg->chest_opn->item, rpg->win->center);
    sfSprite_setPosition(rpg->chest_opn->fond, rpg->win->center);
    sfText_setString(rpg->chest_opn->item_name, name);
    rect = sfText_getGlobalBounds(rpg->chest_opn->item_name);
    pos_text_1.x = rpg->win->center.x - (rect.width / 2);
    pos_text_1.y -= 290;
    sfText_setPosition(rpg->chest_opn->item_name, pos_text_1);
    rect = sfText_getGlobalBounds(rpg->chest_opn->quit_text);
    pos_text_2.x = rpg->win->center.x - (rect.width / 2);
    pos_text_2.y += 300;
    sfText_setPosition(rpg->chest_opn->quit_text, pos_text_2);
}

// display animation chest open
void animation_open(rpg_t *rpg)
{
    if (rpg->chest_opn->part_rect.left < 96) {
        rpg->chest_opn->part_rect.left += 32;
    } else {
        rpg->chest_opn->part_rect.left = 0;
    }
    sfSprite_setTextureRect(rpg->chest_opn->particle,
    rpg->chest_opn->part_rect);
}

//create chest and set position
static sfSprite *create_chest(rpg_t *rpg, int x, int y, int i)
{
    sfVector2f scale = {2, 2};
    sfVector2f center = {x, y};
    sfSprite *sprite;

    sprite = sfSprite_create();
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, center);
    sfSprite_setTexture(sprite, texture(CHEST_CLOSE), sfTrue);
    rpg->chest[i + 1] = NULL;
    return sprite;
}

//malloc scruct chest
void start_chest(rpg_t *rpg, int x, int y, int i)
{
    rpg->chest[i] = malloc(sizeof(chest_t));
    rpg->chest[i]->chest_close = create_chest(rpg, x, y, i);
    rpg->chest[i]->open = 0;
}

//darw component of animation
void draw_particle(rpg_t *rpg)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->chest_opn->fond, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->chest_opn->item_name, NULL);
    sfRenderWindow_drawText(rpg->win->window, rpg->chest_opn->quit_text, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->chest_opn->particle, NULL);
    sfRenderWindow_drawSprite(rpg->win->window, rpg->chest_opn->item, NULL);
}

//draw chest on map
void draw_chest(rpg_t *rpg)
{
    for (int i = 0; rpg->chest[i] != NULL; i++)
        sfRenderWindow_drawSprite(rpg->win->window,
        rpg->chest[i]->chest_close, NULL);
}

static void chech_chest_part2(rpg_t *rpg, int i)
{
    if (i == 5) {
        chest_open(rpg, "Duck", ITM_DUCK);
        sfSprite_setTexture(rpg->tuto_item->tuto_item_sprite,
        rpg->tuto_item->tuto_dock, sfTrue);
    }
    if (i == 6 && rpg->dg->in_dungeon != 3) {
        chest_open(rpg, "Torch", ITM_TORCH);
        sfSprite_setTexture(rpg->tuto_item->tuto_item_sprite,
        rpg->tuto_item->tuto_torch, sfTrue);
    }
    if (i == 7) {
        chest_open(rpg, "Bomb", ITM_BOMB);
        sfSprite_setTexture(rpg->tuto_item->tuto_item_sprite,
        rpg->tuto_item->tuto_bomb, sfTrue);
    }
}

//check witch chest is open
static void check_chest(rpg_t *rpg, int i)
{
    if (i == 0)
        chest_open(rpg, "Fortified Axe", ITM_AXE);
    if (i == 1) {
        chest_open(rpg, "Grappling Hook", ITM_HOOK);
        sfSprite_setTexture(rpg->tuto_item->tuto_item_sprite,
        rpg->tuto_item->tuto_hook, sfTrue);
    }
    if (i == 2)
        chest_open(rpg, "Speed Crystal", ITM_SPEED);
    if (i == 3)
        chest_open(rpg, "Armor Crystal", ITM_ARMOR);
    if (i == 4)
        chest_open(rpg, "Strenght Crystal", ITM_STRENGHT);
    chech_chest_part2(rpg, i);
}

static void interact_chest_part2(rpg_t *rpg)
{
    sfFloatRect chest_pos;
    sfFloatRect player_bounds;

    for (int i = 0; rpg->chest[i] != NULL; i++) {
        player_bounds = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
        chest_pos = sfSprite_getGlobalBounds(rpg->chest[i]->chest_close);
        if (sfFloatRect_intersects(&chest_pos, &player_bounds, NULL) &&
            sfKeyboard_isKeyPressed(sfKeyE) && rpg->chest[i]->open == 0) {
            rpg->chest[i]->open = 1;
            sfSprite_setTexture(rpg->chest[i]->chest_close,
            sfTexture_createFromFile(CHEST_OPEN, NULL), sfTrue);
            check_chest(rpg, i);
        }
    }
}

//check if player try to use chest
void interact_chest(rpg_t *rpg)
{
    int y = 0;
    sfVector2f pos;
    sfFloatRect chest_pos;
    sfFloatRect player_bounds;

    if (rpg->chest_opn->open == 1)
        rpg->player->player_can_move = sfFalse;
    for (int i = 0; rpg->chest[i] != NULL; i++) {
        player_bounds = sfRectangleShape_getGlobalBounds(rpg->player->hitbox);
        chest_pos = sfSprite_getGlobalBounds(rpg->chest[i]->chest_close);
        if (sfFloatRect_intersects(&chest_pos, &player_bounds, NULL))
            close_chest(rpg, i);
    }
    interact_chest_part2(rpg);
}
