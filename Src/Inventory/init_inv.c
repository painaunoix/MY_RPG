/*
** EPITECH PROJECT, 2024
** init inv
** File description:
** file for init struct inventory
*/

#include "../../Include/my.h"

//init struct slot inv
void init_slot_inv(rpg_t *rpg)
{
    rpg->sl_inv = malloc(sizeof(slot_inv_t) * 15 + 8);
    for (int i = 0; i != 15; i++) {
        rpg->sl_inv[i] = malloc(sizeof(slot_inv_t));
        rpg->sl_inv[i]->disp = sfFalse;
        rpg->sl_inv[i]->slot = create_rectangle((sfVector2f) {67, 63},
        (sfVector2f) {100, 100});
        rpg->sl_inv[i]->sp = sfSprite_create();
        rpg->sl_inv[i + 1] = NULL;
        rpg->sl_inv[i]->tex_set = sfFalse;
        rpg->sl_inv[i]->name = NULL;
    }
}

//init strcut skills
void init_skills(rpg_t *rpg)
{
    rpg->skill = malloc(sizeof(skills_t));
    rpg->skill->tab_up = malloc(sizeof(sfRectangleShape **) * 6);
    for (int i = 0; i != 6; i++)
        rpg->skill->tab_up[i] = fill_tab_up(rpg->skill->tab_up[i]);
    rpg->skill->health = 0;
    rpg->skill->strenght = 0;
    rpg->skill->armor = 0;
    rpg->skill->speed = 0;
    rpg->skill->mana = 0;
    rpg->skill->luck = 0;
    rpg->skill->point = 0;
    rpg->skill->skill_txt = create_texte_esc((sfVector2f) {20, 30},
    (sfVector2f) {0, 0},
    sfColor_fromRGB(253, 212, 103), "Skills point left :");
    rpg->skill->nb_point = create_texte_esc((sfVector2f) {20, 30},
    (sfVector2f) {0, 0}, sfColor_fromRGB(253, 212, 103), " ");
    rpg->skill->xp = 0;
}

//init struct inv
void init_inv(rpg_t *rpg)
{
    rpg->inv = malloc(sizeof(inv_t));
    rpg->inv->open = 0;
    rpg->inv->bck = create_rectangle_shape((sfVector2f) {1100, 700},
    (sfVector2f) {10, 10}, INV);
    rpg->inv->title = create_texte_esc((sfVector2f) {30, 70}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "INVENTORY");
    rpg->inv->healt = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Health");
    rpg->inv->mana = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Mana");
    rpg->inv->armor = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Armor");
    rpg->inv->strenght = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Strenght");
    rpg->inv->luck = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Luck");
    rpg->inv->speed = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Speed");
    rpg->inv->move_sp = -1;
}

//create rectangle for struct skills
void init_button_upgrade(rpg_t *rpg)
{
    rpg->inv->skills = malloc(sizeof(sfRectangleShape *) * 6);
    for (int i = 0; i != 6; i++) {
        rpg->inv->skills[i] = create_rectangle_shape((sfVector2f) {50, 50},
        (sfVector2f) {0, 0}, UP);
    }
}

//init struct health
void init_health(rpg_t *rpg)
{
    rpg->health = malloc(sizeof(health_t));
    rpg->health->pv = 4;
    rpg->health->total_pv = 4;
    rpg->health->pv_empty = texture(PV_EMPTY);
    rpg->health->pv_fill = texture(PV);
    rpg->health->pv_tab = malloc(sizeof(sfRectangleShape *) * 10);
    rpg->health->pos = (sfVector2f) {3650, 9600};
    for (int i = 0; i != 10; i++) {
        rpg->health->pv_tab[i] = create_rectangle_shape((sfVector2f)
        {50, 50}, (sfVector2f) {0, 0}, PV_EMPTY);
    }
    rpg->health->heal_pot = sfClock_create();
}
