#include <mlx.h>
#include "fdf.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	mlxtest(t_map **map, const int row, const int column)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_MAX_X, WINDOW_MAX_Y, "Hello World!");
	img.img = mlx_new_image(mlx, WINDOW_MAX_X, WINDOW_MAX_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	for (int i = 0; i < row; i++)
	{
		printf("--%d--\n", i);
		for (int j = 0; j < column; j++)
		{
			printf("%d : x = %f y = %f\n", j, map[i][j].x, map[i][j].y);
			my_mlx_pixel_put(&img, map[i][j].x + WINDOW_MAX_X/2, map[i][j].y + WINDOW_MAX_Y/2, map[i][j].color);
		}
		printf("\n");
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}