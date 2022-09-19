/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put_image_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 08:52:48 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	compare(const void *a, const void *b)
{
	t_zsort	*pa;
	t_zsort	*pb;

	pa = (t_zsort *)a;
	pb = (t_zsort *)b;
	if (pa->z > pb->z)
		return (1);
	else if (pa->z < pb->z)
		return (-1);
	else
		return (0);
}

static void	sort_by_z(t_zsort *zsort, t_map **map, const int row, \
const int column)
{
	int	i;
	int	j;
	int	num;

	i = 0;
	num = 0;
	while (i < row)
	{
		j = 0;
		while (j < column)
		{
			zsort[num].i = i;
			zsort[num].j = j;
			zsort[num].z = map[i][j].z;
			num++;
			j++;
		}
		i++;
	}
	qsort(zsort, num, sizeof(t_zsort), compare);
}

void	pixel_put_image(t_map **map, const int row, const int column, \
t_data *data)
{
	int		i;
	int		num;
	t_zsort	*zsort;

	num = row * column;
	zsort = (t_zsort *)malloc(sizeof(t_zsort) * (num + 1));
	sort_by_z(zsort, map, row, column);
	i = 0;
	while (i < num)
	{
		if (zsort[i].j < column - 1)
			draw_line(map[zsort[i].i][zsort[i].j], \
			map[zsort[i].i][zsort[i].j + 1], data);
		if (zsort[i].i < row - 1)
			draw_line(map[zsort[i].i][zsort[i].j], \
			map[zsort[i].i + 1][zsort[i].j], data);
		i++;
	}
	free(zsort);
}
