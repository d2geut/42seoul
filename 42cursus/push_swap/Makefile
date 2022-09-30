# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 09:14:56 by hanryu            #+#    #+#              #
#    Updated: 2022/09/23 12:42:49 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCSDIR = ./srcs
SRCSNAME = main.c push_swap_utils.c ft_lst_stack.c swap_push_stack.c rotate_stack.c
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSNAME))
OBJS = $(SRCS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(LIBNAME) $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -c $< -o $@

all : $(NAME)

clean :
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)

fclean :
	make -C $(LIBDIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re : fclean all

PHONY : all clean fclean re