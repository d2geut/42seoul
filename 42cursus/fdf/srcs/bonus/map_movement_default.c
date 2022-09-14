/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_movement_default.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:06:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/14 16:46:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	isometric_map(double *x, double *y, double *z)
{
	double	theta;
	double	phi;

	theta = M_PI / 4;
	phi = atan(1 / sqrt(2));
	rotate_z(x, y, z, theta);
	rotate_x(x, y, z, phi);
}

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

static void	translate_default(t_map **map, const int row, const int column)
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

static void	scale_default(t_map **map, const int row, const int column, \
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

void	movement_map_default(t_map **map, const int row, const int column)
{
	int		i;
	int		j;
	double	max_x;
	double	max_y;

	translate_default(map, row, column);
	i = 0;
	max_x = 0;
	max_y = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			isometric_map(&(map[i][j].x), &(map[i][j].y), &(map[i][j].z));
			if (max_x < fabs(map[i][j].x))
				max_x = fabs(map[i][j].x);
			if (max_y < fabs(map[i][j].y))
				max_y = fabs(map[i][j].y);
			j++;
		}
		i++;
	}
	scale_default(map, row, column, margin_scale(max_x, max_y));
}

void	conic_map(double *x, double *y, double *z, int row)
{
	double	absx;
	double	absy;
	double	vv;
	double	kk;

	absx = fabs(*x);
	vv = (absx * absx) * 0.001;
	absy = fabs(*y);
	kk = (absy * absy) * 0.001;
	*x = *x * (1 + *y * 0.1 / ((double)row / 2));
	*z -= vv + kk;
	rotate_x(x, y, z, M_PI_4);
}

void	conic_default(t_map **map, const int row, const int column)
{
	int	i;
	int	j;
	double	max_x;
	double	max_y;
	
	translate_default(map, row, column);
	i = 0;
	max_x = 0;
	max_y = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			conic_map(&(map[i][j].x), &(map[i][j].y), &(map[i][j].z), row);
			if (max_x < fabs(map[i][j].x))
				max_x = fabs(map[i][j].x);
			if (max_y < fabs(map[i][j].y))
				max_y = fabs(map[i][j].y);
			j++;
		}
		i++;
	}
	scale_default(map, row, column, margin_scale(max_x, max_y));
}
