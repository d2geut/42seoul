# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 14:01:59 by hanryu            #+#    #+#              #
#    Updated: 2022/06/06 20:04:50 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = ft_cat
SRCS = ft_catcat.c ft_putstr.c
OBJS = $(SRCS:.c=.o)

all : $(NAME)

.c.o :
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

clean :
	rm -r $(OBJS)

fclean :
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
