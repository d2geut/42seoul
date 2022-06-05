/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_height.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 14:37:51 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 21:26:13 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	ft_check_char(char *str, t_charset *mapchar)
{
	int	n;
	int	cnt;

	cnt = 0;
	n = ft_atoi(str);
	while (n > 0)
	{
		n /= 10;
		cnt++;
	}
	if ((str[cnt] <= 32 || str[cnt] == 127)
		|| (str[cnt + 1] <= 32 || str[cnt + 1] == 127)
		|| (str[cnt + 2] <= 32 || str[cnt + 2] == 127) || str[cnt + 3] != '\n')
		return (ERROR);
	mapchar -> empty = str[cnt];
	mapchar -> obstacle = str[cnt + 1];
	mapchar -> fill = str[cnt + 2];
	return (0);
}

int	ft_check_height(int fd, t_charset *mapchar)
{
	int		size;
	int		check;
	int		ret_num;
	char	first_line[20];
	char	buff;

	buff = 0;
	size = 0;
	while (buff != '\n')
	{
		read(fd, &buff, 1);
		first_line[size] = buff;
		size++;
	}
	first_line[size] = 0;
	ret_num = ft_atoi(first_line);
	if (ret_num <= 0)
		return (ERROR);
	check = ft_check_char(first_line, mapchar);
	if (check == ERROR)
		return (ERROR);
	else
		return (ret_num);
}
