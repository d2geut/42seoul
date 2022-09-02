/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:21:52 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/01 12:56:12 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_hexa_color(char *str, int *num)
{
	if (str[(*num)++] != '0')
		return (1);
	if (str[(*num)++] != 'x')
		return (1);
	while (str[*num])
	{
		if (!(('0' <= str[*num] && str[*num] <= '9') \
		|| ('A' <= str[*num] && str[*num] <= 'F') \
		|| ('a' <= str[*num] && str[*num] <= 'f')))
			return (1);
		(*num)++;
	}
	if (str[*num] != '\0' || *num > 8)
		return (1);
	return (0);
}

static char	*passnbr(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (!('0' <= str[i + 1] && str[i + 1] <= '9'))
			return (&str[i]);
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
		i++;
	if (i == 0 || str[i] != ',')
		return (&str[i]);
	i++;
	if (is_hexa_color(&str[i], &num))
		return (str);
	return (&str[i + num]);
}

static int	line_check(char *line, int *column)
{
	int		i;
	int		flag;
	char	**arr;

	flag = 0;
	arr = ft_split(line, ' ');
	if (!arr)
	{
		write(2, "malloc error.\n", 14);
		return (1);
	}
	if (!arr[0])
		flag = 1;
	i = 0;
	while (arr[i])
	{
		if (passnbr(arr[i])[0])
			flag = 1;
		i++;
	}
	*column = i;
	ft_2darray_free(&arr);
	if (flag)
	{
		write(2, "Include wrong format word.\n", 27);
		return (1);
	}
	return (0);
}

int	file_check(int fd, int *row, int *column)
{
	char	*line;
	int		column_backup;
	int		flag;

	while (1)
	{
		flag = 0;
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line_check(line, column))
			flag = 1;
		else if ((*row)++ != 0 && *column != column_backup)
		{
			write(2, "Include wrong line length.\n", 27);
			flag = 1;
		}
		ft_free((void **)&line);
		if (flag)
			return (1);
		column_backup = *column;
	}
	if (!(*row))
		return (1);
	return (0);
}
