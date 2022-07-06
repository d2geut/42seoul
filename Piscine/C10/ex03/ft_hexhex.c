/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexhex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 20:02:59 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/07 20:54:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

void	hexdump(int *total_size, char str)
{
	char	buff;
	ssize_t	size;

	fd = open(str, O_RDONLY);
	while (1)
	{
		size = read(fd, &buff, 1);
		if (size <= 0)
			break ;
		(*total_size)++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	fd;
	int	total_size;

	i = 2;
	total_size = 0;
	while (i < argc)
	{
		hexdump(&total_size, argv[i]);
		i++;
	}
	return (0);
}
