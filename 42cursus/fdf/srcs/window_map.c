/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:39:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 14:11:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_image(data->mlx, data->win);
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}
	return (0);
}

static int	key_exit(t_data *data)
{
	(void)data;
	exit(0);
}

void	window_map(t_map **map, const int row, const int column)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_MAX_X, WINDOW_MAX_Y, \
	"fdf hanryu");
	data.img = mlx_new_image(data.mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (!data.img)
		fdf_error(1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);
	pixel_put_image(map, row, column, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, EVENT_KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, EVENT_KEY_EXIT, 0, key_exit, &data);
	mlx_loop(data.mlx);
}
