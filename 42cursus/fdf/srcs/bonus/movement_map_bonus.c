/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:41:08 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	set_default(t_data *data, int flag)
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
	if (!flag)
		movement_map_default(data->link, data->row, data->column);
	else
		conic_default(data->link, data->row, data->column);
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
			rotate_y(&data->link[i][j].x, &data->link[i][j].y, \
			&data->link[i][j].z, -2 * M_PI * dx / WINDOW_MAX_X);
			rotate_x(&data->link[i][j].x, &data->link[i][j].y, \
			&data->link[i][j].z, -2 * M_PI * dy / WINDOW_MAX_Y);
			j++;
		}
		i++;
	}
}
