/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 16:40:59 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/02 13:20:27 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <limits.h>
# define WINDOW_MAX_X 2000
# define WINDOW_MAX_Y 1000
# define WINDOW_MARGIN_X 1600
# define WINDOW_MARGIN_Y 800

typedef struct s_map
{
	int		index;
	double	x;
	double	y;
	double	z;
	int		color;
}	t_map;

int		is_fdf(char *str);
char	*get_next_line(int fd);
int		file_check(int fd, int *row, int *column);
void	drawing(char *filename, const int row, const int column);
t_map	**save_map_data(int fd, const int row, const int column);
int		ft_getnbr(char *str);
void	ft_free(void **ptr);
void	ft_2darray_free(char ***arr);
void	free_map(t_map ***map);
void	translate_map(t_map **map, const int row, const int column);
void	rotate_x(double *x, double *y, double *z, double angle);
void	rotate_y(double *x, double *y, double *z, double angle);
void	rotate_z(double *x, double *y, double *z, double angle);
double	margin_scale(int max_x, int max_y);

void	mlxtest(t_map **map, const int row, const int column);

#endif