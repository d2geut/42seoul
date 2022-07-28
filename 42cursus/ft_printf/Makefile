# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/15 10:23:54 by hanryu            #+#    #+#              #
#    Updated: 2022/07/18 13:59:07 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f
AR = ar -rcs

SRCS = ft_printf.c ft_printf_utils.c ft_print_nbr.c ft_print_unbr.c ft_print_hexa.c
OBJS = $(SRCS:.c=.o)

SUBDIR = ./libft

all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(SUBDIR) bonus
	cp $(SUBDIR)/libft.a $(NAME)
	$(AR) $@ $(OBJS)
	
%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@ -I$(SUBDIR)

clean :
	make -C $(SUBDIR) clean
	$(RM) $(OBJS)
	
fclean :
	make -C $(SUBDIR) fclean
	$(RM) $(OBJS)
	$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re bonus