/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 15:06:50 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/04 16:16:08 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft.h"

int	min(int n1, int n2, int n3);

void	dynamic(t_field (*str)[28], int height)
{
	int	i;
	int	j;

	i = 1;
	while (i < height)
	{
		j = 1;
		while (str[i][j].element)
		{
			if (str[i][j].dp)
				str[i][j].dp = min(str[i - 1][j].dp, str[i][j - 1].dp, str[i - 1][j - 1].dp) + 1;
			j++;
		}
		i++;
	}
}

int min(int n1, int n2, int n3)
{
	int	n;

	n = n1;
	if (n > n2)
		n = n2;
	if (n > n3)
		n = n3;
	return (n);
}
