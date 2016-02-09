# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pivanovi <pivanovi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/10/30 15:30:51 by pivanovi          #+#    #+#              #
#    Updated: 2015/10/30 15:30:51 by pivanovi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TOOLS =			srcs/ft_atoi.c						\
				srcs/strings.c						\
				srcs/strings2.c						\
				srcs/strings3.c						\
				srcs/list.c							\
				srcs/list2.c

SRC_CLIENT =	srcs_client/client.c				\
				srcs_client/command.c				\
				srcs_client/set_client.c			\
				srcs_client/fd.c

SRC_SERVER =	srcs_server/main.c					\
				srcs_server/client_write.c			\
				srcs_server/client_read.c			\
				srcs_server/srv_create.c			\
				srcs_server/srv_accept.c			\
				srcs_server/main_loop.c				\
				srcs_server/do_select.c				\
				srcs_server/clean_fd.c				\
				srcs_server/check_fd.c				\
				srcs_server/init_env.c				\
				srcs_server/get_opt.c				\
				srcs_server/init_fd.c				\
				srcs_server/x.c						\
				srcs_server/command.c				\
				srcs_server/command2.c


OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_TOOLS = $(TOOLS:.c=.o)

CFLAGS += -I./includes

all: server client

server: $(OBJ_SERVER) $(OBJ_TOOLS)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(OBJ_TOOLS) -o $@

client: $(OBJ_CLIENT) $(OBJ_TOOLS)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(OBJ_TOOLS) -o $@

clean:
	/bin/rm -f $(OBJ_CLIENT) && /bin/rm -f $(OBJ_SERVER)	\
	&& /bin/rm -f $(OBJ_TOOLS)

fclean: clean
	/bin/rm -f server && /bin/rm -f client

re: fclean all

