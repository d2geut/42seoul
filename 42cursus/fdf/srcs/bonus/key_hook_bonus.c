/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:13:19 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	else if (keycode == KEY_H)
		set_default(data, 0);
	else if (keycode == KEY_C)
		set_default(data, 1);
	else if (keycode == KEY_SHIFT && !data->trans)
		data->rotate = 1;
	return (0);
}

int	key_exit(t_data *data)
{
	(void)data;
	exit(0);
}

int	key_release(int keycode, t_data *data)
{
	if (keycode == KEY_SHIFT)
		data->rotate = 0;
	return (0);
}
