/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 16:02:32 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/26 21:17:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	diagonal_up(int (*arr)[10], int n, int i, int tf)
{
	if (n < 10 && i >= 0)
	{
		arr[n][i] += tf;
		diagonal_up(arr, n + 1, i - 1, tf);
	}
}

void	diagonal_down(int (*arr)[10], int n, int i, int tf)
{
	if (n < 10 && i < 10)
	{
		arr[n][i] += tf;
		diagonal_down(arr, n + 1, i + 1, tf);
	}
}

void	horizontal(int (*arr)[10], int n, int i, int tf)
{
	if (n < 10)
	{
		arr[n][i] += tf;
		horizontal(arr, n + 1, i, tf);
	}
}

void	backtracking(int (*arr)[10], char *queen, int n, int *num)
{
	int	i;

	i = -1;
	while (++i < 10)
	{
		if (!arr[n][i])
		{
			queen[n] = i + '0';
			if (n == 9)
			{
				write(1, queen, 11);
				(*num)++;
			}
			else
			{
				diagonal_down(arr, n + 1, i + 1, 1);
				diagonal_up(arr, n + 1, i - 1, 1);
				horizontal(arr, n + 1, i, 1);
				backtracking(arr, queen, n + 1, num);
				diagonal_down(arr, n + 1, i + 1, -1);
				diagonal_up(arr, n + 1, i - 1, -1);
				horizontal(arr, n + 1, i, -1);
			}
		}
	}
}

int	ft_ten_queens_puzzle(void)
{
	int		arr[10][10];
	char	queen[11];
	int		i;
	int		j;
	int		num;

	queen[10] = '\n';
	num = 0;
	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	backtracking(arr, queen, 0, &num);
	return (num);
}
