/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:50:36 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 10:16:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	conv_operation(va_list ap, char conv)
{
	int	sum;

	if (conv == 'c')
		sum = print_char(ap);
	else if (conv == 's')
		sum = print_str(ap);
	else if (conv == 'd' || conv == 'i')
		sum = print_nbr(ap);
	else if (conv == 'p')
		sum = print_memory(ap);
	else if (conv == 'u')
		sum = print_unbr(ap);
	else if (conv == 'x')
		sum = print_hexa(ap, 0);
	else if (conv == 'X')
		sum = print_hexa(ap, 1);
	else if (conv == '%')
	{
		write(1, "%%", 1);
		sum = 1;
	}
	else
		return (-1);
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		sum;
	int		conv_sum;

	va_start(ap, format);
	i = -1;
	sum = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			conv_sum = conv_operation(ap, format[++i]);
			if (conv_sum == -1)
				return (-1);
			sum += conv_sum;
		}
		else
		{
			write(1, &format[i], 1);
			sum++;
		}
	}
	va_end(ap);
	return (sum);
}
