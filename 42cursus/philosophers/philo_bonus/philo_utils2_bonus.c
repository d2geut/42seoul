/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:36:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 17:14:25 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_semaphore(t_monitor *monitor)
{
	int	i;

	monitor->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, monitor->philo_num);
	if (monitor->fork == SEM_FAILED)
	{
		sem_unlink("fork");
		monitor->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, monitor->philo_num);
	}
	monitor->flag_print = sem_open("flag_print", O_CREAT | O_EXCL, 0644, 1);
	if (monitor->flag_print == SEM_FAILED)
	{
		sem_unlink("flag_print");
		monitor->fork = sem_open("flag_print", O_CREAT | O_EXCL, 0644, 1);
	}
	i = -1;
	while (++i < monitor->philo_num)
	{
	}
}
