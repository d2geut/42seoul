/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:39:39 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 20:59:07 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

void	ft_int_to_char(int nb)
{
	char	str[10];
	int		n;
	int		i;

	i = 0;
	n = nb;
	while (n > 0)
	{
		str[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	while (i > 0)
	{
		write(1, &str[i - 1], 1);
		i--;
	}
}

void	ft_putnbr(int nb)
{
	int	n;

	n = nb;
	if (n > 0)
		ft_int_to_char(n);
	else if (n == 0)
		write(1, "0", 1);
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		n = -n;
		write(1, "-", 1);
		ft_int_to_char(n);
	}
}
