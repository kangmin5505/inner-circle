# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.k>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/03 17:04:19 by kangkim           #+#    #+#              #
#    Updated: 2021/12/27 17:07:54 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
_END	=	\033[0;0m
_GREEN	=	\033[0;32m

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm
RMFLAGS = -f

SRCS = ft_printf.c 				\
	fmt_info.c					\
	parse_specifier_detail.c	\
	print_character.c			\
	print_pointer.c				\
	print_number.c				\
	print_percent.c				\
	utils.c						\
	
OBJS = $(SRCS:.c=.o)

# libft
LIBFT_DIR = libft
LIBFT_A = libft.a

all: $(NAME)

bonus : all

$(NAME): $(OBJS)
	@echo "$(_GREEN)[ Try to make $(LIBFT_A) ]$(_END)"
	@$(MAKE) -s -C $(LIBFT_DIR) all
	@echo "$(_GREEN)[ Done ]$(_END)"
	@echo "$(_GREEN)[ Try to make $(NAME) ]$(_END)"
	@$(AR) $(NAME) $(OBJS) $(LIBFT_DIR)/$(LIBFT_A)
	@echo "$(_GREEN)[ Done ]$(_END)"

.c.o:
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "$(_GREEN)[ Try to clean ]$(_END)" 
	@$(RM) $(RMFLAGS) $(OBJS)
	@make -s -C $(LIBFT_DIR) clean 
	@echo "$(_GREEN)[ Done ]$(_END)"

fclean : clean
	@echo "$(_GREEN)[ Try to fclean ]$(_END)"
	@$(RM) $(RMFLAGS) $(NAME)
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(_GREEN)[ Done ]$(_END)"

re : fclean all

.PHONY: all bonus clean fclean re
