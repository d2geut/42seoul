/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:34:06 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 22:08:53 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	main(int ac, char **av)
{
	int			fd;
	int			height;
	int			line;
	char		**map;
	t_charset	mapchar;

	fd = open(av[1], O_RDONLY);
	height = ft_check_height(fd, &mapchar);
	line = ft_check_line(fd, mapchar, height, -1);
	if (line == ERROR || height == ERROR || ac != 2)
	{
		ft_putstr(ERR_MSG);
		close(fd);
		return (ERROR);
	}
	fd = open(av[1], O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (height + 1));
	ft_make_map(fd, map, height, line);
	into_field(line, height, map, mapchar);
	close(fd);
	return (0);
}
