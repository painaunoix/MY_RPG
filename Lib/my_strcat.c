/*
** EPITECH PROJECT, 2023
** my_strcat
** File description:
** my strcat
*/

#include "../Include/my.h"

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int x = 0;
    char *save = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);

    while (dest[i] != '\0') {
        save[i] = dest[i];
        i++;
    }
    while (src[x] != '\0') {
        save[i] = src[x];
        x++;
        i++;
    }
    save[i] = '\0';
    return (save);
}
