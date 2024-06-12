/*
** EPITECH PROJECT, 2024
** attack_dog.c
** File description:
** attack_dog
*/

#include "../../../Include/my.h"

//knock dog when player hit it
void knock_dog(rpg_t *rpg, int i)
{
    rpg->dog[i]->life -= rpg->player->atk;
    if (rpg->dog[i]->life <= 0) {
        rpg->coin->coin += 2;
        rpg->skill->xp += rand() % 2 + rpg->skill->luck;
        if (rpg->qts->dog <= 4)
            rpg->qts->dog++;
        if (rpg->qts->dog == 5)
            rpg->coin->coin += 15;
    }
    while (rpg->skill->xp >= 10) {
        rpg->skill->xp -= 10;
        rpg->skill->point++;
    }
    if (rpg->player->player_axe == 2)
        sfSprite_move(rpg->dog[i]->dog, (sfVector2f) {20, 0});
    if (rpg->player->player_axe == 4)
        sfSprite_move(rpg->dog[i]->dog, (sfVector2f) {-20, 0});
}

//check if the dog is attack
void change_dog_texture(rpg_t *rpg, int i)
{
    if (sfSprite_getTexture(rpg->dog[i]->dog) ==
    rpg->dog[i]->dog_tx)
        sfSprite_setTexture(rpg->dog[i]->dog,
        rpg->dog[i]->dog_r_red, sfFalse);
    if (sfSprite_getTexture(rpg->dog[i]->dog) ==
    rpg->dog[i]->dog_right)
        sfSprite_setTexture(rpg->dog[i]->dog,
        rpg->dog[i]->dog_l_red, sfFalse);
}

void is_dog_atk(rpg_t *rpg)
{
    sfFloatRect atk = sfRectangleShape_getGlobalBounds(rpg->attack->att_zone);
    sfFloatRect dog;

    for (int i = 0; i <= 7; i++) {
        dog = sfSprite_getGlobalBounds(rpg->dog[i]->dog);
        if (sfFloatRect_intersects(&dog, &atk, NULL) &&
        rpg->dog[i]->life > 0) {
            change_dog_texture(rpg, i);
            knock_dog(rpg, i);
        }
    }
}
