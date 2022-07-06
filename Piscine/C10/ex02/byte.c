/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:39:41 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/07 16:49:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

char	is_byte(char *str)
{
	while (is_space(*(str)))
		str++;
	while ('0' <= *str && *str <= '9')
		str++;
	return (*str);
}

void	byte_error(char *str)
{
	write(1, "tail: illegal offset -- ", 24);
	ft_putstr(str);
	write(1, "\n", 1);
}

void	argu_error(void)
{
	write(1, "tail: option requires an argument -- c\n", 39);
	write(1, "usage: tail [-F | -f | -r] [-q] \
			[-b # | -c # | -n #] [file ...]\n", 64);
}

void	fd_error(int err, char *str)
{
	write(1, "tail: ", 6);
	ft_putstr(str);
	write(1, ": ", 2);
	ft_putstr(strerror(err));
	write(1, "\n", 1);
}
