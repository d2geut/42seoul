/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:53:15 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/26 12:04:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	hexa_char(char *hex, char *c)
{	
	char	n1;
	char	n2;

	n2 = hex[*c % 16];
	n1 = hex[*c / 16];
	write(1, &n1, 1);
	write(1, &n2, 1);
}

void	hexa_array_1(char *hex, unsigned long addnum)
{
	char	arr[20];
	int		n;

	n = 0;
	while (n < 16)
	{
		arr[n] = hex[addnum % 16];
		addnum = addnum / 16;
		n++;
	}
	while (n >= 0)
		write(1, &arr[--n], 1);
	write(1, ": ", 2);
}

void	hexa_array_2(char *hex, void *addr, unsigned int i)
{
	unsigned int	n;
	unsigned int	k;

	n = 0;
	k = i;
	while (n < i)
	{
		hexa_char(hex, (char *)(addr + n));
		if (n % 2)
			write(1, " ", 1);
		n++;
	}
	while (k < 16)
	{
		write(1, "  ", 2);
		if (k % 2)
			write(1, " ", 1);
		k++;
	}
	n = 0;
	while (n++ < i)
		if (*(char *)(addr + n) <= 31 || 127 <= *(char *)(addr + n))
			*(char *)(addr + n) = '.';
	write(1, addr, i);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	char			*hex;
	unsigned int	i;
	int				n;

	i = size;
	n = 0;
	hex = "0123456789abcdef";
	while (i > 0)
	{
		hexa_array_1(hex, (unsigned long)(addr + n * 16));
		if (i > 16)
			hexa_array_2(hex, addr + n * 16, 16);
		else
			hexa_array_2(hex, addr + n * 16, i);
		write(1, "\n", 1);
		if (i < 16)
			break ;
		i = i - 16;
		n++;
	}
	return (addr);
}
