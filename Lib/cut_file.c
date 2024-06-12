/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** cut_file
*/

#include "../Include/my.h"

static int add_value(int *a, int *b)
{
    *a += 1;
    *b += 1;
    return (0);
}

static int skip(char *str, int i)
{
    while (str[i] == '\n'){
        i++;
    }
    return (i);
}

static int count_words(char *str)
{
    int words = 0;
    int i = 0;

    while (str[i] != '\0'){
        if (str[i] == '\n')
            i = skip(str, i);
        if (str[i] == '\0')
            break;
        while (str[i] != '\n' && str[i] != '\0')
            i++;
        words += 1;
    }
    return (words);
}

static int sizeof_word(char *str, int *c, int size)
{
    while (str[*c] != '\0'){
        if (str[*c] != '\n')
            break;
        *c += 1;
    }
    if (str[*c] != '\n' && str[*c] != '\0'){
        while (str[*c] != '\n' && str[*c] != '\0'){
            size++;
            *c += 1;
        }
        return (size);
    }
}

static char **fill_array(char **word_array, char *str)
{
    int cols = 0;
    int li = 0;
    int i = 0;

    i += skip(str, i);
    while (str[i] != '\0'){
        if (str[i] == '\0' || str[i] == '\n') {
            word_array[li][cols] = '\0';
            cols = 0;
            li++;
            i = skip(str, i);
        }
        if (str[i] == '\0')
            return (word_array);
        word_array[li][cols] = str[i];
        add_value(&cols, &i);
    }
    word_array[li][cols] = '\0';
    return (word_array);
}

char **cut_file(char *str)
{
    char **word_array;
    int words = count_words(str);
    int i = 0;
    int size = 0;
    int c = 0;

    if (words == 0)
        return (NULL);
    word_array = malloc(sizeof(char *) * words + (sizeof(NULL)));
    while (i != words){
        size = sizeof_word(str, &c, size);
        word_array[i] = malloc(sizeof(char) * size + 1);
        size = 0;
        i++;
    }
    word_array[words] = NULL;
    word_array = fill_array(word_array, str);
    return (word_array);
}
