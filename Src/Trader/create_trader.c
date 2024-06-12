/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** create trader
*/

#include "../../Include/my.h"

static void is_buy_click(rpg_t *rpg, int i)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(rpg->win->window);
    sfFloatRect buy;

    buy = sfText_getGlobalBounds(rpg->tra_but[i]->buy);
    if (sfFloatRect_contains(&buy, rpg->win->mouse.x, rpg->win->mouse.y)
    == sfTrue) {
        if (sfMouseLeft == rpg->win->event.mouseButton.button
        && sfEvtMouseButtonReleased == rpg->win->event.type && rpg->coin->coin
        >= rpg->tra_but[i]->price) {
            sfText_setFillColor(rpg->tra_but[i]->buy, sfRed);
            rpg->coin->coin -= rpg->tra_but[i]->price;
            set_tex_sl(rpg, rpg->tra_but[i]->name);
        } else
            sfText_setFillColor(rpg->tra_but[i]->buy, sfWhite);
    } else
        sfText_setFillColor(rpg->tra_but[i]->buy,
        sfColor_fromRGB(253, 212, 103));
}

//check if the user want to buy itel
void is_button_click(rpg_t *rpg)
{
    sfFloatRect pos_rec;

    if (rpg->game_state != 1)
        return;
    for (int i = 0; i != 4; i++)
        is_buy_click(rpg, i);
}

//check if the user want to interact with trader
void talk_trader(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->player->player);
    sfFloatRect trader = sfRectangleShape_getGlobalBounds(rpg->trader->rect);

    if (sfFloatRect_intersects(&player, &trader, NULL) &&
    rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
    sfEvtKeyReleased && rpg->trader->open == 0) {
        rpg->trader->open = 1;
        rpg->player->player_can_move = sfFalse;
        return;
    }
    if (sfFloatRect_intersects(&player, &trader, NULL) &&
    rpg->win->event.key.code == sfKeyE && rpg->win->event.type ==
    sfEvtKeyReleased) {
        rpg->trader->open = 0;
        rpg->player->player_can_move = sfTrue;
    }
    is_button_click(rpg);
}

void place_shop(rpg_t *rpg)
{
    sfText_setPosition(rpg->tra_but[0]->cost, set_pos_mid_txt(rpg,
    rpg->tra_but[0]->cost, 375, 0));
    sfText_setPosition(rpg->tra_but[1]->cost, set_pos_mid_txt(rpg,
    rpg->tra_but[1]->cost, 465, 0));
    sfText_setPosition(rpg->tra_but[2]->cost, set_pos_mid_txt(rpg,
    rpg->tra_but[2]->cost, 555, 0));
    sfText_setPosition(rpg->tra_but[0]->buy, set_pos_mid_txt(rpg,
    rpg->tra_but[0]->buy, 370, 150));
    sfText_setPosition(rpg->tra_but[1]->buy, set_pos_mid_txt(rpg,
    rpg->tra_but[1]->buy, 460, 150));
    sfText_setPosition(rpg->tra_but[2]->buy, set_pos_mid_txt(rpg,
    rpg->tra_but[2]->buy, 550, 150));
    sfText_setPosition(rpg->trader->coin, set_pos_mid_txt(rpg,
    rpg->trader->coin, 300, 0));
    sfRectangleShape_setPosition(rpg->trader->back, set_pos_mid_rec
    (rpg, rpg->trader->back, 200, 0));
    sfText_setPosition(rpg->trader->shop, set_pos_mid_txt(rpg,
    rpg->trader->shop, 202, 0));
    sfRenderWindow_drawRectangleShape(rpg->win->window, rpg->trader->back,
    NULL);
}

static void place_text_shop(rpg_t *rpg)
{
        sfRectangleShape_setPosition(rpg->tra_but[0]->rec,
        set_pos_mid_rec(rpg, rpg->tra_but[0]->rec, 352, -150));
        sfRectangleShape_setPosition(rpg->tra_but[1]->rec,
        set_pos_mid_rec(rpg, rpg->tra_but[1]->rec, 442, -150));
        sfRectangleShape_setPosition(rpg->tra_but[2]->rec,
        set_pos_mid_rec(rpg, rpg->tra_but[2]->rec, 532, -150));
        sfRectangleShape_setPosition(rpg->tra_but[0]->item,
        set_pos_mid_rec(rpg, rpg->tra_but[0]->item, 365, -150));
        sfRectangleShape_setPosition(rpg->tra_but[1]->item,
        set_pos_mid_rec(rpg, rpg->tra_but[1]->item, 455, -150));
        sfRectangleShape_setPosition(rpg->tra_but[2]->item,
        set_pos_mid_rec(rpg, rpg->tra_but[2]->item, 545, -150));
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawText(rpg->win->window, rpg->tra_but[i]->cost,
        NULL);
    for (int i = 0; i != 3; i++)
        sfRenderWindow_drawRectangleShape(rpg->win->window,
        rpg->tra_but[i]->item, NULL);
    sfText_setString(rpg->trader->coin,
    my_strcat("coin : ", my_itos(rpg->coin->coin)));
}

//draw trader button
void draw_trader_button(rpg_t *rpg)
{
    if (rpg->trader->open == 1) {
        place_text_shop(rpg);
        place_shop(rpg);
        sfRenderWindow_drawText(rpg->win->window, rpg->trader->shop, NULL);
        sfRenderWindow_drawText(rpg->win->window, rpg->trader->coin, NULL);
        for (int i = 0; i != 3; i++) {
            sfRenderWindow_drawText(rpg->win->window, rpg->tra_but[i]->cost,
            NULL);
            sfRenderWindow_drawText(rpg->win->window, rpg->tra_but[i]->buy,
            NULL);
            sfRenderWindow_drawRectangleShape(rpg->win->window,
            rpg->tra_but[i]->rec, NULL);
        }
        for (int i = 0; i != 3; i++)
            sfRenderWindow_drawRectangleShape(rpg->win->window,
            rpg->tra_but[i]->item, NULL);
        sfText_setString(rpg->trader->coin, my_strcat("coin : ",
        my_itos(rpg->coin->coin)));
        sfRenderWindow_drawText(rpg->win->window, rpg->trader->coin, NULL);
    }
}

static void anim_trader(rpg_t *rpg)
{
    sfTime time = sfClock_getElapsedTime(rpg->trader->cl);
    float second = sfTime_asSeconds(time);

    if (second > 0.5) {
        if (rpg->trader->rec.left < 166 / 2) {
            rpg->trader->rec.left += 166 / 2;
        } else {
            rpg->trader->rec.left = 0;
        }
        sfSprite_setTextureRect(rpg->trader->trader,
        rpg->trader->rec);
        sfClock_restart(rpg->trader->cl);
    }
}

//draw trader
void draw_trader(rpg_t *rpg)
{
    anim_trader(rpg);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->trader->trader, NULL);
    draw_trader_button(rpg);
}
