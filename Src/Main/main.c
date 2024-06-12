/*
** EPITECH PROJECT, 2024
** main.c
** File description:
** main
*/

#include "../../Include/my.h"

//print help
static void helper_mess(void)
{
    printf("USAGE\n    ./my_rpg\nDESCRIPTION\n\n");
    printf("This is a game created by Epitech student in CSFML.\n");
    printf("This RPG follows the story of a Viking named Arnald on a");
    printf(" quest to achieve greatness.\n\nCredits: Aymeric BRETIN, ");
    printf("Lucas ANDRES, Enzo LORENZINY, Thomas FURSTENBERGER\n");
}

//check argv for -h --help
static int error_arg(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-h") == 0 ||
    ac == 2 && strcmp(av[1], "--help") == 0) {
        helper_mess();
        exit(0);
    }
    if (ac != 1)
        exit(84);
}

//event function
int event_function(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->win->window, &rpg->win->event)) {
        if (rpg->win->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg->win->window);
        }
        if (rpg->win->event.key.code == sfKeySpace &&
        rpg->win->event.type == sfEvtKeyPressed && rpg->attack->attack == 0
        && rpg->com->wait_in == sfFalse && is_in_frame(rpg, ITM_AXE) == 0) {
            rpg->attack->clock = sfClock_create();
            degat_to_monster(rpg);
        }
        if (rpg->set->open == 1 && rpg->game_state == 1)
            hover_full_set(rpg, sfWhite, rpg->set->boxt_r);
        event_key(rpg);
    }
}

//game loop call every function in loop
void game_loop(rpg_t *rpg)
{
    while (sfRenderWindow_isOpen(rpg->win->window)) {
        if (rpg->game_state == -1) {
            load_in(rpg);
            rpg->game_state = 0;
        } else {
            run_menu_clock(rpg);
            game(rpg);
            run_clock_all(rpg);
            draw_all(rpg);
            anim_all(rpg);
            sfRenderWindow_display(rpg->win->window);
            sfRenderWindow_clear(rpg->win->window,
            sfColor_fromRGB(65, 159, 204));
            event_function(rpg);
        }
    }
}

//main
int main(int ac, char **av)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    srand(time(NULL));
    rpg->game_state = -1;
    rpg->load = 0;
    error_arg(ac, av);
    init_loading(rpg);
}
