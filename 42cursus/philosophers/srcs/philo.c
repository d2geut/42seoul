/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:34:23 by hanryu            #+#    #+#             */
/*   Updated: 2022/12/29 20:28:05 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_print(char *str, t_philo *philo, int flag)
{
	if (flag)
		return ;
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

static void	*philo_thread(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
	if (philo->num % 2)
		usleep(philo->info->time_eat * 1000);
	while (!(*philo->who_die))
	{
		pthread_mutex_lock(philo->fork_left);
		philo_print("has taken a fork", philo, *philo->who_die);
		pthread_mutex_lock(philo->fork_right);
		philo_print("has taken a fork", philo, *philo->who_die);
		philo->last_eat = getlongtime();
		philo_print("is eating", philo, *philo->who_die);
		usleep(philo->info->time_eat * 1000);
		pthread_mutex_unlock(philo->fork_left);
		pthread_mutex_unlock(philo->fork_right);
		philo_print("is sleeping", philo, *philo->who_die);
		usleep(philo->info->time_sleep * 1000);
		philo_print("is thinking", philo, *philo->who_die);
	}
	return (0);
}

void	*monitor_thread(void *arg)
{
	t_monitor	*monitor;
	int			i;

	monitor = (t_monitor *)arg;
	while (!monitor->who_die)
	{
		i = -1;
		while (++i < monitor->philo_num)
		{
			if (monitor->philo[i].info->time_die < (int)((getlongtime() \
			- monitor->philo[i].last_eat) / 1000))
			{
				monitor->who_die = 1;
				philo_print("died", &monitor->philo[i], 0);
				break ;
			}
		}
	}
	return (0);
}

int	philo_start(t_monitor *monitor)
{
	int			i;
	pthread_t	mtr;

	monitor->time_start = getlongtime();
	if (monitor->time_start == -1)
		return (all_free_destroy(monitor));
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
