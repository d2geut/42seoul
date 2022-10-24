# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/22 09:14:56 by hanryu            #+#    #+#              #
#    Updated: 2022/10/24 11:02:18 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g2

RM = rm -f

SRCSDIR = ./srcs
SRCSNAME = main.c push_swap_utils.c ft_lst_stack.c swap_push_stack.c \
	rotate_stack.c r_rotate_stack.c argv_two_three.c argv_over_four.c \
	push_a_to_b.c
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSNAME))
OBJS = $(SRCS:.c=.o)

NAME_BONUS = checker
BONUSDIR = ./srcs/bonus
BONUSNAME = main_bonus.c get_next_line_bonus.c get_next_line_utils_bonus.c \
	push_swap_utils_bonus.c ft_lst_stack_bonus.c swap_push_stack_bonus.c \
	rotate_stack_bonus.c r_rotate_stack_bonus.c checker_bonus.c
BONUS = $(addprefix $(BONUSDIR)/, $(BONUSNAME))
OBJS_BONUS = $(BONUS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBDIR) -l$(LIBNAME)

$(NAME_BONUS) : $(OBJS_BONUS)
	$(CC) $(CFLAGS) $^ -o $@ -L$(LIBDIR) -l$(LIBNAME)

bonus :
	make $(NAME)
	make $(NAME_BONUS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(LIBDIR)

all : $(NAME)

clean :
	make -C $(LIBDIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C $(LIBDIR) fclean
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(NAME) $(NAME_BONUS)

re : fclean all

PHONY : all clean fclean re bonus