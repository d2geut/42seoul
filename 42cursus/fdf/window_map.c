/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:39:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/05 14:56:44 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	bresenham_x(t_map start, t_map end, t_data *data, int dx, int dy, int sign_x, int sign_y)
{
	int	x;
	int	y;
	int	det;
	int	i;

	x = start.x;
	y = start.y;
	det = (2 * dy) - dx;
	i = dx;
	my_mlx_pixel_put(data, start.x + WINDOW_MAX_X / 2, start.y + WINDOW_MAX_Y / 2, start.color);
	while (i > 0)
	{
		if (det < 0)
			det += 2 * dy;
		else
		{
			y += sign_y;
			det += 2 * (dy - dx);
		}
		x += sign_x;
		i--;
		my_mlx_pixel_put(data, x + WINDOW_MAX_X / 2, y + WINDOW_MAX_Y / 2, pixel_color(start, end, dx, i));
	}
	my_mlx_pixel_put(data, end.x + WINDOW_MAX_X / 2, end.y + WINDOW_MAX_Y / 2, end.color);
}

void	bresenham_y(t_map start, t_map end, t_data *data, int dx, int dy, int sign_x, int sign_y)
{
	int	x;
	int	y;
	int	det;
	int	i;

	x = start.x;
	y = start.y;
	det = (2 * dx) - dy;
	i = dy;
	my_mlx_pixel_put(data, start.x + WINDOW_MAX_X / 2, start.y + WINDOW_MAX_Y / 2, start.color);
	while (i > 0)
	{
		if (det < 0)
			det += 2 * dx;
		else
		{
			x += sign_x;
			det += 2 * dx - 2 * dy;
		}
		y += sign_y;
		i--;
		my_mlx_pixel_put(data, x + WINDOW_MAX_X / 2, y + WINDOW_MAX_Y / 2, pixel_color(start, end, dy, i));
	}
	my_mlx_pixel_put(data, end.x + WINDOW_MAX_X / 2, end.y + WINDOW_MAX_Y / 2, end.color);
}

void	draw_line(t_map start, t_map end, t_data *data)
{
	int	dx;
	int	dy;
	int	sign_x;
	int	sign_y;

	dx = abs((int)end.x - (int)start.x); //수정해야함.
	dy = abs((int)end.y - (int)start.y);
	sign_x = 1;
	sign_y = 1;
	if (end.x < start.x)
		sign_x = -1;
	if (end.y < start.y)
		sign_y = -1;
	if (dx > dy)
		bresenham_x(start, end, data, dx, dy, sign_x, sign_y);
	else
		bresenham_y(start, end, data, dx, dy, sign_x, sign_y);
}

void	pixel_put_image(t_map **map, const int row, const int column, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (j < column - 1)
				draw_line(map[i][j], map[i][j + 1], data);
			if (i < row - 1)
				draw_line(map[i][j], map[i + 1][j], data);
			j++;
		}
		i++;
	}
}

void	window_map(t_map **map, const int row, const int column)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_MAX_X, WINDOW_MAX_Y, "fdf");
	img.img = mlx_new_image(mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	pixel_put_image(map, row, column, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
