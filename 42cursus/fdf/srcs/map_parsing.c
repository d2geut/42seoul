/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:26:13 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/07 10:16:53 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	getcolor(char *str)
{
	int	i;
	int	point;
	int	color;

	i = -1;
	point = 0;
	color = 0;
	while (str[++i])
		if (str[i] == ',')
			point = i;
	if (point)
	{
		while (str[++point + 2])
		{
			color *= 16;
			if ('0' <= str[point + 2] && str[point + 2] <= '9')
				color += str[point + 2] - '0';
			else if ('A' <= str[point + 2] && str[point + 2] <= 'F')
				color += 10 + str[point + 2] - 'A';
			else
				color += 10 + str[point + 2] - 'a';
		}
		return (color);
	}
	return (0xFFFFFF);
}

static void	read_file(int fd, t_map **map)
{
	int		i;
	int		j;
	char	*line;
	char	**arr;

	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		arr = ft_split(line, ' ');
		j = -1;
		while (arr[++j])
		{
			map[i][j].x = j;
			map[i][j].y = i;
			map[i][j].index = ft_getnbr(arr[j]);
			map[i][j].z = map[i][j].index;
			map[i][j].color = getcolor(arr[j]);
		}
		ft_2darray_free(&arr);
		ft_free((void **)&line);
		i++;
	}
}

t_map	**save_map_data(int fd, const int row, const int column)
{
	t_map	**map;
	int		i;

	map = (t_map **)malloc(sizeof(t_map *) * (row + 1));
	if (!map)
		return (NULL);
	map[row] = 0;
	i = 0;
	while (i < row)
	{
		map[i] = (t_map *)malloc(sizeof(t_map) * (column + 1));
		if (!map[i])
		{
			free_map(&map);
			return (NULL);
		}
		i++;
	}
	read_file(fd, map);
	return (map);
}
