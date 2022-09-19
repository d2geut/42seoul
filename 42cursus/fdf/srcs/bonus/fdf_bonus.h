/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:40:59 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:37:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# include <mlx.h>
# define WINDOW_MAX_X 1600
# define WINDOW_MAX_Y 1200
# define WINDOW_MARGIN_X 1400
# define WINDOW_MARGIN_Y 1000
# define EVENT_KEY_PRESS 2
# define EVENT_KEY_RELEASE 3
# define EVENT_MOUSE_PRESS 4
# define EVENT_MOUSE_RELEASE 5
# define EVENT_MOUSE_MOVE 6
# define EVENT_KEY_EXIT 17
# define KEY_ESC 53
# define KEY_H 4
# define KEY_C 8
# define KEY_SHIFT 257
# define MOUSE_MIDDLE 3
# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

typedef struct s_map
{
	int		index;
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

typedef struct s_deri
{
	int	dx;
	int	dy;
	int	sign_x;
	int	sign_y;
}	t_deri;

typedef struct s_data
{
	t_map	**link;
	int		row;
	int		column;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	void	*mlx;
	void	*win;
	int		trans;
	int		rotate;
	int		x;
	int		y;
}	t_data;

typedef struct s_zsort
{
	int		i;
	int		j;
	double	z;
}	t_zsort;

char	*get_next_line(int fd);
void	fdf_error(int n);
int		file_check(int fd, int *row, int *column);
t_map	**save_map_data(int fd, const int row, const int column);
int		ft_getnbr(char *str);
void	ft_free(void **ptr);
void	ft_2darray_free(char ***arr);
void	free_map(t_map ***map);
void	movement_map_default(t_map **map, const int row, const int column);
void	conic_default(t_map **map, const int row, const int column);
void	translate_default(t_map **map, const int row, const int column);
void	scale_default(t_map **map, const int row, const int column, \
double scale);
void	rotate_x(double *x, double *y, double *z, double angle);
void	rotate_y(double *x, double *y, double *z, double angle);
void	rotate_z(double *x, double *y, double *z, double angle);
double	margin_scale(double max_x, double max_y);
void	window_map(t_map **map, const int row, const int column);
int		key_press(int keycode, t_data *data);
int		key_exit(t_data *data);
int		key_release(int keycode, t_data *data);
int		mouse_press(int button, int x, int y, t_data *data);
int		mouse_release(int button, int x, int y, t_data *data);
int		mouse_hook(int x, int y, t_data *data);
void	set_default(t_data *data, int flag);
void	scale_map(t_data *data, int flag);
void	translate_map(t_data *data, int dx, int dy);
void	rotate_map(t_data *data, int dx, int dy);
void	pixel_put_image(t_map **map, const int row, const int column, \
t_data *data);
void	draw_line(t_map start, t_map end, t_data *data);
int		pixel_color(t_map start, t_map end, int d, int i);
int		clipping(t_map *start, t_map *end);

#endif