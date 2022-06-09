# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 20:25:24 by yehyun            #+#    #+#              #
#    Updated: 2022/06/09 12:21:41 by yehyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = bsq.c into_field.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/ft_check_line.c srcs/ft_check_height.c srcs/ft_min.c srcs/ft_make_map.c
OBJS = $(SRCS:.c=.o)

NAME = bsq
TEMP = "temp_map"

all : $(NAME) $(TEMP)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

$(TEMP) :
	touch $(TEMP)
	chmod guo+rw $(TEMP)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(NAME) $(TEMP)
	$(RM) $(OBJS)

re : fclean all

.PHONY : all clean fclean re