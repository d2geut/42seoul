/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:41:52 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/01 11:25:42 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void	write_str(char *arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	write_nbr(int nbr)
{
	char	c;

	if (nbr < 10)
	{
		c = nbr + '0';
		write(1, &c, 1);
	}
	else
	{
		write_nbr(nbr / 10);
		c = nbr % 10 + '0';
		write(1, &c, 1);
	}
}

void	ft_show_tab(struct s_stock_str *par)
{
	int		i;

	i = 0;
	while (par[i].str)
	{
		write_str(par[i].str);
		write_nbr(par[i].size);
		write(1, "\n", 1);
		write_str(par[i].copy);
		i++;
	}
}
