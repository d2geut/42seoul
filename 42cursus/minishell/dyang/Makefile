# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dyang <dyang@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/27 14:21:08 by dyang             #+#    #+#              #
#    Updated: 2023/01/27 15:51:53 by dyang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR=ar
CC=cc
CFLAGS=-Wall -Wextra -Werror
M_OBJS=main.o ft_list.o
M_SRCS=$(M_OBJS:.o=.c)
LIBFTDIR=./libft
LIBFT=$(LIBFTDIR)/libft.a
NAME=minishell

all: $(NAME)
$(NAME): $(M_OBJS)
	make -C $(LIBFTDIR) all
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) -lreadline
.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<
clean:
	make -C $(LIBFTDIR) clean
	rm -f $(M_OBJS)
fclean: clean
	make -C $(LIBFTDIR) fclean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re