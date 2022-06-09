/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:34:06 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/09 12:17:33 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_check_and_make(char *av, int height, int line, t_charset mapchar)
{
	int		first_fd;
	int		second_fd;
	char	**map;

	first_fd = open(av, O_RDONLY);
	if (first_fd < 0)
		return (ERROR);
	height = ft_check_height(first_fd, &mapchar);
	line = ft_check_line(first_fd, mapchar, height, -1);
	close(first_fd);
	if (line == ERROR || height == ERROR)
		return (ERROR);
	second_fd = open(av, O_RDONLY);
	map = (char **)malloc(sizeof(char *) * (height + 1));
	map[height] = 0;
	ft_make_map(second_fd, height, line, map);
	into_field(height, line, map, mapchar);
	close(second_fd);
	return (0);
}

void	ft_ac_is_1(int height, int line, t_charset mapchar)
{
	char	buff;
	int		read_check;
	int		map_check;
	int		fd;

	read_check = 1;
	buff = 0;
	fd = open("temp_map", O_RDWR | O_TRUNC);
	while (read_check)
	{
		read_check = read(0, &buff, 1);
		if (read_check)
			write(fd, &buff, 1);
	}
	close(fd);
	map_check = ft_check_and_make("temp_map", height, line, mapchar);
	if (map_check == ERROR)
		ft_putstr(ERR_MSG);
}

int	main(int ac, char **av)
{
	int			height;
	int			line;
	int			i;
	int			check;
	t_charset	mapchar;

	i = 1;
	height = 0;
	line = 0;
	mapchar.empty = 0;
	mapchar.fill = 0;
	mapchar.obstacle = 0;
	if (ac == 1)
		ft_ac_is_1(height, line, mapchar);
	while (i < ac)
	{
		check = ft_check_and_make(av[i], height, line, mapchar);
		if (check == ERROR)
			ft_putstr(ERR_MSG);
		if (i != ac - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}
