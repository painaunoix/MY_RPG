/*
** EPITECH PROJECT, 2023
** my
** File description:
** h
*/

#ifndef MY_H_
    #define MY_H_

    #include "item.h"
    #include "menu.h"
    #include "map.h"
    #include "hud.h"
    #include "player.h"
    #include "donjon.h"
    #include "monster.h"

    #include <stdarg.h>
    #include <time.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <stddef.h>
    #include <string.h>
    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/PrimitiveType.h>
    #include <SFML/Graphics/RenderStates.h>
    #include <SFML/Graphics/Vertex.h>
    #include <SFML/Window/Event.h>
    #include <SFML/Window/VideoMode.h>
    #include <SFML/Window/WindowHandle.h>
    #include <SFML/Window/Window.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <unistd.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <SFML/Window/Mouse.h>
    #include <SFML/System/Export.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <fcntl.h>
    #include <SFML/Graphics/Transform.h>

typedef struct win_s {
    sfRenderWindow *window;
    sfView *view;
    sfVector2f center;
    sfEvent event;
    sfVector2f mouse;
} win_t;

typedef struct tuto_item_s {
    sfSprite *tuto_item_sprite;
    sfTexture *tuto_dock;
    sfTexture *tuto_bomb;
    sfTexture *tuto_hook;
    sfTexture *tuto_torch;
    int tuto_open;
} tuto_item_t;

typedef struct com_s {
    char *input;
    sfText *com;
    sfBool wait_in;
} com_t;

typedef struct debug_s {
    sfSprite *red;
    sfTexture *redt;
    sfBool disp;
    sfBool coli;
    sfBool die;
} debug_t;

typedef struct sound_s {
    sfRectangleShape *rec;
    sfMusic *sound;
} sound_t;

typedef struct rpg_s {
    int game_state;
    int set_open;
    int load;
    dock_t **dock;
    debug_t *debug;
    stone_t **stone;
    gem_t *gem;
    com_t *com;
    door_t **door;
    trader_but_t **tra_but;
    trader_t *trader;
    coin_t *coin;
    slot_inv_t **sl_inv;
    w_map_t *w_map;
    grap_pillar_t **grap_pillar;
    grap_t *grap;
    player_t *player;
    win_t *win;
    menu_t *menu;
    chest_t **chest;
    chest_opn_t *chest_opn;
    escape_t *esc;
    inv_t *inv;
    set_t *set;
    skills_t *skill;
    health_t *health;
    mana_t *mana;
    cadre_t *cadre;
    slime_t **slime;
    anim_monst_t *anim_monst;
    attack_t *attack;
    cursor_t *cursor;
    map_t *map;
    boat_t *boat;
    dg_t *dg;
    ghost_t **ghost;
    crab_t **crab;
    sound_t **sound;
    snake_t **snake;
    golem_t **golem;
    dog_t **dog;
    loading_t *loading;
    quests_t *qts;
    hit_t *hit;
    die_t *die;
    tuto_t *tuto;
    tuto_item_t *tuto_item;
    walk_t *walk_sound;
    door_cave_t **cave;
    big_torch_t *b_torch;
    boss_t *boss;
    hiden_t *hiden;
    sfSprite *hell_door;
    bomb_t **bomb;
} rpg_t;

typedef struct functioninfo_s {
    void (*func)(rpg_t *rpg);
    char *text;
} functioninfo_t;

// LIB
char *my_itos(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char *str);
char **my_str_to_word_array(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strlen(char *str);
int my_getnbr(char *str);
void event_key(rpg_t *rpg);
void check_map(rpg_t *rpg);
void check_inv(rpg_t *rpg);
void check_esc(rpg_t *rpg);
char **cut_file(char *str);
char *my_strcat(char *dest, char *src);

// INIT
void init_window(rpg_t *rpg);
void init_com(rpg_t *rpg);
void init_debug(rpg_t *rpg);
void init_gem(rpg_t *rpg);
void init_save_tone(rpg_t *rpg);
void init_dock(rpg_t *rpg);
void init_hit(rpg_t *rpg);
void init_die(rpg_t *rpg);
void init_bomb(rpg_t *rpg);

// DEBUG
void display_red(rpg_t *rpg);
void is_slash_press(rpg_t *rpg);
void move_sp(sfSprite *rect, rpg_t *rpg);
void change_speed(rpg_t *rpg);
void move_rect(sfRectangleShape *rect, rpg_t *rpg);
void get_itm(rpg_t *rpg, char **arr);
void set_var(rpg_t *rpg, char **arr);
void change_coli(rpg_t *rpg);
void goto_com(rpg_t *rpg, char **arr);
void pos_player(rpg_t *rpg);
void is_com(rpg_t *rpg);
void set_end_in(rpg_t *rpg);

//BASIC FUNCTION
sfSprite *create_sprite_rect(sfVector2f scale, sfVector2f pos,
    char *file, sfIntRect rect);
sfSprite *create_sprite(sfVector2f scale, sfVector2f pos, char *file);
sfText *create_texte(int size, sfVector2f position, sfColor color, char *str);
sfIntRect make_rect(int height, int widht);
sfTexture *texture(char *file);
sfRectangleShape *create_rectangle(sfVector2f scale, sfVector2f pos);
sfRectangleShape *create_rectangle_shape(sfVector2f scale,
    sfVector2f pos, char *file);
sfVector2f set_pos_mid_rec(rpg_t *rpg, sfRectangleShape *rec, int y, int x);
sfVector2f set_pos_mid_txt(rpg_t *rpg, sfText *text, int y, int x);
sfVector2f set_pos_mid_sprite(rpg_t *rpg, sfSprite *sprite, int y);
sfVector2f set_pos_mid_sprite_off(rpg_t *rpg, sfSprite *sprite, int y, int x);
sfVector2f set_pos_mid_rectan(rpg_t *rpg, sfRectangleShape *rec, int y, int x);
void set_tab_rec_mid(sfRectangleShape **tab, sfVector2f pos);
void set_tex_sl(rpg_t *rpg, char *file);
void run_clock_all(rpg_t *rpg);
void setup_clock(rpg_t *rpg);
void slime_hit(rpg_t *rpg);

//OTHER
void hover_text(rpg_t *rpg, sfColor base, sfColor hover, sfText *text);
void destroy(rpg_t *rpg);
void draw_all(rpg_t *rpg);
void anim_all(rpg_t *rpg);
void game_loop(rpg_t *rpg);
void game(rpg_t *rpg);
void save_game(rpg_t *rpg);
void put_in_stru(rpg_t *rpg);
int hit_hiden(rpg_t *rpg, char *str, int i);

//ITEM
void pillard(rpg_t *rpg, int x, int y, int i);
void init_grap(rpg_t *rpg);
void grap_pillard(rpg_t *rpg);
void start_chest(rpg_t *rpg, int x, int y, int i);
void draw_chest(rpg_t *rpg);
void interact_chest(rpg_t *rpg);
void draw_particle(rpg_t *rpg);
void animation_open(rpg_t *rpg);
void is_chest_open(rpg_t *rpg);
void init_chest_opn(rpg_t *rpg);
void init_chest(rpg_t *rpg);
void change_boat(rpg_t *rpg);
void is_speed_gem_use(rpg_t *rpg);
void change_to_boat(rpg_t *rpg);
void adapt_rope(rpg_t *rpg);
void draw_grap(rpg_t *rpg);
void display_rope(rpg_t *rpg);
void grap_move(rpg_t *rpg, int i);
void init_boat(rpg_t *rpg);
void start_chest(rpg_t *rpg, int x, int y, int i);
void draw_chest(rpg_t *rpg);
void interact_chest(rpg_t *rpg);
void adapt_rope(rpg_t *rpg);
void draw_grap(rpg_t *rpg);
void display_rope(rpg_t *rpg);
void grap_move(rpg_t *rpg, int i);
void draw_particle(rpg_t *rpg);
void animation_open(rpg_t *rpg);
void is_chest_open(rpg_t *rpg);
void change_boat(rpg_t *rpg);
void change_to_boat(rpg_t *rpg);
int is_time_stg(rpg_t *rpg);
void is_stg_gem_use(rpg_t *rpg);
void is_pot_use(rpg_t *rpg);
void is_arm_gem_use(rpg_t *rpg);
void draw_buff(rpg_t *rpg);
void display_bomb(rpg_t *rpg);

//MENU
void hover_set_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void hover_inv_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void hover_quit_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void init_inv(rpg_t *rpg);
void draw_inventory(rpg_t *rpg);
void set_middle_inv(rpg_t *rpg);
void init_settings(rpg_t *rpg);
void draw_setting(rpg_t *rpg);
void set_pos_set(rpg_t *rpg);
void hover_full_set(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void init_volume_set(rpg_t *rpg);
void draw_volume(rpg_t *rpg);
void vol_handling(rpg_t *rpg);
void draw_esacpe(rpg_t *rpg);
void set_pos_esc(rpg_t *rpg);
void init_escap(rpg_t *rpg);
void init_slot_inv(rpg_t *rpg);
void init_skills(rpg_t *rpg);
void init_button_upgrade(rpg_t *rpg);
void init_health(rpg_t *rpg);
void set_middle_tab(rpg_t *rpg);
void draw_skill_up(rpg_t *rpg);
void init_health(rpg_t *rpg);
void set_health(rpg_t *rpg);
void set_mana(rpg_t *rpg);
void init_mana(rpg_t *rpg);
void init_cadre(rpg_t *rpg);
void set_cadre(rpg_t *rpg);
void draw_slot(rpg_t *rpg);
void set_pos_inv_slot(rpg_t *rpg);
void is_mouse_on_slot(rpg_t *rpg);
void hover_play(rpg_t *rpg, sfColor base, sfColor hover, sfText *text);
void hover_continue(rpg_t *rpg, sfColor base, sfColor hover, sfText *text);
void hover_setting(rpg_t *rpg, sfColor base, sfColor hover, sfText *text);
void hover_quit(rpg_t *rpg, sfColor base, sfColor hover, sfText *text);
void hover_cross(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void hover_set_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void hover_inv_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void hover_quit_esc(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void draw_inventory(rpg_t *rpg);
void set_middle_inv(rpg_t *rpg);
void init_button_upgrade(rpg_t *rpg);
void hover_all_skills(rpg_t *rpg);
void init_settings(rpg_t *rpg);
void draw_setting(rpg_t *rpg);
void set_pos_set(rpg_t *rpg);
void init_volume_set(rpg_t *rpg);
void draw_volume(rpg_t *rpg);
void vol_handling(rpg_t *rpg);
void change_sound(rpg_t *rpg, sfMusic *old, sfMusic *new);
void swap_zone(rpg_t *rpg);
void draw_menu(rpg_t *rpg);
int animation_menu(rpg_t *rpg);
void draw_esacpe(rpg_t *rpg);
void set_pos_esc(rpg_t *rpg);
sfText *create_texte_esc(sfVector2f size, sfVector2f position, sfColor color,
    char *str);
sfRectangleShape **fill_tab_up(sfRectangleShape **tab);
void draw_sp_slot(rpg_t *rpg);
void set_itm_in_mid(rpg_t *rpg);
void is_frame_click(rpg_t *rpg);
void move_inventory(rpg_t *rpg);
void init_menu(rpg_t *rpg);
void init_load(rpg_t *rpg);
void init_loading(rpg_t *rpg);
void run_menu_clock(rpg_t *rpg);
void run_menu_load(rpg_t *rpg);
void load_in(rpg_t *rpg);
void init_sound(rpg_t *rpg);
void init_trader(rpg_t *rpg);
void init_trader_but(rpg_t *rpg);
void init_qts(rpg_t *rpg);
void draw_quests(rpg_t *rpg);
void set_middle_qts(rpg_t *rpg);
void check_quests(rpg_t *rpg);
void pos_set_main(rpg_t *rpg);
void draw_setting_main(rpg_t *rpg);
void change_texture(rpg_t *rpg);
void screen_handling(rpg_t *rpg, sfUint32 style);
void check_full_scr(rpg_t *rpg, sfColor hover, sfRectangleShape *rec);
void not_dsiplay_cursor_menu(rpg_t *rpg);
void vol_handling_main(rpg_t *rpg);
void vol_music_menu(rpg_t *rpg);
void vol_song_menu(rpg_t *rpg);

//MAP
void init_map(rpg_t *rpg);
void init_mini_map(rpg_t *rpg);
void set_middle_map(rpg_t *rpg);
void draw_map_cadre(rpg_t *rpg);
void draw_minimap(rpg_t *rpg);
void draw_map(rpg_t *rpg);
void draw_trader(rpg_t *rpg);
void talk_trader(rpg_t *rpg);
void draw_trader_button(rpg_t *rpg);
int iscollision(rpg_t *rpg, sfImage *image);
void draw_save_stone(rpg_t *rpg);
void player_save(rpg_t *rpg);
void draw_top_map(rpg_t *rpg);
void is_dock_use(rpg_t *rpg);

//HUD
void init_cadre(rpg_t *rpg);
void init_cursor(rpg_t *rpg);
void not_dsiplay_cursor(rpg_t *rpg);
int is_in_frame(rpg_t *rpg, char *str);

//PLAYER
void init_player(rpg_t *rpg);
void init_mana(rpg_t *rpg);
void init_att_zone(rpg_t *rpg);
void init_coin(rpg_t *rpg);
void att_zone_link(rpg_t *rpg);
void init_att_zone(rpg_t *rpg);
void degat_to_monster(rpg_t *rpg);
void attack_animation(rpg_t *rpg);
void move_view(rpg_t *rpg);
void player(rpg_t *rpg);
void draw_player(rpg_t *rpg);
void link_hitbox(rpg_t *rpg);
void run_animation(rpg_t *rpg);
void all_colli(rpg_t *rpg);
void adapte_mana(rpg_t *rpg);
void check_attack(rpg_t *rpg);
int screen_die(rpg_t *rpg);
void init_tuto(rpg_t *rpg);
void display_tuto(rpg_t *rpg);
void check_walk(rpg_t *rpg);
void sound_walk(rpg_t *rpg);

//DONJON
void init_dungeon(rpg_t *rpg);
void init_door(rpg_t *rpg);
void draw_dg_forest(rpg_t *rpg);
void init_dg_forest(rpg_t *rpg);
void dg_loop(rpg_t *rpg);
void is_door_taken(rpg_t *rpg);
void animation_key(rpg_t *rpg);
void set_pos_hud_dg(rpg_t *rpg);
void init_dg_hud(rpg_t *rpg);
void draw_dg_hud(rpg_t *rpg);
void draw_dungeon(rpg_t *rpg);
void draw_dungeon_hud(rpg_t *rpg);
void draw_ghost_dg(rpg_t *rpg);
void draw_ghost_dg(rpg_t *rpg);
void interact_with_silver_door(rpg_t *rpg, dg_door_for_t *door);
void interact_with_gold_door(rpg_t *rpg, dg_door_for_t *door);
void interact_with_silver_key(rpg_t *rpg, sfSprite *silver_key);
void interact_with_gold_key(rpg_t *rpg, sfSprite *gold_key);
void dg_loop_water(rpg_t *rpg);
void init_dg_water(rpg_t *rpg);
void draw_dg_water(rpg_t *rpg);
void draw_dg_sand(rpg_t *rpg);
void init_dg_sand(rpg_t *rpg);
void dg_loop_snake(rpg_t *rpg);
void draw_slime_dg(rpg_t *rpg);
void draw_snake_dg(rpg_t *rpg);
void init_dg_mountain(rpg_t *rpg);
void draw_dg_mountain(rpg_t *rpg);
void dg_loop_mountain(rpg_t *rpg);
void draw_dog_dg(rpg_t *rpg);
void init_dg_lava(rpg_t *rpg);
void draw_dg_lava(rpg_t *rpg);
void dg_loop_lava(rpg_t *rpg);
void draw_snake_wave(rpg_t *rpg);
void draw_slime_wave(rpg_t *rpg);
void draw_dog_wave(rpg_t *rpg);
void draw_ghost_wave(rpg_t *rpg);
void draw_golem_dg(rpg_t *rpg);

//ARENA
void trigger_arena(sfRectangleShape *rect, int *start, rpg_t *rpg);

void create_arena_forest(rpg_t *rpg);
void draw_hud_arena_forest(rpg_t *rpg, int start, int end);

void create_arena_water(rpg_t *rpg);
void draw_hud_arena_water(rpg_t *rpg, int start, int end);

void create_arena_sand(rpg_t *rpg);
void draw_hud_arena_sand(rpg_t *rpg, int start, int end);

void create_arena_mountain(rpg_t *rpg);
void draw_hud_arena_mountain(rpg_t *rpg, int start, int end);

//MONSTER
void init_anim_monster(rpg_t *rpg);
void draw_slime(rpg_t *rpg);
void setup_slime(rpg_t *rpg);
void anim_slime(rpg_t *rpg);
void setup_ghost(rpg_t *rpg);
void draw_ghost(rpg_t *rpg);
void anim_ghost(rpg_t *rpg);
void is_ghost_atk(rpg_t *rpg);
void move_crab(rpg_t *rpg);
void draw_crab(rpg_t *rpg);
void setup_crab(rpg_t *rpg);
void anim_crab(rpg_t *rpg);
void is_crab_atk(rpg_t *rpg);
void moving_crab_all(rpg_t *rpg);
void setup_snake(rpg_t *rpg);
void draw_snake(rpg_t *rpg);
void anim_snake(rpg_t *rpg);
void is_snake_atk(rpg_t *rpg);
void setup_golem(rpg_t *rpg);
void draw_golem(rpg_t *rpg);
void anim_golem(rpg_t *rpg);
void is_golem_atk(rpg_t *rpg);
void setup_dog(rpg_t *rpg);
void draw_dog(rpg_t *rpg);
void anim_dog(rpg_t *rpg);
void is_dog_atk(rpg_t *rpg);
void init_load(rpg_t *rpg);
void game_loop(rpg_t *rpg);
void init_loading(rpg_t *rpg);
void run_menu_clock(rpg_t *rpg);
void load_in(rpg_t *rpg);
void draw_monster(rpg_t *rpg);
sfSprite *create_ghost(rpg_t *rpg, int x, int y, int i);
void init_door_cave(rpg_t *rpg);
void is_cave_taken(rpg_t *rpg);
void init_big_torch(rpg_t *rpg);
void draw_big_torch(rpg_t *rpg);
void interact_big_torch(rpg_t *rpg);
void anim_b_torch(rpg_t *rpg);
void create_arena(rpg_t *rpg);
void draw_hud_arena_forest(rpg_t *rpg, int start, int end);
void trigger_arena(sfRectangleShape *rect, int *start, rpg_t *rpg);
void move_to_player_dog(rpg_t *rpg);
void move_to_player_dog_dg(rpg_t *rpg);
void move_to_player_ghost(rpg_t *rpg);
void move_to_player_ghost_dg(rpg_t *rpg);
void move_to_player_golem(rpg_t *rpg);
void move_to_player_golem_dg(rpg_t *rpg);
void move_to_player_slime(rpg_t *rpg);
void move_to_player_slime_dg(rpg_t *rpg);
void move_to_player_snake(rpg_t *rpg);
void move_to_player_snake_dg(rpg_t *rpg);
void is_slime_atk_dg(rpg_t *rpg);
void is_ghost_atk_dg(rpg_t *rpg);
void is_snake_atk_dg(rpg_t *rpg);
void is_dog_atk_dg(rpg_t *rpg);
void is_golem_atk_dg(rpg_t *rpg);
void knock_monster(rpg_t *rpg, int i);
void knock_snake(rpg_t *rpg, int i);
void knock_ghost(rpg_t *rpg, int i);
void knock_golem(rpg_t *rpg, int i);
void knock_dog(rpg_t *rpg, int i);
void change_snake_texture(rpg_t *rpg, int i);
void change_ghost_texture(rpg_t *rpg, int i);
void change_dog_texture(rpg_t *rpg, int i);
void change_golem_texture(rpg_t *rpg, int i);
void init_tuto_item(rpg_t *rpg);
void show_tuto_item(rpg_t *rpg);
void close_chest(rpg_t *rpg, int i);
void init_boss(rpg_t *rpg);
int anim_boss(rpg_t *rpg);
int boss_attack(rpg_t *rpg);
void move_to_player_boss(rpg_t *rpg, sfVector2f player_pos);
int is_second(sfClock *clock, float nb);
int anim_flame(rpg_t *rpg);
void move_to_player_proj(rpg_t *rpg, sfVector2f player_pos);
void is_boss_atk(rpg_t *rpg);
void trigger_start_boss(rpg_t *rpg);
int anim_atk(rpg_t *rpg);
void is_prok_atk(rpg_t *rpg);
void boss_hit(rpg_t *rpg);
void make_armor(rpg_t *rpg, int atk, char *str, int i);
void proj_hit(rpg_t *rpg);
void link_hitbox_boss(rpg_t *rpg);
void remake_heal_bar(rpg_t *rpg);
int anim_trigger(rpg_t *rpg);
void trigger_end_game(rpg_t *rpg);
void draw_end(rpg_t *rpg);
void init_end(rpg_t *rpg);

#endif /* MY_H_ */
