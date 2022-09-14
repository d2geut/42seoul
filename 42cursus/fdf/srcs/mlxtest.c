#include <mlx.h>
#include <stdio.h>

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
	int		trans;
	int		rotate;
}	t_vars;

int	key_press(int keycode, t_vars *vars)
{
	if (keycode == 257 && !vars->trans)
	{
		vars->rotate = 1;
	}
	printf("%d\n", keycode);
	return (0);
}

int	key_release(int keycode, t_vars *vars)
{
	if (keycode == 257)
	{
		vars->rotate = 0;
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (!vars->rotate && button == 3)
		vars->trans = 1;
	return (0);
}

int	mouse_release(int button, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (button == 3)
		vars->trans = 0;
	return (0);
}

int	mouse_hook(int x, int y, t_vars *vars)
{
	if (vars->trans)
	{
		printf("translate : ");
		mlx_mouse_get_pos(vars->win, &x, &y);
		printf("%d %d\n", x, y);
	}
	else if (vars->rotate)
	{
		printf("rotate : ");
		mlx_mouse_get_pos(vars->win, &x, &y);
		printf("%d %d\n", x, y);
	}
	return (0);
}

int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1600, 1200, "Hello World!");
	vars.trans = 0;
	vars.rotate = 0;
	mlx_hook(vars.win, 2, 0, key_press, &vars);
	mlx_hook(vars.win, 3, 0, key_release, &vars);
	mlx_hook(vars.win, 4, 0, mouse_press, &vars);
	mlx_hook(vars.win, 5, 0, mouse_release, &vars);
	mlx_hook(vars.win, 6, 0, mouse_hook, &vars);
	mlx_loop(vars.mlx);
}