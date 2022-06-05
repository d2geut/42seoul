/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 19:40:55 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 22:06:46 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	ft_check_line(int fd, t_charset mapchar, int height, int i)
{
	ssize_t	check;
	char	buff;
	int		size[2];

	size[0] = 1;
	buff = 0;
	while (++i < height)
	{
		size[1] = size[0];
		size[0] = 1;
		read(fd, &buff, 1);
		while (buff != '\n' && check > 0)
		{
			if (buff != mapchar.empty && buff != mapchar.obstacle)
				return (ERROR);
			check = read(fd, &buff, 1);
			size[0]++;
		}
		if ((i != 0 && size[0] != size[1]) || (i == height - 1 && buff != '\n'))
			return (ERROR);
	}
	check = read(fd, &buff, 1);
	if (check > 0)
		return (ERROR);
	return (size[0]);
}
