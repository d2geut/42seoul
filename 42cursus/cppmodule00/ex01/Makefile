# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/26 17:27:17 by hanryu            #+#    #+#              #
#    Updated: 2023/06/28 10:38:18 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
CLANG = clang++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

RM = rm -f

SRCS = PhoneBook.cpp Contact.cpp main.cpp
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