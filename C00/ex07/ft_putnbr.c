/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:29:13 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/21 00:40:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *c, int i, int k)
{
	if (k < 0)
	{
		write(1, "-", 1);
	}
	while (i)
	{
		write(1, &c[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int		i;
	int		k;
	char	c[11];

	i = 1;
	k = nb;
	if (nb == 0)
	{
		write(1, "0", 1);
	}
	while (nb)
	{
		if (k > 0)
		{
			c[i - 1] = (nb % 10) + 48;
		}
		else
		{
			c[i - 1] = -(nb % 10) + 48;
		}
		nb = nb / 10;
		i++;
	}
	print(c, i, k);
}
