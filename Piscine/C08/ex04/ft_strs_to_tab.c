/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:19:24 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/31 22:43:00 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

void	into_strs(t_stock_str *strs, int ac, char **av)
{
	int	i;
	int	s;

	i = 0;
	while (i < ac)
	{
		s = 0;
		while (av[i][s])
			s++;
		strs[i].size = s;
		strs[i].str = av[i];
		strs[i].copy = (char *)malloc(sizeof(char) * (s + 1));
		s = 0;
		while (av[i][s])
		{
			strs[i].copy[s] = av[i][s];
			s++;
		}
		strs[i].copy[s] = '\0';
		i++;
	}
	strs[i].str = 0;
	strs[i].copy = 0;
	strs[i].size = 0;
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*strs;

	strs = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!strs)
		return (0);
	into_strs(strs, ac, av);
	return (strs);
}
