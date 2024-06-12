/*
** EPITECH PROJECT, 2023
** my_strdup
** File description:
** malloc and copy a string
*/

#include "../Include/my.h"

int my_strlen(char *str)
{
    int i = 0;

    if (str == NULL)
        return (1);
    for (; str[i]; i++);
    return (i);
}

char *my_strdup(char *str)
{
    char *stc = NULL;

    if (str == NULL)
        return (NULL);
    stc = malloc(sizeof(char) * my_strlen(str) + 1);
    my_strcpy(stc, str);
    return stc;
}
