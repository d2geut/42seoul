/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometric_conic_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:06:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	isometric_map(double *x, double *y, double *z)
{
	double	theta;
	double	phi;

	theta = M_PI / 4;
	phi = atan(1 / sqrt(2));
	rotate_z(x, y, z, theta);
	rotate_x(x, y, z, phi);
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

static void	conic_map(double *x, double *y, double *z, int row)
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
