/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:58:57 by hanryu            #+#    #+#             */
/*   Updated: 2022/08/26 11:38:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr(unsigned long n, int depth, char *arr, const int base)
{
	if (n >= (unsigned int)base)
		depth = ft_putnbr(n / base, depth, arr, base);
	write(1, &arr[n % base], 1);
	return (depth + 1);
}

int	print_nbr(va_list ap)
{
	int				arg;
	unsigned int	arg_u;
	int				word;

	word = 0;
	arg = va_arg(ap, int);
	if (arg < 0)
	{
		arg_u = -1 * arg;
		write(1, "-", 1);
		word++;
	}
	else
		arg_u = arg;
	word += ft_putnbr(arg_u, 0, "0123456789", 10);
	return (word);
}

int	print_unbr(va_list ap)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	return (ft_putnbr(arg, 0, "0123456789", 10));
}

int	print_hexa(va_list ap, int flag)
{
	unsigned int	arg;

	arg = va_arg(ap, unsigned int);
	if (!flag)
		return (ft_putnbr(arg, 0, "0123456789abcdef", 16));
	else
		return (ft_putnbr(arg, 0, "0123456789ABCDEF", 16));
}

int	print_memory(va_list ap)
{
	void	*arg;

	arg = va_arg(ap, void *);
	write(1, "0x", 2);
	return (ft_putnbr((unsigned long)arg, 0, "0123456789abcdef", 16) + 2);
}
