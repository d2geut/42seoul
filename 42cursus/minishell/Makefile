# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/31 15:46:19 by hanryu            #+#    #+#              #
#    Updated: 2023/02/06 14:58:33 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = builtin
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
RM = rm -f

SRCS = main.c ft_list.c builtin_command.c builtin_utils.c
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