/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:50:06 by hanryu            #+#    #+#             */
/*   Updated: 2023/03/26 05:19:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec.h"

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((0 <= x && x < WINDOW_X) && (0 <= y && y < WINDOW_Y))
	{
		dst = data->addr + (y * data->line_length + x * \
		(data->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	main()
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_vec3	a_color;

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&a_color, 0, sizeof(t_vec3));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "test");
	data.img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
	if (!data.img)
		return (1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);

	int	i;
	int	j;
	i = 0;
	while (i < WINDOW_X)
	{
		j = 0;
		while (j < WINDOW_Y)
		{
			a_color.x = (double)i / WINDOW_X;
			a_color.y = (double)j / WINDOW_Y;
			a_color.z = 0.25;
			my_mlx_pixel_put(&data, i, j, create_trgb(0, 256 * a_color.x, 256 * a_color.y, 256 * a_color.z));
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
