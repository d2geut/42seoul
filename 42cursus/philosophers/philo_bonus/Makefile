# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 08:22:23 by hanryu            #+#    #+#              #
#    Updated: 2023/01/05 13:46:15 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCS = main_bonus.c philo_utils_bonus.c philo_bonus.c philo_print_bonus.c \
	philo_init_bonus.c philo_utils2_bonus.c philo_monitor_bonus.c
OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJS)

fclean :
	$(RM) $(OBJS)
	$(RM) $(NAME)

re : fclean all

PHONY : all clean fclean re
