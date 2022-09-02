/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 11:18:00 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/02 13:05:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_x(double *x, double *y, double *z, double angle)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = prev_x;
	*y = cos(angle) * prev_y - sin(angle) * prev_z;
	*z = sin(angle) * prev_y + cos(angle) * prev_z;
}

void	rotate_y(double *x, double *y, double *z, double angle)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = cos(angle) * prev_x - sin(angle) * prev_z;
	*y = prev_y;
	*z = sin(angle) * prev_x + cos(angle) * prev_z;
}

void	rotate_z(double *x, double *y, double *z, double angle)
{
	double	prev_x;
	double	prev_y;
	double	prev_z;

	prev_x = *x;
	prev_y = *y;
	prev_z = *z;
	*x = cos(angle) * prev_x - sin(angle) * prev_y;
	*y = sin(angle) * prev_x + cos(angle) * prev_y;
	*z = prev_z;
}
