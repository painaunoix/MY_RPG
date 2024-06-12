/*
** EPITECH PROJECT, 2024
** paint
** File description:
** convert int to string
*/

#include "../Include/my.h"

int len_nb(int nb)
{
    int cont = 0;

    while (nb != 0) {
        nb /= 10;
        cont++;
    }
    return (cont);
}

char *my_itos(int nb)
{
    int len = len_nb(nb);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 0;
    int save = 0;

    if (nb == 0)
        return "0\0";
    if (nb == -1)
        return "-1\0";
    while (nb != 0) {
        save = nb % 10;
        nb /= 10;
        str[len - 1] = save + 48;
        len--;
        i++;
    }
    str[i] = '\0';
    return (str);
}
