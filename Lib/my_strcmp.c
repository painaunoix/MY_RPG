/*
** EPITECH PROJECT, 2023
** my_strcmp
** File description:
** comapre two strings
*/

#include "../Include/my.h"

int strlen_chaine(char const *nb1, char const *nb2)
{
    int a = 0;
    int b = 0;

    while (nb1[a] != '\0')
        a++;
    while (nb2[b] != '\0')
        b++;
    if (a < b) {
        return b;
    } else {
        return a;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;
    int result = 0;
    int size = 0;

    if (s1 == NULL || s2 == NULL)
        return (1);
    size = strlen_chaine(s1, s2);
    while (size != 0 && result == 0) {
        result = s1[i] - s2[i];
        size--;
        i++;
    }
    if (result == 0)
        return 0;
    return 1;
}
