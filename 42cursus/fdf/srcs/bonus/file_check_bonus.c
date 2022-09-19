/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:21:52 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:16 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

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

static void	line_check(char *line, int *column)
{
	int		i;
	char	**arr;

	arr = ft_split(line, ' ');
	if (!arr)
		fdf_error(2);
	if (!arr[0])
		fdf_error(3);
	i = -1;
	while (arr[++i])
		if (passnbr(arr[i])[0])
			fdf_error(3);
	*column = i;
	ft_2darray_free(&arr);
}

int	file_check(int fd, int *row, int *column)
{
	char	*line;
	int		column_backup;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_check(line, column);
		if ((*row)++ != 0 && *column != column_backup)
			fdf_error(4);
		ft_free((void **)&line);
		column_backup = *column;
	}
	if (!(*row))
		fdf_error(4);
	return (0);
}
