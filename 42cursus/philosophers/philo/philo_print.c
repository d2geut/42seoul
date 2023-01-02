/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:00:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 14:22:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_print(char *str, t_philo *philo, int *flag)
{
	pthread_mutex_lock(philo->flag_print);
	pthread_mutex_lock(philo->die);
	if (*flag == 0)
	{
		printf("%lld %d %s\n", (getlongtime() - philo->time_start) / 1000, \
		philo->num, str);
	}
	pthread_mutex_unlock(philo->die);
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

void	philo_sleep(long long wait)
{
	long long	after_time;

	after_time = getlongtime() + wait;
	while (after_time > getlongtime())
		usleep(100);
}
