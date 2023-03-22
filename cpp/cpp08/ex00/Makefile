# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kangkim <kangkim@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/17 23:04:19 by kangkim           #+#    #+#              #
#    Updated: 2022/04/18 00:43:20 by kangkim          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = c++
CXXFLAGS = -std=c++98 -pedantic -Wall -Wextra -Werror
CXXDEBUGFLAGS = -fsanitize=address -fsanitize=undefined

NAME = main
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)
HEADER = easyfind.hpp

all : $(NAME)

$(NAME) : $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o : %.cpp $(HEADER)
	$(CXX) $(CXXFLAGS) -c $<

debug : CXXFLAGS += $(CXXDEBUGFLAGS)
debug : re

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY : all debug clean fclean re