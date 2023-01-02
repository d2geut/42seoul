/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:24:44 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 16:08:20 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	return (1);
}

static int	is_space(const char c)
{
	if ((9 <= c && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			minus;
	long long	sum;

	i = 0;
	minus = 1;
	sum = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		sum = sum * 10;
		if (minus > 0)
			sum += str[i] - '0';
		else
			sum -= str[i] - '0';
		i++;
	}
	return ((int)sum);
}

long long	getlongtime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_usec + tv.tv_sec * 1000000);
}
