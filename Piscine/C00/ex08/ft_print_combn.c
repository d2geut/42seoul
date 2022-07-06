/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:48:48 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/22 15:49:21 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	array_output(int n, int i, char *arr)
{
	arr[i] = arr[i - 1] + 1;
	while (arr[i] <= ':' - n)
	{
		if (n == 1)
		{
			write(1, arr, n + i);
			if (!(arr[0] + i == '9'))
			{
				write(1, ", ", 2);
			}
		}
		else
			array_output(n - 1, i + 1, arr);
		arr[i]++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	arr[11];

	arr[0] = '0';
	i = 0;
	while (arr[0] <= ':' - n)
	{
		if (n == 1)
		{
			write(1, &arr[0], 1);
			if (arr[0] != '9')
				write(1, ", ", 2);
		}
		else
			array_output(n - 1, i + 1, arr);
		arr[0]++;
	}
}
