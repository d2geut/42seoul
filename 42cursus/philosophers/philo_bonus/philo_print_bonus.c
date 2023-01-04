/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:00:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/04 16:36:32 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	philo_print(char *str, t_philo *philo)
{
	sem_wait(philo->info->flag_print);
	printf("%lld %d %s\n", (getlongtime() - philo->info->time_start) / 1000, \
	philo->num, str);
	sem_post(philo->info->flag_print);
}

void	philo_sleep(long long wait)
{
	long long	after_time;

	after_time = getlongtime() + wait;
	while (after_time > getlongtime())
		usleep(100);
}

void	ft_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}
