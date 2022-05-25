/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:53:15 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/23 22:32:02 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexademical_2(char *hex)
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

void	hexa_char(char *hex, char arrchar)
{
	char	arr[3];
	int		n;

	n = 1;
	arr[0] = '0';
	arr[1] = '0';
	arr[2] = '\0';
	while (arrchar)
	{
		arr[n] = hex[arrchar % 16];
		arrchar = arrchar / 16;
		n--;
	}
	write(1, arr, 2);
}

void	hexa_array_2(char *hex, unsigned long addnum)
{
	char	arr[17];
	int		n;

	n = 0;
	while (1)
	{
		arr[n] = '0';
		n++;
		if (n == 16)
		{
			arr[n] = '\0';
			break ;
		}
	}
	while (addnum)
	{
		arr[n - 1] = hex[addnum % 16];
		addnum = addnum / 16;
		n--;
	}
	write(1, arr, 16);
	write(1, ": ", 2);
}

void	hexa_array_1(char *hex, void *addr, unsigned int i)
{
	unsigned int	n;
	unsigned int	k;

	n = 0;
	k = i;
	while (n < i)
	{
		hexa_char(hex, *(char *)(addr + n));
		if (n % 2)
			write(1, " ", 1);
		n++;
	}
	while (k++ < 16)
	{
		write(1, "  ", 2);
		if (k % 2)
			write(1, " ", 1);
	}
	n = 0;
	while (n++ < i)
		if (*(char *)(addr + n) <= 31 || 127 <= *(char *)(addr + n))
			*(char *)(addr + n) = '.';
	write(1, addr, i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			hex[17];
	unsigned int	i;
	int				n;

	i = size;
	n = 0;
	hexademical_2(hex);
	while (i > 0)
	{
		hexa_array_2(hex, (unsigned long)(addr + n * 16));
		if (i > 16)
			hexa_array_1(hex, addr + n * 16, 16);
		else
			hexa_array_1(hex, addr + n * 16, i);
		write(1, "\n", 1);
		if (i < 16)
			break ;
		i = i - 16;
		n++;
	}
	return (addr);
}
