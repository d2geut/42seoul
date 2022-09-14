/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:38:06 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/07 11:08:46 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
	system("leaks fdf");
	return (0);
}
