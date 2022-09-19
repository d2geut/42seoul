/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clipping_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:56:18 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	compute_code(double x, double y)
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

static void	clipping_xy(t_map *start, t_map *end, int c, double *xy)
{
	if (c == WINDOW_MAX_Y || c == -WINDOW_MAX_Y)
	{
		xy[0] = start->x + (end->x - start->x) * (c / 2 - start->y) / \
		(end->y - start->y);
		xy[1] = c / 2;
	}
	else if (c == WINDOW_MAX_X || c == -WINDOW_MAX_X)
	{
		xy[1] = start->y + (end->y - start->y) * (c / 2 - start->x) / \
		(end->x - start->x);
		xy[0] = c / 2;
	}
}

static void	update_code(t_map *data, int *c, double *xy)
{
	data->x = xy[0];
	data->y = xy[1];
	*c = compute_code(data->x, data->y);
}

static void	clipping2(t_map *start, t_map *end, int *c1, int *c2)
{
	int		code_out;
	double	xy[2];

	if ((*c1) != 0)
		code_out = *c1;
	else
		code_out = *c2;
	if (code_out & 8)
		clipping_xy(start, end, WINDOW_MAX_Y, xy);
	else if (code_out & 4)
		clipping_xy(start, end, -WINDOW_MAX_Y, xy);
	else if (code_out & 2)
		clipping_xy(start, end, WINDOW_MAX_X, xy);
	else if (code_out & 1)
		clipping_xy(start, end, -WINDOW_MAX_X, xy);
	if (code_out == *c1)
		update_code(start, c1, xy);
	else
		update_code(end, c2, xy);
}

int	clipping(t_map *start, t_map *end)
{
	int		code1;
	int		code2;

	code1 = compute_code(start->x, start->y);
	code2 = compute_code(end->x, end->y);
	while (1)
	{
		if ((code1 == 0) && (code2 == 0))
			break ;
		else if (code1 & code2)
			return (1);
		else
			clipping2(start, end, &code1, &code2);
	}
	return (0);
}
