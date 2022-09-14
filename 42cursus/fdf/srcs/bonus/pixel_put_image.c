/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:52:48 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/14 14:51:56 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WINDOW_MAX_X) && (0 <= y && y < WINDOW_MAX_Y))
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	bresenham_x(t_map start, t_map end, t_data *data, t_deri deri)
{
	int	x;
	int	y;
	int	det;
	int	i;

	x = start.x;
	y = start.y;
	det = (2 * deri.dy) - deri.dx;
	i = deri.dx;
	while (i-- > 0)
	{
		if (det < 0)
			det += 2 * deri.dy;
		else
		{
			y += deri.sign_y;
			det += 2 * (deri.dy - deri.dx);
		}
		x += deri.sign_x;
		my_mlx_pixel_put(data, x + WINDOW_MAX_X / 2, y + WINDOW_MAX_Y / 2, \
		pixel_color(start, end, deri.dx, i));
	}
}

static void	bresenham_y(t_map start, t_map end, t_data *data, t_deri deri)
{
	int	x;
	int	y;
	int	det;
	int	i;

	x = start.x;
	y = start.y;
	det = (2 * deri.dx) - deri.dy;
	i = deri.dy;
	while (i-- > 0)
	{
		if (det < 0)
			det += 2 * deri.dx;
		else
		{
			x += deri.sign_x;
			det += 2 * (deri.dx - deri.dy);
		}
		y += deri.sign_y;
		my_mlx_pixel_put(data, x + WINDOW_MAX_X / 2, y + WINDOW_MAX_Y / 2, \
		pixel_color(start, end, deri.dy, i));
	}
}

static void	draw_line(t_map start, t_map end, t_data *data)
{
	t_deri	deri;

	if (clipping(&start.x, &start.y, &end.x, &end.y))
		return ;
	deri.dx = (int)fabs((double)((int)end.x - (int)start.x));
	deri.dy = (int)fabs((double)((int)end.y - (int)start.y));
	deri.sign_x = 1;
	deri.sign_y = 1;
	if (end.x < start.x)
		deri.sign_x = -1;
	if (end.y < start.y)
		deri.sign_y = -1;
	my_mlx_pixel_put(data, start.x + WINDOW_MAX_X / 2, \
	start.y + WINDOW_MAX_Y / 2, start.color);
	if (deri.dx > deri.dy)
		bresenham_x(start, end, data, deri);
	else
		bresenham_y(start, end, data, deri);
	my_mlx_pixel_put(data, end.x + WINDOW_MAX_X / 2, \
	end.y + WINDOW_MAX_Y / 2, end.color);
}

int	compare(const void *a, const void *b)
{
	t_zsort	*pa = (t_zsort *)a;
	t_zsort	*pb = (t_zsort *)b;

	if (pa->z > pb->z)
		return (1);
	else if (pa->z < pb->z)
		return (-1);
	else
		return (0);
}

void	pixel_put_image(t_map **map, const int row, const int column, \
t_data *data)
{
	int		i;
	int		j;
	t_zsort	*zsort;
	int		num;

	num = row * column;
	zsort = (t_zsort *)malloc(sizeof(t_zsort) * (num + 1));
	i = 0;
	num = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			zsort[num].i = i;
			zsort[num].j = j;
			zsort[num++].z = map[i][j].z;
			j++;
		}
		i++;
	}
	qsort(zsort, num, sizeof(t_zsort), compare);
	i = 0;
	while (i < num)
	{
		if (zsort[i].j < column - 1)
			draw_line(map[zsort[i].i][zsort[i].j], map[zsort[i].i][zsort[i].j + 1], data);
		if (zsort[i].i < row - 1)
			draw_line(map[zsort[i].i][zsort[i].j], map[zsort[i].i + 1][zsort[i].j], data);
		i++;
	}
	free(zsort);
}
