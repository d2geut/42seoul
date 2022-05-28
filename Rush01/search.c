/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 09:40:17 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/28 14:57:16 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	verification(int (*arr)[4], int *input);

int	horizontal(int (*arr)[4], int i, int j, int n)
{
	while (--j >= 0)
	{
		if (arr[i][j] == n)
			return (0);
	}
	return (1);
}

int	vertical(int (*arr)[4], int i, int j, int n)
{
	while (--i >= 0)
	{
		if (arr[i][j] == n)
			return (0);
	}
	return (1);
}

void	backtracking(int (*arr)[4], int i, int j, int *input)
{
	int	n;

	n = 1;
	while (n < 5)
	{
		if (horizontal(arr, i, j, n) && vertical(arr, i, j, n))
		{
			arr[i][j] = n;
			if (j < 3)
				backtracking(arr, i, j + 1, input);
			else if (i < 3)
				backtracking(arr, i + 1, 0, input);
			else
				verification(arr, input);
			arr[i][j] = 0;
		}
		n++;
	}
}

void	make_array(int *input)
{
	int	arr[4][4];
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			arr[i][j] = 0;
			j++;
		}
		i++;
	}
	backtracking(arr, 0, 0, input);
	if (input[16] == -1)
		write(2, "Error\n", 6);
}
