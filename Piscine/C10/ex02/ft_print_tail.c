/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tail.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:11:32 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/07 19:48:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

void	shift(char *buff, char buff_temp)
{
	int	i;

	i = 0;
	while (buff[i + 1])
	{
		buff[i] = buff[i + 1];
		i++;
	}
	buff[i] = buff_temp;
}

void	print_noav(int size_byte)
{
	char	*buff;
	char	buff_temp;
	ssize_t	size;
	int		i;

	buff = (char *)malloc(sizeof(char) * (size_byte + 1));
	i = 0;
	while (1)
	{
		size = read(0, &buff_temp, 1);
		if (size == 0)
			break ;
		if (i < size_byte)
		{
			buff[i++] = buff_temp;
			buff[i] = '\0';
		}
		else
			shift(buff, buff_temp);
	}
	ft_putstr(buff);
	free(buff);
}

void	print_noone(void)
{
	char	buff;
	ssize_t	size;

	while (1)
	{
		size = read(0, &buff, 1);
		if (size == 0)
			break ;
	}
}
