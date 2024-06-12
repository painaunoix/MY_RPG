##
## EPITECH PROJECT, 2023
## makefile
## File description:
## compile files
##

SRC =	Src/InitStruct/init_struct.c 					\
		Src/Main/main.c 								\
		Src/Main/init_win.c								\
		Src/RemakeCsfml/remake_csfml.c 					\
		Src/RemakeCsfml/remake_csfml_sprite.c 			\
		Src/Draw/draw_all.c 							\
		Src/Draw/draw_dungeon.c 						\
		Src/Menu/menu.c 								\
		Src/Menu/settings_main.c						\
		Src/Menu/volume_handling_main.c 				\
		Src/Clock/setup_clock.c 						\
		Src/Gameloop/main_loop.c 						\
		Src/Player/player.c 							\
		Src/Player/init_player.c						\
		Src/Player/player_hit_dg.c						\
		Src/Player/player_hit.c							\
		Src/Player/sound_walk.c							\
		Src/WorldMap/world_map.c 						\
		Src/Chest/chest.c 								\
		Src/Chest/chest_init.c							\
		Src/Grappling\ hook/adapt_rope.c 				\
		Src/Grappling\ hook/display_target.c 			\
		Src/Grappling\ hook/move_grap.c 				\
		Src/Grappling\ hook/init_grap.c					\
		Src/Debug/move_sp.c 							\
		Src/Debug/change_speed.c						\
		Src/Debug/move_rect.c 							\
		Src/Debug/debug_red_coli.c 						\
		Src/Escape/escape.c 							\
		Src/RemakeCsfml/csfml_set_middle.c				\
		Src/Menu/menu_interact.c						\
		Src/Menu/init_menu.c							\
		Src/Escape/escape_hove.c						\
		Src/Escape/init_escape.c						\
		Src/Inventory/inventory.c						\
		Src/Inventory/button_upgrade.c					\
		Src/Inventory/set_slot_inv.c					\
		Src/Inventory/init_inv.c						\
		Src/Settings/settings.c 						\
		Src/Destroy/destroy.c							\
		Src/Inventory/create_tab_up.c					\
		Src/Inventory/set_itm_to_slot.c					\
		Lib/my_strcpy.c									\
		Lib/my_strcmp.c									\
		Lib/my_strdup.c									\
		Lib/int_to_str.c								\
		Src/Health/health.c								\
		Src/Monster/Slime/slime.c 						\
		Src/Monster/Slime/slime_move.c 					\
		Src/Monster/init_monster.c						\
		Src/Mana/mana.c									\
		Src/Mana/init_mana.c							\
		Src/Cadre/is_item_in_frame.c					\
		Src/Cadre/cadre.c								\
		Src/Cadre/init_cadre.c							\
		Src/Cadre/is_frame_click.c						\
		Src/Player/player_attack.c 						\
		Src/Cursor/cursor.c 							\
		Src/Cursor/init_cursor.c						\
		Src/Map/map.c									\
		Src/Map/init_map.c								\
		Src/Map/init_sound.c							\
		Src/Map/change_sound.c							\
		Src/Trader/create_trader.c						\
		Src/Trader/init_trader.c						\
		Src/Inventory/move_inv.c 						\
		Src/Boat/boat_move.c 							\
		Src/Boat/init_boat.c							\
		Src/Draw/anim_all.c 							\
		Src/Door/dongeon_door.c 						\
		Src/Door/cave_door.c 							\
		Src/Dungeon/init_dungeon.c 						\
		Src/Dungeon/anim_key.c 							\
		Src/Dungeon/Dungeon_forest/dungeon_forest.c		\
		Src/Dungeon/Dungeon_forest/dungeon_interact.c 	\
		Src/Dungeon/Dungeon_forest/dungeon_f_arena.c 	\
		Src/Dungeon/dungeon_hud.c 						\
		Src/Dungeon/Dungeon_water/dungeon_water.c		\
		Src/Dungeon/Dungeon_sand/dungeon_sand.c			\
		Src/Dungeon/Dungeon_Mountain/dungeon_mountain.c	\
		Src/Dungeon/Dungeon_Lava/dungeon_lava.c			\
		Src/Settings/volume_handling.c					\
		Src/Monster/Ghost/ghost.c						\
		Src/Monster/Ghost/ghost_move.c					\
		Src/Monster/Ghost/attack_ghost.c				\
		Src/Player/player_colli.c 						\
		Src/Player/player_attack_dg.c 					\
		Src/command/get.c 								\
		Src/command/com_coli.c							\
		Src/command/is_com.c 							\
		Src/command/pos.c 								\
		Src/command/goto.c 								\
		Src/command/set.c 								\
		Src/command/get_input.c 						\
		Lib/cut_file.c									\
		Lib/my_str_to_word_array.c						\
		Lib/my_getnbr.c									\
		Src/Monster/Crab/crab.c 						\
		Src/Monster/Crab/crab_move.c 					\
		Src/Monster/Crab/attack_crab.c 					\
		Src/Monster/Snake/snake.c						\
		Src/Monster/Snake/snake_move.c					\
		Src/Monster/Snake/attack_snake.c				\
		Src/Monster/Golem/golem.c						\
		Src/Monster/Golem/golem_move.c					\
		Src/Monster/Golem/attack_golem.c				\
		Src/Monster/Dog/dog.c							\
		Src/Monster/Dog/dog_move.c						\
		Src/Monster/Dog/attack_dog.c					\
		Src/Loading/loading_screen.c 					\
		Src/Event/esc_eve.c 							\
		Src/Event/inv_eve.c 							\
		Src/Event/map_eve.c 							\
		Src/Event/event.c	 							\
		Src/Gem/init_gem.c	 							\
		Src/Gem/speed_gem.c	 							\
		Src/Gem/stg_gem.c	 							\
		Src/Gem/arm_gem.c	 							\
		Src/Save/save_in_file.c	 						\
		Src/Save/put_in_stru.c	 						\
		Src/Save/save_stone.c	 						\
		Src/Quests/init_quests.c						\
		Src/Quests/quests.c								\
		Src/Event/qts_eve.c								\
		Src/Dock/make_dock.c							\
		Lib/my_strcat.c									\
		Src/History/history.c							\
		Src/Die/screen_die.c							\
		Src/Tuto/display_msg.c							\
		Src/Tuto/init_tuto.c							\
		Src/Potion/heal_pot.c 							\
		Src/Big_torch/big_torch.c						\
		Src/Bomb/init_bomb.c							\
		Src/Dungeon/Dungeon_water/dungeon_w_arena.c		\
		Src/Dungeon/Dungeon_sand/dungeon_s_arena.c		\
		Src/Dungeon/Dungeon_Mountain/dungeon_m_arena.c	\
		Src/Tuto_item/tuto_item.c 						\
		Src/Boss/boss_move.c 							\
		Src/Boss/create_boss.c 							\
		Src/Boss/proj_move.c 							\
		Src/Boss/boss_attack.c 							\
		Src/Boss/boss_hit.c 							\
		Src/Boss/boss_anim.c 							\

OBJ = $(SRC:.c=.o)

NAME = my_rpg

OPTION = -lcsfml-window -lcsfml-graphics -lcsfml-system -lcsfml-audio -lm

all:
	gcc -g -o $(NAME) $(SRC) $(OPTION)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: all

execute:	re
	./$(NAME)
