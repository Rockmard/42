# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 18:04:12 by tpipi             #+#    #+#              #
#    Updated: 2024/02/02 19:08:36 by tpipi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Wextra -Werror
SRC =	stack_utils.c \
		stack_fill_utils.c \
		operations_utils.c \
		sorting.c \
		sorting_utils.c \
		push_swap.c
OBJ = $(SRC:.c=.o)
LIBFT = ./libft/libft.a
NAME = push_swap

all : $(NAME)

$(NAME) : $(LIBFT) $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT) :
	make -C libft bonus --no-print-directory

clean :
	rm -f $(OBJ)
	make -C libft clean --no-print-directory

fclean : clean
	rm -f $(NAME)
	make -C libft fclean --no-print-directory

re : fclean all

.PHONY : all clean fclean re libft
