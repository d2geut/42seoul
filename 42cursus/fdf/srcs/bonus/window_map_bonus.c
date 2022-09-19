/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:39:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:41:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	main_loop(t_data *data)
{
	data->img = mlx_new_image(data->mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (!data->img)
		fdf_error(1);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel, \
	&data->line_length, &data->endian);
	pixel_put_image(data->link, data->row, data->column, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_destroy_image(data->mlx, data->img);
	return (0);
}

void	control_guide(void)
{
	write(1, "==== Fdf Control Guide ====\n", 28);
	write(1, "Move : Middle Click\n", 20);
	write(1, "Rotate : Shift + Middle Click\n", 30);
	write(1, "Zoom In/Out : Scroll\n", 21);
	write(1, "Isometric : H\n", 14);
	write(1, "Conic : C\n", 10);
	write(1, "===========================\n", 28);
}

void	window_map(t_map **map, const int row, const int column)
{
	t_data	data;

	data.link = map;
	data.row = row;
	data.column = column;
	data.trans = 0;
	data.rotate = 0;
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WINDOW_MAX_X, WINDOW_MAX_Y, \
	"fdf hanryu");
	control_guide();
	mlx_hook(data.win, EVENT_KEY_PRESS, 0, key_press, &data);
	mlx_hook(data.win, EVENT_KEY_RELEASE, 0, key_release, &data);
	mlx_hook(data.win, EVENT_KEY_EXIT, 0, key_exit, &data);
	mlx_hook(data.win, EVENT_MOUSE_PRESS, 0, mouse_press, &data);
	mlx_hook(data.win, EVENT_MOUSE_RELEASE, 0, mouse_release, &data);
	mlx_hook(data.win, EVENT_MOUSE_MOVE, 0, mouse_hook, &data);
	mlx_loop_hook(data.mlx, main_loop, &data);
	mlx_loop(data.mlx);
}
