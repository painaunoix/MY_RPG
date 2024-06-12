/*
** EPITECH PROJECT, 2024
** init_quests.c
** File description:
** init_quests
*/

#include "../../Include/my.h"

void create_qts(rpg_t *rpg)
{
    rpg->qts->txSnake = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Kill Snake :");
    rpg->qts->txSlime = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Kill Slime :");
    rpg->qts->txGhost = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Kill Ghost :");
    rpg->qts->txDog = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Kill Dog :");
    rpg->qts->txGolem = create_texte_esc((sfVector2f) {30, 40}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "Kill Golem :");
}

//init struct quests
void init_qts(rpg_t *rpg)
{
    rpg->qts = malloc(sizeof(quests_t));
    rpg->qts->open = 0;
    rpg->qts->dog = 0;
    rpg->qts->slime = 0;
    rpg->qts->ghost = 0;
    rpg->qts->golem = 0;
    rpg->qts->snake = 0;
    rpg->qts->bck = create_rectangle_shape((sfVector2f) {1100, 700},
    (sfVector2f) {10, 10}, QTS);
    rpg->qts->title = create_texte_esc((sfVector2f) {30, 70}, (sfVector2f)
    {0, 0}, sfColor_fromRGB(253, 212, 103), "QUESTS");
    create_qts(rpg);
}
