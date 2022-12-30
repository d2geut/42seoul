/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:56:33 by hanryu            #+#    #+#             */
/*   Updated: 2022/12/30 17:50:38 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	argv_init(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while ('0' <= argv[i][j] && argv[i][j] <= '9')
			j++;
		if (argv[i][j])
			return (1);
		i++;
	}
	return (0);
}

static int	info_init(t_info *info, t_monitor *monitor, int argc, char **argv)
{
	if (!memset(info, 0, sizeof(t_info)))
		return (1);
	if (!memset(monitor, 0, sizeof(t_monitor)))
		return (1);
	monitor->philo_num = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (monitor->philo_num <= 0 || info->time_die < 0 || info->time_eat < 0 \
	|| info->time_sleep < 0)
		return (1);
	monitor->must_eat = -1;
	if (argc == 6)
	{
		monitor->must_eat = ft_atoi(argv[5]);
		if (monitor->must_eat < 0)
			return (1);
	}
	return (0);
}

static int	monitor_init(t_monitor *monitor)
{
	int	i;

	monitor->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * \
	monitor->philo_num);
	if (!monitor->fork)
		return (free_monitor(monitor));
	monitor->thread = (pthread_t *)malloc(sizeof(pthread_t) * \
	monitor->philo_num);
	if (!monitor->thread)
		return (free_monitor(monitor));
	monitor->philo = (t_philo *)malloc(sizeof(t_philo) * monitor->philo_num);
	if (!monitor->philo)
		return (free_monitor(monitor));
	if (pthread_mutex_init(&monitor->flag_print, NULL))
		return (free_monitor(monitor));
	i = -1;
	while (++i < monitor->philo_num)
	{
		if (pthread_mutex_init(&monitor->fork[i], NULL))
		{
			mutex_array_destroy(monitor->fork, i);
			return (free_monitor(monitor));
		}
	}
	return (0);
}

static int	philo_init(t_info *info, t_monitor *monitor)
{
	int	i;

	if (monitor_init(monitor))
		return (1);
	i = -1;
	while (++i < monitor->philo_num)
	{
		if (!memset(&monitor->philo[i], 0, sizeof(t_philo)))
		{
			mutex_array_destroy(monitor->fork, monitor->philo_num);
			return (free_monitor(monitor));
		}
		monitor->philo[i].info = info;
		monitor->philo[i].num = i + 1;
		monitor->philo[i].fork_left = &monitor->fork[i];
		monitor->philo[i].fork_right = &monitor->fork[(i + 1) % \
		monitor->philo_num];
		monitor->philo[i].flag_print = &monitor->flag_print;
		monitor->philo[i].who_die = &monitor->who_die;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_info		info;
	t_monitor	monitor;

	if (!(argc == 5 || argc == 6))
		return (print_error("argc error\n"));
	if (argv_init(argc, argv) || info_init(&info, &monitor, argc, argv))
		return (print_error("argv error\n"));
	if (philo_init(&info, &monitor))
		return (print_error("philo init error\n"));
	if (philo_start(&monitor))
		return (print_error("philo error\n"));
	return (0);
}
