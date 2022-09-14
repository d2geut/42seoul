/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:39:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/14 14:48:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_default(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->link[i][j].y = i;
			data->link[i][j].x = j;
			data->link[i][j].z = data->link[i][j].index;
			j++;
		}
		i++;
	}
	movement_map_default(data->link, data->row, data->column);
}

static int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		exit(0);
	else if (keycode == 4)
		set_default(data);
	else if (keycode == 257 && !data->trans)
		data->rotate = 1;
	return (0);
}

static int	key_exit(t_data *data)
{
	(void)data;
	exit(0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == 257)
		data->rotate = 0;
	return (0);
}

void	scale_map(t_data *data, int flag)
{
	double	n;
	int		i;
	int		j;

	if (!flag)
		n = 2;
	else
		n = 1 / (double)2;
	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->link[i][j].x *= n;
			data->link[i][j].y *= n;
			data->link[i][j].z *= n;
			j++;
		}
		i++;
	}
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 3)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		data->x = x;
		data->y = y;
		data->trans = 1;
	}
	else if (button == 4)
		scale_map(data, 0);
	else if (button == 5)
		scale_map(data, 1);
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == 3)
		data->trans = 0;
	return (0);
}

void	translate_map(t_data *data, int dx, int dy)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			data->link[i][j].x += dx;
			data->link[i][j].y += dy;
			j++;
		}
		i++;
	}
}

void	rotate_map(t_data *data, int dx, int dy)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->row)
	{
		j = 0;
		while (j < data->column)
		{
			rotate_y(&data->link[i][j].x, &data->link[i][j].y, &data->link[i][j].z, -2 * M_PI * dx / WINDOW_MAX_X);
			rotate_x(&data->link[i][j].x, &data->link[i][j].y, &data->link[i][j].z, -2 * M_PI * dy / WINDOW_MAX_Y);
			j++;
		}
		i++;
	}
}

int	mouse_hook(int x, int y, t_data *data)
{
	if (data->rotate && data->trans)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		rotate_map(data, x - data->x, y - data->y);
		data->x = x;
		data->y = y;
	}
	else if (data->trans)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		translate_map(data, x - data->x, y - data->y);
		data->x = x;
		data->y = y;
	}
	return (0);
}

int	main_loop(t_data *data)
{
	mlx_destroy_image(data->mlx, data->img);
	data->img = mlx_new_image(data->mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (!data->img)
		fdf_error(1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	pixel_put_image(data->link, data->row, data->column, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

void	window_map(t_map **map, const int row, const int column)
{
	t_data	data;

	data.link = map;
	data.row = row;
	data.column = column;
	data.trans = 0;
	data.rotate = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_MAX_X, WINDOW_MAX_Y, "fdf");
	if (!data.win)
		fdf_error(5);
	data.img = mlx_new_image(data.mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (!data.img)
		fdf_error(1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	pixel_put_image(map, row, column, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, EVENT_KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, EVENT_KEY_RELEASE, 0, key_release, &data);
	mlx_hook(data.win, EVENT_KEY_EXIT, 0, key_exit, &data);
	mlx_hook(data.win, EVENT_MOUSE_PRESS, 0, mouse_press, &data);
	mlx_hook(data.win, EVENT_MOUSE_RELEASE, 0, mouse_release, &data);
	mlx_hook(data.win, EVENT_MOUSE_MOVE, 0, mouse_hook, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
}
