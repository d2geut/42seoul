/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 09:50:36 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/11 12:39:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

static int	is_conversion(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || \
		c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		num_ps;
	int		arg;

	i = 0;
	num_ps = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			num_ps++;
			i++;
			if (!is_conversion(format[i]))
				return (-1);
		}
		i++;
	}
	va_start(ap, num_ps);
	i = 0;
	while (i < num_ps)
	{
		arg = va_arg(ap, int);
		i++;
	}
}
