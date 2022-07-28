/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 14:44:47 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 09:54:40 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(unsigned int n)
{
	if (!n)
		return (0);
	return (1 + str_len(n / 10));
}

static int	ft_putunbr_fd(unsigned int n, int fd)
{
	char	arr[11];
	int		buff;
	int		buff_cpy;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	buff = str_len(n);
	buff_cpy = buff;
	while (0 < buff--)
	{
		arr[buff] = (n % 10) + '0';
		n = n / 10;
	}
	write(fd, arr, buff_cpy);
	return (buff_cpy);
}

int	print_unbr(va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	return (ft_putunbr_fd(arg, 1));
}
