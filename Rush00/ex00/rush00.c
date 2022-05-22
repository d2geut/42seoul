/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:16:12 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/21 14:43:56 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char a);

void	print_line(char start, char mid, char last, char cnt)
{
	ft_putchar(start);
	while (--cnt > 1)
		ft_putchar(mid);
	if (cnt)
		ft_putchar(last);
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (y > 0 && x > 0)
	{
		while (i < y)
		{
			if (i == 0)
				print_line('A', 'B', 'C', x);
			else if (i == y - 1)
				print_line('C', 'B', 'A', x);
			else
				print_line('B', ' ', 'B', x);
			write(1, "\n", 1);
			i++;
		}
	}
}
