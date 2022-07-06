/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ung <ung@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 16:48:07 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/09 10:08:54 by ung              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_make_map(int fd, int height, int line, char **map)
{
	char	buff;
	int		i;
	int		j;

	buff = 0;
	i = 0;
	while (buff != '\n')
		read(fd, &buff, 1);
	while (i < height)
	{
		j = 1;
		map[i] = (char *)malloc(sizeof(char) * (line + 1));
		read(fd, &buff, 1);
		map[i][0] = buff;
		while (buff != '\n')
		{
			read(fd, &buff, 1);
			map[i][j] = buff;
			j++;
		}
		map[i][j] = 0;
		i++;
	}
}
