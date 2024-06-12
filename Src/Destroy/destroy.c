/*
** EPITECH PROJECT, 2024
** destroy
** File description:
** destroy
*/

#include "../../Include/my.h"

//destroy rectangle
static void destroy_rect(rpg_t *rpg)
{
    sfRectangleShape_destroy(rpg->esc->set_r);
    sfRectangleShape_destroy(rpg->esc->cross_r);
    sfRectangleShape_destroy(rpg->esc->quit_r);
    sfRectangleShape_destroy(rpg->esc->inv_r);
    sfRectangleShape_destroy(rpg->grap->rope);
    sfRectangleShape_destroy(rpg->inv->bck);
    sfRectangleShape_destroy(rpg->player->hitbox);
}

//destroy text
static void destroy_text_2(rpg_t *rpg)
{
    sfText_destroy(rpg->set->setting);
    sfText_destroy(rpg->set->music);
    sfText_destroy(rpg->set->song);
}

//destroy text
void destroy_text(rpg_t *rpg)
{
    sfText_destroy(rpg->chest_opn->item_name);
    sfText_destroy(rpg->chest_opn->quit_text);
    sfText_destroy(rpg->esc->inv_txt);
    sfText_destroy(rpg->esc->opt_txt);
    sfText_destroy(rpg->esc->quit_txt);
    sfText_destroy(rpg->esc->set_txt);
    sfText_destroy(rpg->inv->armor);
    sfText_destroy(rpg->inv->healt);
    sfText_destroy(rpg->inv->luck);
    sfText_destroy(rpg->inv->mana);
    sfText_destroy(rpg->inv->speed);
    sfText_destroy(rpg->inv->strenght);
    sfText_destroy(rpg->inv->title);
    sfText_destroy(rpg->menu->Continue);
    sfText_destroy(rpg->menu->Play);
    sfText_destroy(rpg->menu->Quit);
    sfText_destroy(rpg->menu->Setting);
    sfText_destroy(rpg->menu->Title);
    sfText_destroy(rpg->set->full_scr);
    destroy_text_2(rpg);
}

//destroy sprite
void destroy_sprite(rpg_t *rpg)
{
    sfSprite_destroy(rpg->chest_opn->particle);
    sfSprite_destroy(rpg->esc->back);
    sfSprite_destroy(rpg->chest_opn->fond);
    sfSprite_destroy(rpg->chest_opn->item);
    sfSprite_destroy(rpg->menu->fond);
    sfSprite_destroy(rpg->player->player);
    sfSprite_destroy(rpg->w_map->map);
    sfSprite_destroy(rpg->w_map->m_top);
    sfSprite_destroy(rpg->set->back);
}

//destroy texture
void destroy_tex(rpg_t *rpg)
{
    sfTexture_destroy(rpg->player->player_left_idle);
    sfTexture_destroy(rpg->player->player_left_move);
    sfTexture_destroy(rpg->player->player_right_idle);
    sfTexture_destroy(rpg->player->player_right_move);
}

//destroy other
void destroy_mul(rpg_t *rpg)
{
    for (int i = 0; rpg->chest[i]; i++) {
        sfSprite_destroy(rpg->chest[i]->chest_close);
        sfSprite_destroy(rpg->chest[i]->chest_open);
    }
    for (int i = 0; rpg->grap_pillar[i]; i++)
        sfRectangleShape_destroy(rpg->grap_pillar[i]->pillar);
    for (int i = 0; rpg->inv->skills[i]; i++)
        sfRectangleShape_destroy(rpg->inv->skills[i]);
    for (int i = 0; rpg->inv->slots[i]; i++)
        sfRectangleShape_destroy(rpg->inv->slots[i]);
    sfClock_destroy(rpg->chest_opn->clock);
    sfClock_destroy(rpg->menu->clock);
    sfClock_destroy(rpg->player->clock);
    sfConvexShape_destroy(rpg->grap->dis_rope);
    sfMusic_destroy(rpg->menu->song);
    sfView_destroy(rpg->player->view);
    sfView_destroy(rpg->win->view);
    sfImage_destroy(rpg->w_map->red_m);
}

//free struct
static void free_stru(rpg_t *rpg)
{
    free(rpg->chest);
    free(rpg->chest_opn);
    free(rpg->esc);
    free(rpg->grap);
    free(rpg->grap_pillar);
    free(rpg->inv);
    free(rpg->menu);
    free(rpg->player);
    free(rpg->set);
    free(rpg->w_map);
    free(rpg->win);
    free(rpg);
}

//call all function for free all
void destroy(rpg_t *rpg)
{
    destroy_mul(rpg);
    destroy_rect(rpg);
    destroy_sprite(rpg);
    destroy_tex(rpg);
    destroy_text(rpg);
    free_stru(rpg);
}
