/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 14:47:45 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 15:00:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	monitor_init_2(t_monitor *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->philo_num)
	{
		if (pthread_mutex_init(&monitor->fork[i], NULL))
		{
			mutex_array_destroy(monitor->fork, i);
			mutex_array_destroy(monitor->eat, i);
			return (free_monitor(monitor));
		}
		if (pthread_mutex_init(&monitor->eat[i], NULL))
		{
			mutex_array_destroy(monitor->fork, i + 1);
			mutex_array_destroy(monitor->eat, i);
			return (free_monitor(monitor));
		}
	}
	return (0);
}

int	philo_thread_2(t_philo *philo)
{
	philo_print("is sleeping", philo, philo->who_die);
	philo_sleep(philo->info->time_sleep * 1000);
	philo_print("is thinking", philo, philo->who_die);
	pthread_mutex_lock(philo->die);
	if (*philo->who_die)
	{
		pthread_mutex_unlock(philo->die);
		return (1);
	}
	pthread_mutex_unlock(philo->die);
	return (0);
}
