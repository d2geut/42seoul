/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_catcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 18:26:44 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/06 21:44:58 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cat.h"
#include <stdio.h>

void	print_error(int err, char *str)
{
	write(1, "cat: ", 5);
	ft_putstr(str);
	write(1, ": ", 2);
	ft_putstr(strerror(err));
	write(1, "\n", 1);
}

void	print_open(int fd)
{
	char	buff;
	ssize_t	size;

	while (1)
	{
		size = read(fd, &buff, 1);
		if (0 < size)
			write(1, &buff, 1);
		else
			break ;
	}
	close(fd);
}

void	print_noav(void)
{
	char	buff;
	ssize_t	size;

	while (1)
	{
		size = read(0, &buff, 1);
		printf("%c", buff);
		if (size == 0)
			break ;
	}
}

int	main(int argc, char **argv)
{
	int	fd;
	int	i;

	if (argc == 1)
	{
		print_noav();
	}
	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd <= 0)
			print_error(errno, argv[i]);
		else
			print_open(fd);
		i++;
	}
	return (0);
}
