# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/01 20:25:24 by yehyun            #+#    #+#              #
#    Updated: 2022/06/05 12:15:43 by yehyun           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = bsq.c into_field.c srcs/ft_atoi.c srcs/ft_putstr.c srcs/ft_check_line.c srcs/ft_check_height.c srcs/ft_min.c srcs/ft_make_map.c
OBJS = $(SRCS:.c=.o)

TARGET = bsq

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.c.o :
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS)
	$(RM) $(TARGET)

re : fclean all

.PHONY : all clean fclean re