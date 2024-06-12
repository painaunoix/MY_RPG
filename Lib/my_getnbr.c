/*
** EPITECH PROJECT, 2023
** my_getnbr
** File description:
** convert string to int
*/

#include "../Include/my.h"

int make_pow(int i)
{
    int nb = 1;

    for (; i != 0; i--) {
        nb *= 10;
    }
    return (nb);
}

int my_getnbr(char *str)
{
    int nb = 0;

    for (int i = 0; i != my_strlen(str); i++) {
        nb += (str[i] - 48) * make_pow(my_strlen(str) - i);
    }
    return (nb / 10);
}
