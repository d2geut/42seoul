/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:16:29 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/23 22:28:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexademical(char *hex)
{
	hex[0] = '0';
	hex[1] = '1';
	hex[2] = '2';
	hex[3] = '3';
	hex[4] = '4';
	hex[5] = '5';
	hex[6] = '6';
	hex[7] = '7';
	hex[8] = '8';
	hex[9] = '9';
	hex[10] = 'a';
	hex[11] = 'b';
	hex[12] = 'c';
	hex[13] = 'd';
	hex[14] = 'e';
	hex[15] = 'f';
}

void	hexa_array(char *hex, char *str, int i)
{
	char	arr[3];
	int		n;

	n = 1;
	arr[0] = '0';
	arr[1] = '0';
	arr[2] = '\0';
	while (str[i])
	{
		arr[n] = hex[str[i] % 16];
		str[i] = str[i] / 16;
		n--;
	}
	write(1, "\\", 1);
	write(1, arr, 2);
}

void	ft_putstr_non_printable(char *str)
{
	int		i;
	char	hex[17];

	i = 0;
	hexademical(hex);
	while (str[i])
	{
		if (str[i] <= 31 || 127 <= str[i])
			hexa_array(hex, str, i);
		else
			write(1, &str[i], 1);
		i++;
	}
}
