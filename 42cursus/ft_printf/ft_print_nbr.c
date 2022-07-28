/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:58:57 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 10:04:08 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len(int n)
{
	if (!n)
		return (0);
	return (1 + str_len(n / 10));
}

static void	in_arr(int buff, int fd, int n, char *arr)
{
	int	minus;

	minus = 1;
	if (n < 0)
	{
		write(fd, "-", 1);
		minus = -1;
	}
	while (0 < buff--)
	{
		arr[buff] = minus * (n % 10) + '0';
		n = n / 10;
	}
}

static int	pf_putnbr_fd(int n, int fd)
{
	char	arr[11];
	int		buff;
	int		minus;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	buff = str_len(n);
	minus = 1;
	in_arr(buff, fd, n, arr);
	write(fd, arr, buff);
	if (n < 0)
		return (buff + 1);
	return (buff);
}

int	print_nbr(va_list ap)
{
	int	arg;

	arg = va_arg(ap, int);
	return (pf_putnbr_fd(arg, 1));
}
