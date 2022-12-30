/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:00:23 by hanryu            #+#    #+#             */
/*   Updated: 2022/12/30 14:13:55 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(char *str, t_philo *philo, int *flag)
{
	pthread_mutex_lock(philo->flag_print);
	if (*flag == 0)
	{
		printf("%lld %d %s\n", (getlongtime() - philo->time_start) / 1000, \
		philo->num, str);
	}
	pthread_mutex_unlock(philo->flag_print);
}

void	philo_hard_print(char *str, t_philo *philo)
{
	pthread_mutex_lock(philo->flag_print);
	printf("%lld %d %s\n", (getlongtime() - philo->time_start) / 1000, \
	philo->num, str);
	pthread_mutex_unlock(philo->flag_print);
}

void	error_print(char *str, pthread_mutex_t flag_print)
{
	pthread_mutex_lock(&flag_print);
	printf("%s\n", str);
	pthread_mutex_unlock(&flag_print);
}

int	philo_sleep(long long wait)
{
	long long	after_time;
	long long	time;

	time = getlongtime();
	if (time < 0)
		return (1);
	after_time = time + wait;
	while (after_time > time)
	{
		if (usleep(100))
			return (1);
		time = getlongtime();
		if (time < 0)
			return (1);
	}
	return (0);
}
