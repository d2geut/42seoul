/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 09:39:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/07 15:18:45 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	key_press(int keycode)
{
	if (keycode == KEY_ESC)
		exit(0);
	return (0);
}

static int	key_exit(void)
{
	exit(0);
}

void	window_map(t_map **map, const int row, const int column)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_MAX_X, WINDOW_MAX_Y, "fdf");
	if (!mlx_win)
		fdf_error(5);
	img.img = mlx_new_image(mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	if (!img.img)
		fdf_error(1);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, \
	&img.line_length, &img.endian);
	pixel_put_image(map, row, column, &img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_hook(mlx_win, EVENT_KEY_PRESS, 0, key_press, &img);
	mlx_hook(mlx_win, EVENT_KEY_EXIT, 0, key_exit, &img);
	mlx_loop(mlx);
}
