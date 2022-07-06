/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:37:51 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/09 12:10:44 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	ft_check_char(char *str, t_charset *mapchar, int size)
{
	int	n;
	int	cnt;

	cnt = size - 4;
	if ((str[cnt] <= 32 || str[cnt] == 127)
		|| (str[cnt + 1] <= 32 || str[cnt + 1] == 127)
		|| (str[cnt + 2] <= 32 || str[cnt + 2] == 127) || str[cnt + 3] != '\n')
		return (ERROR);
	mapchar -> empty = str[cnt];
	mapchar -> obstacle = str[cnt + 1];
	mapchar -> fill = str[cnt + 2];
	while (cnt < size)
	{
		str[cnt] = 0;
		cnt++;
	}
	n = ft_atoi(str);
	return (n);
}

int	ft_check_height(int fd, t_charset *mapchar)
{
	int		size;
	int		check;
	char	first_line[20];
	char	buff;

	buff = 0;
	size = 0;
	check = 1;
	while (buff != '\n' && check > 0 && size < 19)
	{
		check = read(fd, &buff, 1);
		first_line[size] = buff;
		size++;
	}
	first_line[size] = 0;
	if (size > 15 || size < 5)
		return (ERROR);
	check = ft_check_char(first_line, mapchar, size);
	if (check <= 0)
		return (ERROR);
	else
		return (check);
}
