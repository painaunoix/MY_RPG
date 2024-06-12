/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** display msg
*/

#include "../../Include/my.h"

static int step1(rpg_t *rpg)
{
    char c = rpg->win->event.text.unicode;

    if (c == 'z' || c == 'q' || c == 's' || c == 'd')
        return (1);
    return (0);
}

static int step2(rpg_t *rpg)
{
    for (int i = 0; rpg->sl_inv[i]; i++) {
        if (my_strcmp(rpg->sl_inv[i]->name, ITM_AXE) == 0)
            return (1);
    }
    return (0);
}

static int step3(rpg_t *rpg)
{
    if (rpg->inv->open == 1)
        return (1);
    return (0);
}

static int step4(rpg_t *rpg)
{
    if (my_strcmp(ITM_AXE, rpg->cadre->itm1) == 0)
        return (1);
    if (my_strcmp(ITM_AXE, rpg->cadre->itm2) == 0)
        return (1);
    return (0);
}

static int step5(rpg_t *rpg)
{
    if (rpg->crab[0]->life < 5)
        return (1);
    return (0);
}

void task_complete(rpg_t *rpg)
{
    if (step1(rpg) == 1 && rpg->tuto->step == 1)
        rpg->tuto->step++;
    if (step2(rpg) == 1 && rpg->tuto->step == 2)
        rpg->tuto->step++;
    if (step3(rpg) == 1 && rpg->tuto->step == 3)
        rpg->tuto->step++;
    if (step4(rpg) == 1 && rpg->tuto->step == 4)
        rpg->tuto->step++;
    if (step5(rpg) == 1 && rpg->tuto->step == 5)
        rpg->tuto->step++;
}

void display_tuto_split(rpg_t *rpg)
{
    if (rpg->tuto->step == 1)
        sfRenderWindow_drawText(rpg->win->window, rpg->tuto->step1, NULL);
    if (rpg->tuto->step == 2)
        sfRenderWindow_drawText(rpg->win->window, rpg->tuto->step2, NULL);
    if (rpg->tuto->step == 3)
        sfRenderWindow_drawText(rpg->win->window, rpg->tuto->step3, NULL);
    if (rpg->tuto->step == 4)
        sfRenderWindow_drawText(rpg->win->window, rpg->tuto->step4, NULL);
    if (rpg->tuto->step == 5)
        sfRenderWindow_drawText(rpg->win->window, rpg->tuto->step5, NULL);
    task_complete(rpg);
}

void display_tuto(rpg_t *rpg)
{
    sfText_setPosition(rpg->tuto->step1, set_pos_mid_txt(rpg,
    rpg->tuto->step1, 800, 0));
    sfText_setPosition(rpg->tuto->step2, set_pos_mid_txt(rpg,
    rpg->tuto->step2, 900, 0));
    sfText_setPosition(rpg->tuto->step3, set_pos_mid_txt(rpg,
    rpg->tuto->step3, 900, 0));
    sfText_setPosition(rpg->tuto->step4, set_pos_mid_txt(rpg,
    rpg->tuto->step4, 900, 0));
    sfText_setPosition(rpg->tuto->step5, set_pos_mid_txt(rpg,
    rpg->tuto->step5, 900, 0));
    display_tuto_split(rpg);
}
