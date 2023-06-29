# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 19:58:17 by hanryu            #+#    #+#              #
#    Updated: 2023/06/28 14:42:32 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = account
CLANG = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = Account.cpp tests.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME) : $(OBJS)
	$(CLANG) $(CPPFLAGS) $^ -o $@

%.o : %.cpp
	$(CLANG) $(CPPFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re