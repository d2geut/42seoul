/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   into_field.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:04:34 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/04 19:54:33 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	dynamic(t_field **field, int height);
void	find_max(t_field **field, int height, int i);
void	print_result(t_field **field, int height);
void	min(int n1, int n2, int n3);

void	into_field(int line, int height, char **arr, t_charset cs)
{
	t_field	**field;
	int		i;
	int		j;

	field = (t_field **)malloc(sizeof(t_field *) * (height + 1));
	i = -1;
	while (arr[++i])
	{
		field[i] = (t_field *)malloc(sizeof(t_field) * (line + 1));
		j = -1;
		while (arr[i][++j])
		{
			field[i][j].element = arr[i][j];
			if (arr[i][j] == cs.empty)
				field[i][j].dp = 1;
			else
				field[i][j].dp = 0;
		}
		field[i][j].element = '\0';
		field[i][j].dp = 0;
	}
	dynamic(field, height);
	find_max(field, height, cs, -1);
	print_result(field, height);
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
				field[i][j].dp = min(field[i - 1][j].dp, field[i][j - 1].dp, \
						field[i - 1][j - 1].dp) + 1;
			j++;
		}
		i++;
	}
}

void	find_max(t_field **field, int height, t_charset cs, int i)
{
	int	max[3];
	int	j;

	max[2] = 0;
	while (++i < height)
	{
		j = -1;
		while (field[i][++j].element)
		{
			if (max[2] < field[i][j].dp)
			{
				max[0] = i;
				max[1] = j;
				max[2] = field[i][j].dp;
			}
		}
	}
	i = max[0] - max[2];
	while (++i <= max[0])
	{
		j = max[1] - max[2];
		while (++j <= max[1])
			field[i][j].element = cs.fill;
	}
}

void	print_result(t_field **field, int height)
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
		write(1, "\n", 1);
		i++;
	}
}
