/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** save in file
*/

#include "../../Include/my.h"

void put_in_file(char *str, FILE *fptr)
{
    fwrite(str, my_strlen(str), 1, fptr);
    fwrite("\n", 1, 1, fptr);
}

void save_inv_split(rpg_t *rpg, FILE *fptr)
{
    put_in_file(my_itos(rpg->tuto->step), fptr);
    put_in_file(my_itos(rpg->qts->dog), fptr);
    put_in_file(my_itos(rpg->qts->ghost), fptr);
    put_in_file(my_itos(rpg->qts->golem), fptr);
    put_in_file(my_itos(rpg->qts->slime), fptr);
    put_in_file(my_itos(rpg->qts->snake), fptr);
}

void save_inv(rpg_t *rpg, FILE *fptr)
{
    put_in_file(my_itos(rpg->skill->point), fptr);
    for (int i = 0; rpg->sl_inv[i]; i++) {
        if (rpg->sl_inv[i]->name != NULL) {
            put_in_file(rpg->sl_inv[i]->name, fptr);
        } else
            put_in_file("NULL", fptr);
    }
    if (rpg->cadre->itm1 != NULL) {
        put_in_file(rpg->cadre->itm1, fptr);
    } else
        put_in_file("NULL", fptr);
    if (rpg->cadre->itm2 != NULL) {
        put_in_file(rpg->cadre->itm2, fptr);
    } else
        put_in_file("NULL", fptr);
    save_inv_split(rpg, fptr);
}

void save_pos(rpg_t *rpg, FILE *fptr)
{
    sfVector2f pos = sfSprite_getPosition(rpg->player->player);

    rpg->health->pos = pos;
    put_in_file(my_itos(pos.x), fptr);
    put_in_file(my_itos(pos.y), fptr);
    put_in_file(my_itos(rpg->health->pv), fptr);
    put_in_file(my_itos(rpg->health->total_pv), fptr);
    put_in_file(my_itos(rpg->coin->coin), fptr);
    put_in_file(my_itos(rpg->skill->health), fptr);
    put_in_file(my_itos(rpg->skill->speed), fptr);
    put_in_file(my_itos(rpg->player->player_speed), fptr);
    put_in_file(my_itos(rpg->skill->luck), fptr);
    put_in_file(my_itos(rpg->skill->strenght), fptr);
    put_in_file(my_itos(rpg->skill->mana), fptr);
    put_in_file(my_itos(rpg->skill->armor), fptr);
    put_in_file(my_itos(rpg->skill->xp), fptr);
    save_inv(rpg, fptr);
}

void save_game(rpg_t *rpg)
{
    FILE *fptr;

    fptr = fopen("Save/Save1", "wb+");
    save_pos(rpg, fptr);
    fclose(fptr);
}
