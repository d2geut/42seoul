/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:01:15 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/05 13:02:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*monitor_die(void *arg)
{
	int		i;
	t_info	*info;

	info = arg;
	i = -1;
	sem_wait(info->die);
	while (++i < info->philo_num)
	{
		sem_post(info->musteat);
		kill(info->philo[i].pid, SIGKILL);
	}
	sem_post(info->die);
	return (0);
}

void	*monitor_musteat(void *arg)
{
	t_info	*info;
	int		i;

	info = arg;
	i = -1;
	while (++i < info->philo_num)
		sem_wait(info->musteat);
	sem_post(info->die);
	return (0);
}

void	free_kill(t_info *info)
{
	int		i;
	char	*name;

	sem_close(info->fork);
	sem_close(info->flag_print);
	sem_close(info->die);
	sem_close(info->musteat);
	sem_unlink("fork");
	sem_unlink("flag_print");
	sem_unlink("die");
	sem_unlink("musteat");
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

void	philo_monitor(t_info *info)
{
	int			i;
	int			status;
	pthread_t	thread1;
	pthread_t	thread2;

	pthread_create(&thread1, NULL, monitor_musteat, info);
	pthread_create(&thread2, NULL, monitor_die, info);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	i = -1;
	while (++i < info->philo_num)
		waitpid(info->philo[i].pid, &status, 0);
	free_kill(info);
}
