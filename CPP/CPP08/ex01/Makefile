# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/10 03:00:57 by tpipi             #+#    #+#              #
#    Updated: 2025/06/04 17:03:22 by tpipi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Span

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98
RM = rm -f

SRC = main.cpp Span.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o : %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re