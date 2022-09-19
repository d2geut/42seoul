/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:36:19 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:06 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

void	draw_line(t_map start, t_map end, t_data *data)
{
	t_deri	deri;

	if (clipping(&start, &end))
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
