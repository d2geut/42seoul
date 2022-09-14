/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:56:18 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/14 14:35:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	compute_code(double x, double y)
{
	int	code;

	code = 0;
	if (x < -WINDOW_MAX_X / 2)
		code |= 1;
	else if (x > WINDOW_MAX_X / 2)
		code |= 2;
	if (y < -WINDOW_MAX_Y / 2)
		code |= 4;
	else if (y > WINDOW_MAX_Y / 2)
		code |= 8;
	return (code);
}

int	clipping(double *x1, double *y1, double *x2, double *y2)
{
	int		code1;
	int		code2;
	int		code_out;
	double	x;
	double	y;

	code1 = compute_code(*x1, *y1);
	code2 = compute_code(*x2, *y2);
	while (1)
	{
		if ((code1 == 0) && (code2 == 0))
			break ;
		else if (code1 & code2)
			return (1);
		else
		{
			if (code1 != 0)
				code_out = code1;
			else
				code_out = code2;
			if (code_out & 8)
			{
				x = *x1 + (*x2 - *x1) * (WINDOW_MAX_Y / 2 - *y1) / (*y2 - *y1);
				y = WINDOW_MAX_Y / 2;
			}
			else if (code_out & 4)
			{
				x = *x1 + (*x2 - *x1) * (-WINDOW_MAX_Y / 2 - *y1) / (*y2 - *y1);
				y = -WINDOW_MAX_Y / 2;
			}
			else if (code_out & 2)
			{
				y = *y1 + (*y2 - *y1) * (WINDOW_MAX_X / 2 - *x1) / (*x2 - *x1);
				x = WINDOW_MAX_X / 2;
			}
			else if (code_out & 1)
			{
				y = *y1 + (*y2 - *y1) * (-WINDOW_MAX_X / 2 - *x1) / (*x2 - *x1);
				x = -WINDOW_MAX_X / 2;
			}
			if (code_out == code1)
			{
				*x1 = x;
				*y1 = y;
				code1 = compute_code(*x1, *y1);
			}
			else
			{
				*x2 = x;
				*y2 = y;
				code2 = compute_code(*x2, *y2);
			}
		}
	}
	return (0);
}