# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivanderw <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/31 15:10:22 by ivanderw          #+#    #+#              #
#    Updated: 2023/09/19 20:25:47 by ivanderw         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

MLX = mlx/libmlx.a

LIBFT_DIR = source/libft/

CC_FLAGS = gcc -Wall -Wextra -Werror -I includes -I mlx \
		   	-Lmlx -lmlx -framework OpenGL \
			-L$(LIBFT_DIR) -lft		\
			-framework AppKit #-fsanitize=address -g

SOURCE  = 	source/main.c						\
			source/utilities/check_utils.c		\
			source/utilities/clear_checks.c 	\
			source/utilities/draw_map.c			\
			source/utilities/enemy_utils.c		\
			source/utilities/fill_check_map.c	\
			source/utilities/frame_refresh.c	\
			source/utilities/ft_printbr.c		\
			source/utilities/ft_start_exit.c	\
			source/utilities/iterate_enemy.c	\
			source/utilities/keycode_utils.c	\
			source/utilities/map_utils.c		\
			source/utilities/misc_utils.c		\
			source/utilities/move_utils.c		\
			source/utilities/move_utils_2.c		\
			source/utilities/path_setting.c		\
			source/utilities/point_utils.c		\
			source/utilities/refresh_map.c		\
			source/utilities/state_utils.c		

all: $(NAME)

OBJECTS = $(source:%.c=%.o)

%.o: %.c
	$(CC_FLAGS) -o $@ -c $<

$(NAME):  $(MLX) $(LIBFT)
	$(CC_FLAGS) $(SOURCE) -o $(NAME)

$(MLX):
	make -C mlx

$(LIBFT):
	make -C source/libft

clean:
	@rm -f $(OBJECTS)

fclean: clean
	@rm -rf $(NAME)
	@make -C mlx clean
	@make -C $(LIBFT_DIR) clean

re: fclean all
ca: clean all

.PHONY: all clean fclean re
