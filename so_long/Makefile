# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 18:04:12 by tpipi             #+#    #+#              #
#    Updated: 2024/02/20 12:40:43 by tpipi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC =	so_long.c path_checker.c \
		maps_utils.c maps_parsing.c maps_errors.c \
		images_utils.c mlx_utils.c event_utils.c \
		get_next_line.c get_next_line_utils.c
SRC := $(addprefix srcs/, $(SRC))
OBJ = $(SRC:.c=.o)

LIBFT = libft/libft.a
MLX = MacroLibX/libmlx.so

all : $(NAME)

$(NAME) : $(LIBFT) $(MLX) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -lSDL2 $(MLX) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) :
	@make -C libft bonus -j --no-print-directory

$(MLX):
	@make -C MacroLibX -j --no-print-directory

clean :
	rm -f $(OBJ)
	make -C libft clean --no-print-directory
	make -C MacroLibX clean --no-print-directory

fclean : clean
	rm -f $(NAME)
	make -C libft fclean --no-print-directory
	make -C MacroLibX fclean --no-print-directory

re : fclean all

.PHONY : all clean fclean re
