/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:38:06 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:46:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	is_fdf(char *str)
{
	char	**arr;
	char	*word;
	int		i;

	arr = ft_split(str, '.');
	if (!arr)
		fdf_error(1);
	if (!arr[0])
		fdf_error(2);
	i = 0;
	word = arr[0];
	while (arr[++i])
		word = arr[i];
	if (ft_strncmp(word, "fdf", 4))
		fdf_error(2);
	ft_2darray_free(&arr);
}

static int	before_parsing(char *filename, int *row, int *column)
{
	int	fd;
	int	flag;

	flag = 0;
	is_fdf(filename);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		if (file_check(fd, row, column))
			flag = 1;
	}
	else
	{
		perror(filename);
		flag = 1;
	}
	close(fd);
	return (flag);
}

static void	map_default(char *filename, const int row, const int column)
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

int	main(int argc, char **argv)
{
	int	row;
	int	column;

	if (argc != 2)
		write(1, "Usage: ./fdf <filename>\n", 24);
	else
	{
		row = 0;
		column = 0;
		if (!before_parsing(argv[1], &row, &column))
			map_default(argv[1], row, column);
	}
	return (0);
}
