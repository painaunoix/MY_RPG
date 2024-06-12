/*
** EPITECH PROJECT, 2023
** str to word array
** File description:
** take a str and return word array
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../Include/my.h"

int lonmt(char const *str, int ind)
{
    int i = 0;

    while (str[ind] != '\0' && str[ind] != ' ') {
        ind++;
        i++;
    }
    return (i);
}

int place_word(char const *str, char **tab, int lettre, int tabpl)
{
    char *src = malloc(sizeof(char) * (lonmt(str, lettre)) + 1);
    int nbsrc = 0;
    int nb = 0;

    while (str[lettre] != ' ' && str[lettre] != '\0' && str[lettre] != '\t'
    && str[lettre] != ';') {
        src[nbsrc] = str[lettre];
        nbsrc++;
        lettre++;
        nb++;
    }
    tab[tabpl] = src;
    tab[tabpl][nb] = '\0';
}

int nb_mots(char const *str)
{
    int nb = 1;

    for (int i = 0; str[i]; i++)
        if (str[i] == ' ')
            nb++;
    return (nb);
}

char **my_str_to_word_array(char *str)
{
    char **tab = NULL;
    int i = 0;
    int tabpl = 0;

    tab = malloc(sizeof(char *) * (nb_mots(str)) + 8);
    while (i < my_strlen(str)) {
        if (i < my_strlen(str) && str[i] != ' ' && str[i] != '\t'
        && str[i] != ';') {
            place_word(str, tab, i, tabpl);
            i += lonmt(str, i) + 1;
            tabpl++;
        } else {
            i++;
        }
    }
    tab[tabpl] = NULL;
    return (tab);
}
