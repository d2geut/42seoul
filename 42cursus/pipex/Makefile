# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 13:34:19 by hanryu            #+#    #+#              #
#    Updated: 2022/12/06 06:27:34 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

SRCSDIR = ./srcs
SRCSNAME = main.c command_path.c pipex_util.c command_process.c
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