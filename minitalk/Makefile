# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tpipi <tpipi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/02 18:04:12 by tpipi             #+#    #+#              #
#    Updated: 2024/02/27 15:46:30 by tpipi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT = client
SERVER = server

CC = cc
FLAGS = -Wall -Wextra -Werror

PRINTF_SRC = ft_strlen.c ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_base.c ft_putpointer.c
PRINTF_SRC := $(addprefix srcs/printf/, $(PRINTF_SRC))
PRINTF_OBJ = $(PRINTF_SRC:.c=.o)

CLIENT_SRC = srcs/client.c $(PRINTF_SRC)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)

SERVER_SRC = srcs/server.c $(PRINTF_SRC)
SERVER_OBJ = $(SERVER_SRC:.c=.o)

ifdef BONUS
	SERVER_SRC = srcs/server_bonus.c $(PRINTF_SRC)
	CLIENT_SRC = srcs/client_bonus.c $(PRINTF_SRC)
	CLIENT = client_bonus
	SERVER = server_bonus
endif

all : $(CLIENT) $(SERVER)

$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_OBJ) -o $(CLIENT)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_OBJ) -o $(SERVER)

bonus :
	@make BONUS=1 --no-print-directory

%.o : %.c
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -f $(CLIENT_OBJ) $(SERVER_OBJ) srcs/client_bonus.o srcs/server_bonus.o

fclean : clean
	rm -f $(CLIENT) $(SERVER) client_bonus server_bonus

re : fclean all

.PHONY : all clean fclean re bonus
