# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 09:14:56 by hanryu            #+#    #+#              #
#    Updated: 2022/10/04 16:31:56 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCSDIR = ./srcs
SRCSNAME = main.c push_swap_utils.c ft_lst_stack.c swap_push_stack.c \
	rotate_stack.c r_rotate_stack.c argv_two_three.c argv_over_four.c \
	push_a_to_b.c
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSNAME))
OBJS = $(SRCS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBDIR) -l$(LIBNAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

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