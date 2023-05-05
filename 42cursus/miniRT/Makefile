# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/25 15:56:04 by hanryu            #+#    #+#              #
#    Updated: 2023/05/05 18:05:02 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = miniRT
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCS = main.c camera.c ray.c ray_object.c vec.c object.c
OBJS = $(SRCS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

MLXNAME = mlx
MLXDIR = ./minilibx_mms_20210621
MLX = libmlx.dylib

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	make -C $(MLXDIR) all
	cp $(MLXDIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(LIBNAME) -L$(MLXDIR) -l$(MLXNAME) \
		-framework OpenGL -framework AppKit $^ -o $@

%.o : %.c
	$(CC) $(CFLAGS) -I$(LIBDIR) -I$(MLXDIR) -c $< -o $@

all : $(NAME)

clean :
	make -C $(LIBDIR) clean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean :
	make -C $(LIBDIR) fclean
	make -C $(MLXDIR) clean
	$(RM) $(OBJS) $(OBJS_BONUS)
	$(RM) $(NAME) $(MLX)

re : fclean all

.PHONY : all clean fclean re