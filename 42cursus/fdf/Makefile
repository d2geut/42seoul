# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 10:50:14 by hanryu            #+#    #+#              #
#    Updated: 2022/07/28 18:04:06 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c
OBJS = $(SRCS:.c=.o)

MLXNAME = mlx
MLXDIR = ./mlx
MLX = libmlx.dylib

$(NAME) : $(OBJS)
	make -C $(MLXDIR) all
	cp $(MLXDIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) -L$(MLXDIR) -l$(MLXNAME) -framework OpenGL -framework AppKit $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(MLXDIR) -c $< -o $@

all : $(NAME)

clean :
	make -C $(MLXDIR) clean
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(MLX)

re : fclean all

.PHONY : all clean fclean re