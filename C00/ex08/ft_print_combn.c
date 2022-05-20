/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 23:14:02 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/21 00:42:40 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int n, int i, char *c)
{
	c[i] = c[i - 1] + 1;
	while (c[i] <= ':' - n)
	{
		if (n == 1)
		{
			write(1, c, n + i);
			if (!(c[0] + i == '9'))
			{
				write(1, ", ", 2);
			}
		}
		else
		{
			print(n - 1, i + 1, c);
		}
		c[i]++;
	}
}

void	ft_print_combn(int n)
{
	int		i;
	char	c[9];

	c[0] = '0';
	i = 0;
	while (c[0] <= ':' - n)
	{
		print(n - 1, i + 1, c);
		c[0]++;
	}
}
