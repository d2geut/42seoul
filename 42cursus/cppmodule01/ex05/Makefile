# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:58:17 by hanryu            #+#    #+#              #
#    Updated: 2023/06/30 07:49:10 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = harl
CC = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = main.cpp Harl.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CC) $(CXXFLAGS) $^ -o $@

%.o : %.cpp
	$(CC) $(CXXFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re