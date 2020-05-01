##
## EPITECH PROJECT, 2019
## MUL_my_rpg_2019
## File description:
## Makefile
##

ECHO =		/bin/echo -e
CURL =		/bin/curl
ONLINE =	/bin/nm-online
DEFAULT =	"\033[00m"
GREEN =		"\033[0;32m"
BGREEN =	"\033[1;32m"
TEAL =		"\033[1;36m"
ORANGE =	"\e[1;33m"
RED =		"\033[0;31m"
BRED =		"\033[1;31m"
FLASH =		"\e[5;30m"
BYELLOW =	"\e[1;33m"
BMAGENTA =	"\e[1;35m"

NAME	= my_rpg

CC	= gcc

RM	= rm -f

SRCS	=	src/main.c										\
			src/event.c										\
			src/draw/draw.c									\
			src/draw/draw_text.c							\
			src/destroy/destroy.c							\
			src/destroy/destroy_button.c					\
			src/destroy/destroy_text.c						\
			src/destroy/destroy_save.c						\
			src/create/create.c							\
			src/create/create_text.c						\
			src/create/create_window.c						\
			src/create/create_background.c					\
			src/create/create_button.c						\
			src/create/create_enemy.c						\
			src/create/create_player.c						\
			src/scenes/start_menu.c							\
			src/create_backgrounds/start_menu_background.c	\
			src/create_buttons/start_menu_button.c			\
			src/create_players/start_menu_player.c			\
			src/create_enemies/start_menu_enemy.c			\
			src/scenes/save.c								\
			src/create_backgrounds/save_background.c		\
			src/create_buttons/save_button.c				\
			src/create_players/save_player.c				\
			src/create_enemies/save_enemy.c					\
			src/scenes/game.c								\
			src/create_backgrounds/game_background.c		\
			src/create_buttons/game_button.c				\
			src/create_players/game_player.c				\
			src/create_enemies/game_enemy.c					\
			src/tools/get_mouse_pos.c						\
			src/tools/is_mouse_over_button.c				\
			src/tools/is_arrow_pressed.c					\
			src/callback/quit_cb.c							\
			src/callback/play_cb.c							\
			src/callback/create_cb.c						\
			src/callback/game_cb.c							\
			src/callback/return_cb.c						\
			src/callback/new_cb.c							\
			src/tools/handle_buttons.c						\
			src/save/check_save.c							\
			src/save/get_save_data.c						\
			src/anim/anim_player.c							\
			src/move/move_player_and_background.c			\
			src/create_texts/game_text.c					\
			src/create_texts/save_text.c					\
			src/create_texts/start_menu_text.c				\
			src/scenes/new.c								\
			src/create_backgrounds/new_background.c			\
			src/create_buttons/new_button.c					\
			src/create_players/new_player.c					\
			src/create_enemies/new_enemy.c					\
			src/create_texts/new_text.c						\
			src/fight/fight_count.c							\
			src/fight/fight_effects.c						\
			src/scenes/fight.c								\
			src/create_backgrounds/fight_background.c		\
			src/create_players/fight_player.c				\
			src/create_enemies/fight_enemy.c				\
			src/fight/menu_display.c						\
			src/create_buttons/fight_button.c				\
			src/save/write_save_name.c						\
			src/scenes/pause.c								\
			src/create_backgrounds/pause_background.c		\
			src/create_buttons/pause_button.c				\
			src/create_players/pause_player.c				\
			src/create_enemies/pause_enemy.c				\
			src/create_texts/pause_text.c					\
			src/callback/help_cb.c							\
			src/callback/resume_cb.c						\
			src/create_texts/fight_text.c					\
			src/save/update_save_file.c						\
			src/save/fulfill_save.c							\
			src/scenes/help.c								\
			src/create_backgrounds/help_background.c		\
			src/create_buttons/help_button.c				\
			src/create_players/help_player.c				\
			src/create_enemies/help_enemy.c					\
			src/create_texts/help_text.c					\
			src/scenes/inv_and_stat.c						\
			src/create_backgrounds/inv_and_stat_background.c\
			src/create_buttons/inv_and_stat_button.c		\
			src/create_players/inv_and_stat_player.c		\
			src/create_enemies/inv_and_stat_enemy.c			\
			src/create_texts/inv_and_stat_text.c			\
			src/move/move_npc.c 							\

OBJS	= $(SRCS:.c=.o)

LIB = lib/libmy.a

CFLAGS = -I ./include/
CFLAGS += -Wall -Wextra
CFLAGS += -L./lib -lmy -g
CSFML += -l csfml-system -l csfml-window -l csfml-graphics -l csfml-audio

all: $(NAME)

$(NAME): binary_name $(LIB) $(OBJS)
	@$(CC) $(OBJS) -o $(NAME) $(CFLAGS) $(CSFML) && \
	$(ECHO) $(BGREEN) "Build Complete !" $(DEFAULT) \
	|| $(ECHO) $(FLASH) $(BRED) "Build Failed !" $(DEFAULT)

clean:
	@make -C lib/my clean --no-print-directory
	@$(RM) $(OBJS)
	@$(ECHO) $(BMAGENTA) "clean" $(DEFAULT)

$(LIB):
	@make -C lib/my --no-print-directory
	@$(ECHO) $(BGREEN) "Lib Complete !\n"

fclean: clean
	@make -C lib/my fclean --no-print-directory
	@$(RM) $(NAME)
	@$(ECHO) $(BMAGENTA) "fclean" $(DEFAULT)

re: fclean all

debug: CFLAGS += -g
debug: re
		@$(ECHO) $(BRED) "Debug mode"

binary_name:
	@$(ECHO) $(TEAL)
	@$(ONLINE) -q -t 2 && \
	$(CURL) http://artii.herokuapp.com/make?text=$(NAME) \
	|| $(ECHO) -n $(TEAL) Building $(NAME)...
	@$(ECHO) '\n'

.PHONY: all clean fclean re binary_name

.c.o:
		@gcc $(CFLAGS) -c -o $@ $^ && $(ECHO) \
		$(BGREEN)"[OK]"$(BYELLOW) `basename $^` $(DEFAULT) \
		|| $(ECHO) $(BRED)"[ERROR]"$(BYELLOW) $< $(DEFAULT)
