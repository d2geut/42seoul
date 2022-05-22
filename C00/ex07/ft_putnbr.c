/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 22:29:13 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/22 15:53:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(char *c, int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
		write(1, "-", 1);
	while (nb)
	{
		if (nb < 0)
			nb = -nb;
		c[i++] = nb % 10 + 48;
		nb = nb / 10;
	}
	while (i)
	{
		write(1, &c[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	c[11];

	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		print(c, nb);
}
