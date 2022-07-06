/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:16:29 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/26 10:00:31 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa_array(char *hex, unsigned char c)
{
	char	n1;
	char	n2;

	n2 = hex[c % 16];
	n1 = hex[c / 16];
	write(1, "\\", 1);
	write(1, &n1, 1);
	write(1, &n2, 1);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	*hex;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i])
	{
		if ((unsigned char)str[i] <= 31 || 127 <= (unsigned char)str[i])
			hexa_array(hex, (unsigned char)str[i]);
		else
			write(1, &str[i], 1);
		i++;
	}
}
