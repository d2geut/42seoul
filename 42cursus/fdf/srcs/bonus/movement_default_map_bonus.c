/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_default_map_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:49:34 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:47 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	index_range(t_map **map, const int row, const int column)
{
	int	max;
	int	min;
	int	i;
	int	j;

	i = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			if (map[i][j].index > max)
				max = map[i][j].index;
			if (map[i][j].index < min)
				min = map[i][j].index;
			j++;
		}
		i++;
	}
	return (max + min);
}

void	translate_default(t_map **map, const int row, const int column)
{
	int	i;
	int	j;
	int	range;

	i = 0;
	range = index_range(map, row, column);
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			map[i][j].x -= (double)(column - 1) / 2;
			map[i][j].y -= (double)(row - 1) / 2;
			map[i][j].z -= (double)range / 2;
			j++;
		}
		i++;
	}
}

void	scale_default(t_map **map, const int row, const int column, \
double scale)
{
	int	i;
	int	j;

	i = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			map[i][j].x *= scale;
			map[i][j].y *= scale;
			map[i][j].z *= scale;
			j++;
		}
		i++;
	}
}

double	margin_scale(double max_x, double max_y)
{
	double	scale_x;
	double	scale_y;

	scale_x = (WINDOW_MARGIN_X / 2) / max_x;
	scale_y = (WINDOW_MARGIN_Y / 2) / max_y;
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}
