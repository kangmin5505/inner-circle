# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 11:54:02 by kangkim           #+#    #+#              #
#    Updated: 2021/12/23 14:25:45 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = server client

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = server_bonus.c	\
	   client_bonus.c	\

OBJS = $(SRCS:.c=.o)

# libftprintf
LIBFTPRINTF_DIR = libftprintf
LIBFTPRINTF_A = $(LIBFTPRINTF_DIR)/libftprintf.a

all: $(NAME)

server: server_bonus.o $(LIBFTPRINTF_A)
	$(CC) $(CFLAGS) -o $@ $^

client: client_bonus.o $(LIBFTPRINTF_A)
	$(CC) $(CFLAGS) -o $@ $^ 

$(LIBFTPRINTF_A):
	make -C $(LIBFTPRINTF_DIR) all

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)
	make -C $(LIBFTPRINTF_DIR) clean 

fclean: clean
	$(RM) $(NAME)
	make -C $(LIBFTPRINTF_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
