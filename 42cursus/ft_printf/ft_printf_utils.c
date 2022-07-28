/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 13:58:20 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/18 10:10:28 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap)
{
	int	arg;

	arg = va_arg(ap, int);
	ft_putchar_fd(arg, 1);
	return (1);
}

int	print_str(va_list ap)
{
	char	*arg;

	arg = va_arg(ap, char *);
	if (!arg)
	{
		write(1, "(null)", 6);
		return (6);
	}
	ft_putstr_fd(arg, 1);
	return (ft_strlen(arg));
}
