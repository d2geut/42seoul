/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:34:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 15:01:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*philo_one(t_philo *philo)
{
	pthread_mutex_lock(philo->fork_left);
	philo_print("has taken a fork", philo, philo->who_die);
	pthread_mutex_unlock(philo->fork_left);
	return (0);
}

static void	*philo_thread(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->fork_left == philo->fork_right)
		return (philo_one(philo));
	if (!(philo->num % 2))
		philo_sleep(philo->info->time_eat * 1000);
	while (1)
	{
		pthread_mutex_lock(philo->fork_left);
		philo_print("has taken a fork", philo, philo->who_die);
		pthread_mutex_lock(philo->fork_right);
		philo_print("has taken a fork", philo, philo->who_die);
		pthread_mutex_lock(philo->eat);
		philo->last_eat = getlongtime();
		philo_print("is eating", philo, philo->who_die);
		philo->cnt_eat++;
		pthread_mutex_unlock(philo->eat);
		philo_sleep(philo->info->time_eat * 1000);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		if (philo_thread_2(philo))
			break ;
	}
	return (0);
}

static void	monitor_thread2(t_monitor *monitor, int *eat_all)
{
	int	i;

	i = -1;
	while (++i < monitor->philo_num)
	{
		pthread_mutex_lock(&monitor->eat[i]);
		if (monitor->philo[i].info->time_die < (int)((getlongtime() \
		- monitor->philo[i].last_eat) / 1000))
		{
			pthread_mutex_lock(&monitor->die);
			monitor->who_die = 1;
			pthread_mutex_unlock(&monitor->die);
			philo_hard_print("died", &monitor->philo[i]);
			pthread_mutex_unlock(&monitor->eat[i]);
			return ;
		}
		if (monitor->must_eat >= 0 && \
		monitor->philo[i].cnt_eat >= monitor->must_eat)
			(*eat_all)++;
		pthread_mutex_unlock(&monitor->eat[i]);
	}
}

static void	*monitor_thread(void *arg)
{
	t_monitor	*monitor;
	int			eat_all;

	monitor = (t_monitor *)arg;
	while (1)
	{
		eat_all = 0;
		monitor_thread2(monitor, &eat_all);
		if (monitor->must_eat >= 0 && eat_all == monitor->philo_num)
		{
			pthread_mutex_lock(&monitor->die);
			monitor->who_die = 1;
			pthread_mutex_unlock(&monitor->die);
		}
		pthread_mutex_lock(&monitor->die);
		if (monitor->who_die)
		{
			pthread_mutex_unlock(&monitor->die);
			break ;
		}
		pthread_mutex_unlock(&monitor->die);
	}
	return (0);
}

int	philo_start(t_monitor *monitor)
{
	int			i;
	pthread_t	mtr;

	monitor->time_start = getlongtime();
	i = -1;
	while (++i < monitor->philo_num)
	{
		monitor->philo[i].time_start = monitor->time_start;
		monitor->philo[i].last_eat = monitor->time_start;
		if (pthread_create(&monitor->thread[i], NULL, philo_thread, \
		&monitor->philo[i]))
			return (thread_create_error(monitor, NULL));
	}
	if (pthread_create(&mtr, NULL, monitor_thread, monitor))
		return (thread_create_error(monitor, mtr));
	i = -1;
	while (++i < monitor->philo_num)
		pthread_join(monitor->thread[i], NULL);
	pthread_join(mtr, NULL);
	(void)all_free_destroy(monitor);
	return (0);
}
