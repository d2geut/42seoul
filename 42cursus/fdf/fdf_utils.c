/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 10:48:22 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/02 13:13:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_getnbr(char *str)
{
	int	i;
	int	sum;
	int	sign;

	i = 0;
	sum = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum = sum * 10;
		sum += sign * (str[i] - '0');
		i++;
	}
	return (sum);
}

void	ft_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	ft_2darray_free(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		ft_free((void **)&((*arr)[i]));
		i++;
	}
	free(*arr);
	*arr = NULL;
}

void	free_map(t_map ***map)
{
	int	i;

	i = 0;
	while ((*map)[i])
	{
		ft_free((void **)&(*map)[i]);
		i++;
	}
	free(*map);
	*map = NULL;
}

double	margin_scale(int max_x, int max_y)
{
	double	scale_x;
	double	scale_y;

	scale_x = (WINDOW_MARGIN_X / 2) / (double)max_x;
	scale_y = (WINDOW_MARGIN_Y / 2) / (double)max_y;
	if (scale_x < scale_y)
		return (scale_x);
	return (scale_y);
}