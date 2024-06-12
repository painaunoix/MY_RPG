/*
** EPITECH PROJECT, 2024
** init window
** File description:
** file for init struct window
*/

#include "../../Include/my.h"

const functioninfo_t load_info[] = {
    {init_player, "Init Player"},
    {init_map, "Init Map"},
    {init_menu, "Init Menu"},
    {init_chest, "Init Chest"},
    {init_grap, "Init Grapling"},
    {grap_pillard, "Init Grap Pillard"},
    {init_chest_opn, "Init Chest Open"},
    {init_escap, "Init Escape"},
    {init_settings, "Init Setting"},
    {setup_slime, "Init Slime"},
    {setup_ghost, "Init Ghost"},
    {setup_snake, "Init Snake"},
    {init_health, "Init Health"},
    {init_inv, "Init Inventory"},
    {init_qts, "Init Quests"},
    {init_button_upgrade, "Init Upgrade"},
    {init_skills, "Init Skills"},
    {init_slot_inv, "Init Slot Inventory"},
    {init_anim_monster, "Init Monster Anim"},
    {init_volume_set, "Init Volume"},
    {init_sound, "Init Sound"},
    {init_mana, "Init Mana"},
    {init_cadre, "Init Item"},
    {init_cursor, "Init Cursor"},
    {init_att_zone, "Init Player Attack"},
    {init_coin, "Init Coin"},
    {init_boat, "Init Boat"},
    {init_mini_map, "Init Minimap"},
    {init_cursor, "Init Cursor"},
    {init_trader, "Init Trader"},
    {init_trader_but, "Init Trader Item"},
    {init_dungeon, "Init Dungeon"},
    {init_door, "Init Door"},
    {init_com, "Init Terminal"},
    {setup_crab, "Init Crab"},
    {init_debug, "Init Debug"},
    {setup_golem, "Init Golem"},
    {setup_dog, "Init Dog"},
    {init_gem, "Init Gem"},
    {init_save_tone, "Init Gem"},
    {init_dg_hud, "Init Dungeon Hud"},
    {init_dock, "Init Dock"},
    {init_hit, "Init Hit"},
    {init_dg_water, "Init Water Dungeon"},
    {init_die, "Init Die"},
    {init_dg_sand, "Init Sand Dungeon"},
    {init_tuto, "Init Tutorial"},
    {init_dg_mountain, "Init Mountain Dungeon"},
    {sound_walk, "Init sound_walk"},
    {init_dg_lava, "Init Lava Dungeon"},
    {init_door_cave, "Init Cave"},
    {init_big_torch, "Init Big Torch"},
    {init_bomb, "Init Bomb"},
    {init_tuto_item, "Init Tutorial Item"},
    {init_boss, "Init Boss"},
    {setup_clock, "Init Clock"}
};

static void event_function_loading(rpg_t *rpg)
{
    while (sfRenderWindow_pollEvent(rpg->win->window, &rpg->win->event)) {
        if (rpg->win->event.type == sfEvtClosed) {
            sfRenderWindow_close(rpg->win->window);
        }
    }
}

static void anim_menu(rpg_t *rpg)
{
    if (rpg->menu->seconds > 0.125) {
        animation_menu(rpg);
        sfClock_restart(rpg->menu->clock);
    }
}

void run_menu_clock(rpg_t *rpg)
{
    rpg->menu->time = sfClock_getElapsedTime(rpg->menu->clock);
    rpg->menu->seconds = sfTime_asSeconds(rpg->menu->time);
    anim_menu(rpg);
}

void init_load(rpg_t *rpg)
{
    rpg->menu = malloc(sizeof(menu_t));
    rpg->loading = malloc(sizeof(loading_t));
    rpg->menu->fond_rect = make_rect(332, 576);
    rpg->menu->fond = create_sprite_rect((sfVector2f) {3.5, 3.5},
        (sfVector2f) {-30, -30}, MENU, rpg->menu->fond_rect);
    rpg->menu->clock = sfClock_create();
    rpg->loading->in = 0;
    rpg->loading->load_border = create_sprite((sfVector2f) {1, 1},
    (sfVector2f) {0, 0}, LOAD_BORDER);
    rpg->loading->loading_bar = sfRectangleShape_create();
    sfRectangleShape_setPosition(rpg->loading->loading_bar,
    (sfVector2f) {360, 830});
    sfRectangleShape_setFillColor(rpg->loading->loading_bar, sfYellow);
    sfRectangleShape_setSize(rpg->loading->loading_bar, (sfVector2f) {20, 60});
    rpg->loading->info = create_texte_esc((sfVector2f) {70, 70},
    (sfVector2f) {0, 0}, sfBlack, "start");
}

static void set_loading_text_mid(rpg_t *rpg)
{
    sfVector2u pos = sfRenderWindow_getSize(rpg->win->window);
    int center = pos.x / 2;
    sfFloatRect rect = sfText_getGlobalBounds(rpg->loading->info);
    int x = center - (rect.width / 2);

    sfText_setPosition(rpg->loading->info, (sfVector2f) {x, 817});
}

//draw all for loading screen
static void draw_loading(rpg_t *rpg, int increment)
{
    sfRenderWindow_drawSprite(rpg->win->window, rpg->menu->fond, NULL);
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->loading->loading_bar, NULL);
    run_menu_clock(rpg);
    sfRectangleShape_setSize(rpg->loading->loading_bar,
    (sfVector2f) {increment, 70});
    sfRenderWindow_drawRectangleShape(rpg->win->window,
    rpg->loading->loading_bar, NULL);
    sfRenderWindow_drawSprite(rpg->win->window,
    rpg->loading->load_border, NULL);
}

void load_in(rpg_t *rpg)
{
    int increment = 20;
    int nb = 56;

    for (int i = 0; i < nb; i++) {
        load_info[i].func(rpg);
        event_function_loading(rpg);
        draw_loading(rpg, increment);
        sfText_setString(rpg->loading->info, load_info[i].text);
        set_loading_text_mid(rpg);
        sfRenderWindow_drawText(rpg->win->window, rpg->loading->info, NULL);
        sfRenderWindow_display(rpg->win->window);
        increment += 1215 / nb;
        sleep(0.7);
    }
}
