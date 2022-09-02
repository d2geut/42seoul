/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:38:06 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/01 14:15:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	before_parsing(char *filename, int *row, int *column)
{
	int	fd;
	int	flag;

	flag = 0;
	if (is_fdf(filename))
		exit (1);
	fd = open(filename, O_RDONLY);
	if (fd >= 0)
	{
		if (file_check(fd, row, column))
			flag = 1;
		else
			printf("row = %d, column = %d\n", *row, *column);
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
		{
			drawing(argv[1], row, column);
			write(2, "Correct.\n", 9);
		}
	}
	system("leaks fdf");
	return (0);
}
