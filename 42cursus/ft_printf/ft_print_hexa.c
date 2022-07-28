/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 16:12:27 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 13:31:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_len_hexa(unsigned long n)
{
	if (!n)
		return (0);
	return (1 + str_len_hexa(n / 16));
}

static int	ft_puthexa(unsigned long n, int fd, char *hex)
{
	char	arr[20];
	int		buff;
	int		buff_cpy;

	if (n == 0)
	{
		write(fd, "0", 1);
		return (1);
	}
	buff = str_len_hexa(n);
	buff_cpy = buff;
	while (0 < buff--)
	{
		arr[buff] = hex[n % 16];
		n = n / 16;
	}
	write(fd, arr, buff_cpy);
	return (buff_cpy);
}

int	print_hexa(va_list ap, int flag)
{
	unsigned int	arg;
	char			*hex;

	arg = va_arg(ap, unsigned int);
	if (!flag)
	{
		hex = "0123456789abcdef";
		return (ft_puthexa(arg, 1, hex));
	}
	else
	{
		hex = "0123456789ABCDEF";
		return (ft_puthexa(arg, 1, hex));
	}
}

int	print_memory(va_list ap)
{
	void	*arg;
	char	*hex;

	arg = va_arg(ap, void *);
	hex = "0123456789abcdef";
	write(1, "0x", 2);
	return (ft_puthexa((unsigned long)arg, 1, hex) + 2);
}
