/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 11:34:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/04 16:53:29 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	*philo_thread(void *arg)
{
	t_philo		*philo;

	philo = (t_philo *)arg;
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

	philo = (t_philo *)arg;
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
			sem_post(philo->info->flag_print);
		}
		else if (philo->info->must_eat >= 0 && philo->info->must_eat \
		<= philo->cnt_eat)
			kill(philo->pid, SIGKILL);
		sem_post(philo->eat);
	}
	return (0);
}

void	free_kill(t_info *info)
{
	int		i;
	char	*name;

	sem_close(info->fork);
	sem_close(info->flag_print);
	sem_close(info->die);
	sem_unlink("fork");
	sem_unlink("flag_print");
	sem_unlink("die");
	i = -1;
	while (++i < info->philo_num)
	{
		sem_close(info->philo[i].eat);
		name = sem_eatname(i);
		if (!name)
			exit_error("malloc error\n", 1);
		sem_unlink(name);
		ft_free((void *)&name);
	}
	ft_free((void *)&info->philo);
}

void	monitor_die(t_info *info)
{
	int	i;

	i = -1;
	sem_wait(info->die);
	while (++i < info->philo_num)
		kill(info->philo[i].pid, SIGKILL);
	sem_post(info->die);
}

int	philo_start(t_info *info)
{
	int			i;
	pthread_t	thread1;
	pthread_t	thread2;
	int			status;

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
	monitor_die(info);
	i = -1;
	while (++i < info->philo_num)
		waitpid(info->philo[i].pid, &status, 0);
	free_kill(info);
	return (0);
}
