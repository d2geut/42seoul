# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/28 10:50:14 by hanryu            #+#    #+#              #
#    Updated: 2023/03/25 16:23:31 by hanryu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = cc
CFLAGS = -Wall -Wextra -Werror

RM = rm -f

SRCSDIR = ./srcs
SRCSNAME = main.c fdf_utils.c file_check.c map_control.c map_parsing.c \
	get_next_line.c get_next_line_utils.c map_movement_default.c rotate_3d.c \
	window_map.c pixel_color.c pixel_put_image.c fdf_error.c
SRCS = $(addprefix $(SRCSDIR)/, $(SRCSNAME))
OBJS = $(SRCS:.c=.o)

BONUSDIR = ./srcs/bonus
BONUSNAME = main_bonus.c fdf_utils_bonus.c file_check_bonus.c map_parsing_bonus.c \
	get_next_line_bonus.c get_next_line_utils_bonus.c isometric_conic_bonus.c \
	movement_default_map_bonus.c rotate_3d_bonus.c window_map_bonus.c pixel_color_bonus.c \
	pixel_put_image_bonus.c draw_line_bonus.c fdf_error_bonus.c \
	clipping_bonus.c movement_map_bonus.c key_hook_bonus.c mouse_hook_bonus.c
BONUS = $(addprefix $(BONUSDIR)/, $(BONUSNAME))
OBJS_BONUS = $(BONUS:.c=.o)

LIBNAME = ft
LIBDIR = ./libft

MLXNAME = mlx
MLXDIR = ./mlx
MLX = libmlx.dylib

ifdef IS_BONUS
	OBJS := $(OBJS_BONUS)
else
	OBJS := $(OBJS)
endif

$(NAME) : $(OBJS)
	make -C $(LIBDIR) bonus
	make -C $(MLXDIR) all
	cp $(MLXDIR)/$(MLX) $(MLX)
	$(CC) $(CFLAGS) -L$(LIBDIR) -l$(LIBNAME) -L$(MLXDIR) -l$(MLXNAME) \
		-framework OpenGL -framework AppKit $^ -o $@

bonus :
	make IS_BONUS=1 $(NAME)

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

.PHONY : all clean fclean re bonus