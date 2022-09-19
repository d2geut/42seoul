/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:14:04 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == MOUSE_MIDDLE)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		data->x = x;
		data->y = y;
		data->trans = 1;
	}
	else if (button == MOUSE_SCROLL_UP)
		scale_map(data, 0);
	else if (button == MOUSE_SCROLL_DOWN)
		scale_map(data, 1);
	return (0);
}

int	mouse_release(int button, int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	if (button == MOUSE_MIDDLE)
		data->trans = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_data *data)
{
	if (data->rotate && data->trans)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		rotate_map(data, x - data->x, y - data->y);
		data->x = x;
		data->y = y;
	}
	else if (data->trans)
	{
		mlx_mouse_get_pos(data->win, &x, &y);
		translate_map(data, x - data->x, y - data->y);
		data->x = x;
		data->y = y;
	}
	return (0);
}
