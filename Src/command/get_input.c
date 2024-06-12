/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get input make by the player
*/

#include "../../Include/my.h"

//init struct for command
void init_com(rpg_t *rpg)
{
    rpg->com = malloc(sizeof(com_t));
    rpg->com->input = malloc(1);
    rpg->com->input[0] = '\0';
    rpg->com->com = create_texte_esc((sfVector2f) {25, 25},
    (sfVector2f) {0, 0}, sfBlack, "");
    rpg->com->wait_in = sfFalse;
}

//manage str for delete part of str
static char *change_str(char *str, int c, rpg_t *rpg, int len)
{
    int i = 0;

    if (c == 8 && len == 0)
        return (my_strdup("\0"));
    if (c == 8)
        rpg->com->input[len - 1] = '\0';
    return (str);
}

//realloc sring by adding one place
char *realloc_string(char *str)
{
    char *str2;

    if (str[0] == '\0')
        return (my_strdup(" \0"));
    str2 = malloc(sizeof(char) * (my_strlen(str) + 1) + 1);
    for (int i = 0; str[i]; i++) {
        str2[i] = str[i];
        str2[i + 1] = '\0';
    }
    return (str2);
}

//set all varaible to stop input
void set_end_in(rpg_t *rpg)
{
    rpg->com->input = malloc(1);
    rpg->com->input[0] = '\0';
    rpg->com->wait_in = sfFalse;
}

//get charachter press by user
void get_input(rpg_t *rpg)
{
    int len = my_strlen(rpg->com->input);
    char c = rpg->win->event.text.unicode;

    if (rpg->win->event.type == sfEvtTextEntered && c != 27 &&
    rpg->com->wait_in) {
        if (c != 13) {
            rpg->com->input = realloc_string(rpg->com->input);
            rpg->com->input[len] = c;
            rpg->com->input[len + 1] = '\0';
        }
        rpg->com->input = change_str(rpg->com->input, c, rpg, len);
        sfText_setString(rpg->com->com, rpg->com->input);
    }
    if (c == 13) {
        is_com(rpg);
        set_end_in(rpg);
        rpg->player->player_can_move = sfTrue;
    }
}

//set on input when user press /
void is_slash_press(rpg_t *rpg)
{
    if (rpg->win->event.key.code == sfKeySlash &&
    rpg->win->event.type == sfEvtKeyReleased && rpg->com->wait_in == sfFalse
    && rpg->game_state == 1) {
        rpg->com->wait_in = sfTrue;
        rpg->player->player_can_move = sfFalse;
        sfText_setString(rpg->com->com, "");
    }
    if (rpg->com->wait_in == sfTrue) {
        get_input(rpg);
    }
}
