/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_free_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 17:25:57 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 14:56:38 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

int	free_monitor(t_monitor *monitor)
{
	ft_free((void *)&monitor->fork);
	ft_free((void *)&monitor->eat);
	ft_free((void *)&monitor->thread);
	ft_free((void *)&monitor->philo);
	return (1);
}

void	mutex_array_destroy(pthread_mutex_t *arr, int num)
{
	int	i;

	i = -1;
	while (++i < num)
		pthread_mutex_destroy(&arr[i]);
}

int	all_free_destroy(t_monitor *monitor)
{
	int	i;

	i = -1;
	while (++i < monitor->philo_num)
	{
		pthread_mutex_destroy(&monitor->fork[i]);
		pthread_mutex_destroy(&monitor->eat[i]);
	}
	pthread_mutex_destroy(&monitor->flag_print);
	pthread_mutex_destroy(&monitor->die);
	return (free_monitor(monitor));
}

int	thread_create_error(t_monitor *monitor, pthread_t mtr)
{
	int	i;

	pthread_mutex_lock(&monitor->die);
	monitor->who_die = 1;
	pthread_mutex_unlock(&monitor->die);
	error_print("pthread create error", monitor->flag_print);
	i = -1;
	while (++i < monitor->philo_num)
		pthread_join(monitor->thread[i], NULL);
	if (mtr)
		pthread_join(mtr, NULL);
	return (all_free_destroy(monitor));
}
