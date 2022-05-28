/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 11:12:43 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/28 14:57:18 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	colup(int (*arr)[4], int *input)
{
	int	n;
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < 4)
	{
		num = 0;
		n = 0;
		j = -1;
		while (++j < 4)
		{
			if (n <= arr[j][i])
			{
				n = arr[j][i];
				num++;
			}
			if (n == 4)
				break ;
		}
		if (input[i] != num)
			return (0);
	}
	return (1);
}

int	coldown(int (*arr)[4], int *input)
{
	int	n;
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < 4)
	{
		num = 0;
		n = 0;
		j = 4;
		while (--j >= 0)
		{
			if (n <= arr[j][i])
			{
				n = arr[j][i];
				num++;
			}
			if (n == 4)
				break ;
		}
		if (input[i + 4] != num)
			return (0);
	}
	return (1);
}

int	rowleft(int (*arr)[4], int *input)
{
	int	n;
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < 4)
	{
		num = 0;
		n = 0;
		j = -1;
		while (++j < 4)
		{
			if (n <= arr[i][j])
			{
				n = arr[i][j];
				num++;
			}
			if (n == 4)
				break ;
		}
		if (input[i + 8] != num)
			return (0);
	}
	return (1);
}

int	rowright(int (*arr)[4], int *input)
{
	int	n;
	int	i;
	int	j;
	int	num;

	i = -1;
	while (++i < 4)
	{
		num = 0;
		n = 0;
		j = 4;
		while (--j >= 0)
		{
			if (n <= arr[i][j])
			{
				n = arr[i][j];
				num++;
			}
			if (n == 4)
				break ;
		}
		if (input[i + 12] != num)
			return (0);
	}
	return (1);
}

void	verification(int (*arr)[4], int *input)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	if (colup(arr, input) && coldown(arr, input) && rowleft(arr, input)
		&& rowright(arr, input) && input[16])
	{
		while (i < 4)
		{
			j = 0;
			while (j < 4)
			{
				c = arr[i][j] + '0';
				write(1, &c, 1);
				if (j < 3)
					write(1, " ", 1);
				j++;
			}
			i++;
			write(1, "\n", 1);
		}
		input[16] = 0;
	}
}
