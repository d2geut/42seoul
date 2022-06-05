/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yehyun <yehyun@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:40:29 by yehyun            #+#    #+#             */
/*   Updated: 2022/06/04 15:28:46 by yehyun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft.h"

int	ft_atoi(char *str)
{
	int			i;
	int			count;
	long long	temp_num;

	i = 0;
	count = 0;
	temp_num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			count++;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp_num *= 10;
		temp_num += str[i] - '0';
		i++;
	}
	if (count % 2 == 1)
		return ((int)(temp_num * -1));
	else
		return ((int)temp_num);
}
