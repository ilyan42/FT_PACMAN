# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ilbendib <ilbendib@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 17:49:42 by ilbendib          #+#    #+#              #
#    Updated: 2024/01/03 11:54:36 by ilbendib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
CC = gcc -g3
CFLAGS = -Wall -Wextra -Werror
_HEADERS = so_long.h

_SRCS = 		src/main.c 	src/game/ft_map_init.c\
						src/game/ft_handle_key_press.c\
						src/game/ft_move_is_good.c\
						src/game/ft_move.c\
						src/game/ft_nb_colect.c\
						src/game/ft_draw_pacman.c\
						src/game/ft_draw_map.c\
						src/game/ft_put_map.c\
						src/game/ft_draw_monster.c\
						src/game/ft_check_map.c\
						src/game/ft_utils.c\
						src/monster/ft_init_monster_blue.c\
						src/monster/ft_move_monster_blue.c\
						src/monster/ft_init_monster_green.c\
						src/monster/ft_move_monster_green.c\
						src/monster/ft_init_monster_red.c\
						src/monster/ft_move_monster_red.c\
						src/monster/ft_move_monster_blue_utils.c\
						src/parsing_map/ft_parsing_map.c\
						src/parsing_map/ft_parsing_error.c\
						src/parsing_map/ft_parsing_error_2.c\
						src/parsing_map/ft_parsing_error_3.c\


SRC_DIR = .

SRCS = $(_SRCS:%=$(SRC_DIR)/%)

HEADERS_DIR = .

HEADERS = $(_HEADERS:%=$(HEADERS_DIR)/%)

UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S),Linux)
	LDFLAGS = -Lminilibx-linux -lmlx ./LIBFT/libft.a -lXext -lX11 -lm -lz
else ifeq ($(UNAME_S),Darwin)
	LDFLAGS = -Lmlx -lmlx -Imlx -L./LIBFT -lft -framework OpenGL -framework AppKit
else
	$(error Unsupported operating system: $(UNAME_S))
endif

AR = ar

ARFLAGS = rcs

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I$(HEADERS_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(MAKE) all -C ./LIBFT 
	$(MAKE) -C minilibx-linux
	$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) 

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	$(MAKE) fclean -C ./LIBFT
	$(MAKE) clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re
