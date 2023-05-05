/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 13:50:06 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 18:14:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "vec.h"
#include "camera.h"
#include "ray.h"
#include "object.h"
#include <stdio.h>

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
	t_camera	camera;
	t_sphere	sp;

	camera = camera_set();
	sp = sphere_init(vec3(0, 0, 5), 2);

	ft_memset(&data, 0, sizeof(t_data));
	ft_memset(&a_color, 0, sizeof(t_vec3));
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, camera.image_x, camera.image_y, "test");
	data.img = mlx_new_image(mlx, camera.image_x, camera.image_y);
	if (!data.img)
		return (1);
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, \
	&data.line_length, &data.endian);

	double	x;
	double	y;
	t_ray	ray;
	int	i;
	int	j;
	j = 0;
	while (j < camera.image_y)
	{
		i = 0;
		while (i < camera.image_x)
		{
			x = (double)i / (camera.image_x - 1);
			y = (double)(camera.image_y - j - 1) / (camera.image_y - 1);
			ray = ray_camera(&camera, x, y);
			a_color = ray_color(&ray, sp);
			my_mlx_pixel_put(&data, i, j, create_trgb(0, 255.999 * a_color.x, 255.999 * a_color.y, 255.999 * a_color.z));
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(mlx, mlx_win, data.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
