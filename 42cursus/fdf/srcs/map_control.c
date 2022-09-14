/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:59:24 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/07 12:37:28 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_default(char *filename, const int row, const int column)
{
	t_map	**map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		map = save_map_data(fd, row, column);
		if (map)
		{
			movement_map_default(map, row, column);
			window_map(map, row, column);
		}
		free_map(&map);
		close(fd);
	}
	else
		perror(filename);
}
