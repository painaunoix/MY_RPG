/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** put in file
*/

#include "../../Include/my.h"

int size_arr(char **arr)
{
    int i = 0;

    if (arr == NULL)
        return (0);
    for (i = 0; arr[i]; i++);
    return (i);
}

void put_inv_split(rpg_t *rpg, char **file)
{
    rpg->tuto->step = my_getnbr(file[30]);
    rpg->qts->dog = my_getnbr(file[31]);
    rpg->qts->ghost = my_getnbr(file[32]);
    rpg->qts->golem = my_getnbr(file[33]);
    rpg->qts->slime = my_getnbr(file[34]);
    rpg->qts->snake = my_getnbr(file[35]);
}

void put_inv(rpg_t *rpg, char **file)
{
    int idx = 14;

    for (int i = 0; idx != 28; i++) {
        set_tex_sl(rpg, file[idx]);
        if (my_strcmp("NULL", file[idx]) != 0)
            rpg->sl_inv[i]->disp = sfTrue;
        idx++;
    }
    if (my_strcmp("NULL", file[30])) {
        rpg->cadre->item2 = create_rectangle_shape((sfVector2f)
        {50, 50}, (sfVector2f) {0, 0}, file[30]);
        rpg->cadre->itm2 = my_strdup(file[30]);
    }
    if (my_strcmp("NULL", file[29])) {
        rpg->cadre->item = create_rectangle_shape((sfVector2f)
        {50, 50}, (sfVector2f) {0, 0}, file[29]);
        rpg->cadre->itm1 = my_strdup(file[29]);
    }
    put_inv_split(rpg, file);
}

void put_player(rpg_t *rpg, char **file)
{
    sfSprite_setPosition(rpg->player->player, (sfVector2f)
    {my_getnbr(file[0]), my_getnbr(file[1])});
    rpg->health->pv = my_getnbr(file[2]);
    rpg->health->total_pv = my_getnbr(file[3]);
    rpg->coin->coin = my_getnbr(file[4]);
    rpg->skill->health = my_getnbr(file[5]);
    rpg->skill->speed = my_getnbr(file[6]);
    rpg->player->player_speed = my_getnbr(file[7]);
    rpg->skill->luck = my_getnbr(file[8]);
    rpg->skill->strenght = my_getnbr(file[9]);
    rpg->player->atk = rpg->skill->strenght * 0.25 + 1;
    rpg->skill->mana = my_getnbr(file[10]);
    rpg->skill->armor = my_getnbr(file[11]);
    rpg->skill->xp = my_getnbr(file[12]);
    rpg->skill->point = my_getnbr(file[13]);
    put_inv(rpg, file);
}

void put_in_stru(rpg_t *rpg)
{
    struct stat s;
    int fd = open("Save/Save1", O_RDONLY);
    char *buffer;
    char **file;

    if (stat("Save/Save1", &s) == -1)
        return;
    buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size] = '\0';
    file = cut_file(buffer);
    if (size_arr(file) < 36)
        return;
    put_player(rpg, file);
}
