/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:34:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/05 14:46:01 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*philo_thread(void *arg)
{
	t_philo		*philo;

	philo = arg;
	if (!(philo->num % 2))
		philo_sleep(philo->info->time_eat * 1000);
	while (1)
	{
		sem_wait(philo->info->fork);
		philo_print("has taken a fork", philo);
		sem_wait(philo->info->fork);
		philo_print("has taken a fork", philo);
		sem_wait(philo->eat);
		philo->last_eat = getlongtime();
		philo_print("is eating", philo);
		philo->cnt_eat++;
		sem_post(philo->eat);
		philo_sleep(philo->info->time_eat * 1000);
		sem_post(philo->info->fork);
		sem_post(philo->info->fork);
		philo_print("is sleeping", philo);
		philo_sleep(philo->info->time_sleep * 1000);
		philo_print("is thinking", philo);
	}
	return (0);
}

static void	*monitor_thread(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		sem_wait(philo->eat);
		if (philo->info->time_die < (int)((getlongtime() - \
		philo->last_eat) / 1000))
		{
			sem_wait(philo->info->flag_print);
			printf("%lld %d died\n", (getlongtime() - \
			philo->info->time_start) / 1000, philo->num);
			sem_post(philo->info->die);
		}
		else if (philo->info->must_eat == philo->cnt_eat)
		{
			sem_post(philo->info->musteat);
			philo->cnt_eat++;
		}
		sem_post(philo->eat);
	}
	return (0);
}

void	philo_start(t_info *info)
{
	int			i;
	pthread_t	thread1;
	pthread_t	thread2;

	i = -1;
	info->time_start = getlongtime();
	while (++i < info->philo_num)
	{
		info->philo[i].last_eat = info->time_start;
		info->philo[i].pid = fork();
		if (!info->philo[i].pid)
		{
			pthread_create(&thread1, NULL, philo_thread, &info->philo[i]);
			pthread_create(&thread2, NULL, monitor_thread, &info->philo[i]);
			pthread_join(thread1, NULL);
			pthread_join(thread2, NULL);
			exit (0);
		}
	}
}
