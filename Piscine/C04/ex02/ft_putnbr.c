/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:43:06 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/24 19:49:44 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_num(char *arr, int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb = -nb;
	}
	while (nb)
	{
		arr[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	while (i)
	{
		write(1, &arr[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	char	arr[11];

	if (nb == 0)
		write(1, "0", 1);
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else
		print_num(arr, nb);
}
