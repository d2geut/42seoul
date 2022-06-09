/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:04:34 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/09 12:09:54 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	dynamic(t_field **field, int height);
void	find_max(t_field **field, int height, t_charset cs, int i);
void	print_result(t_field **field, int height, char **map);

void	into_field(int height, int line, char **map, t_charset cs)
{
	t_field	**field;
	int		i;
	int		j;

	field = (t_field **)malloc(sizeof(t_field *) * (height + 1));
	i = -1;
	while (++i < height)
	{
		field[i] = (t_field *)malloc(sizeof(t_field) * (line + 1));
		j = -1;
		while (++j < line)
		{
			field[i][j].element = map[i][j];
			if (map[i][j] == cs.empty)
				field[i][j].dp = 1;
			else
				field[i][j].dp = 0;
		}
		field[i][j].element = '\0';
		field[i][j].dp = 0;
	}
	field[i] = 0;
	dynamic(field, height);
	find_max(field, height, cs, -1);
	print_result(field, height, map);
}

void	dynamic(t_field **field, int height)
{
	int	i;
	int	j;

	i = 1;
	while (i < height)
	{
		j = 1;
		while (field[i][j].element)
		{
			if (field[i][j].dp)
				field[i][j].dp = min(field[i - 1][j].dp,
						field[i][j - 1].dp, field[i - 1][j - 1].dp) + 1;
			j++;
		}
		i++;
	}
}

void	find_max(t_field **field, int height, t_charset cs, int i)
{
	t_maxfield	find;
	int			j;

	find.dp_max = 0;
	while (++i < height)
	{
		j = -1;
		while (field[i][++j].element)
		{
			if (find.dp_max < field[i][j].dp)
			{
				find.i_max = i;
				find.j_max = j;
				find.dp_max = field[i][j].dp;
			}
		}
	}
	i = find.i_max - find.dp_max;
	while (++i <= find.i_max)
	{
		j = find.j_max - find.dp_max;
		while (++j <= find.j_max)
			field[i][j].element = cs.fill;
	}
}

void	print_result(t_field **field, int height, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (field[i][j].element)
		{
			write(1, &field[i][j].element, 1);
			j++;
		}
		free(map[i]);
		free(field[i]);
		i++;
	}
	free(map);
	free(field);
}
