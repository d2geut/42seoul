/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:36:16 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/05 11:57:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	argv_init(int argc, char **argv)
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

int	info_init(t_info *info, int argc, char **argv)
{
	memset(info, 0, sizeof(t_info));
	info->philo_num = ft_atoi(argv[1]);
	info->time_die = ft_atoi(argv[2]);
	info->time_eat = ft_atoi(argv[3]);
	info->time_sleep = ft_atoi(argv[4]);
	if (info->philo_num <= 0 || info->time_die < 0 || info->time_eat < 0 \
	|| info->time_sleep < 0)
		return (1);
	info->must_eat = -1;
	if (argc == 6)
	{
		info->must_eat = ft_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (1);
	}
	return (0);
}

static void	semaphore_init(t_info *info)
{
	info->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, info->philo_num);
	if (info->fork == SEM_FAILED)
	{
		sem_unlink("fork");
		info->fork = sem_open("fork", O_CREAT | O_EXCL, 0644, info->philo_num);
	}
	info->flag_print = sem_open("flag_print", O_CREAT | O_EXCL, 0644, 1);
	if (info->flag_print == SEM_FAILED)
	{
		sem_unlink("flag_print");
		info->flag_print = sem_open("flag_print", O_CREAT | O_EXCL, 0644, 1);
	}
	info->die = sem_open("die", O_CREAT | O_EXCL, 0644, 0);
	if (info->die == SEM_FAILED)
	{
		sem_unlink("die");
		info->die = sem_open("die", O_CREAT | O_EXCL, 0644, 0);
	}
	info->musteat = sem_open("musteat", O_CREAT | O_EXCL, 0644, 0);
	if (info->musteat == SEM_FAILED)
	{
		sem_unlink("musteat");
		info->musteat = sem_open("musteat", O_CREAT | O_EXCL, 0644, 0);
	}
}

char	*sem_eatname(int i)
{
	char	*name;
	char	*num;

	num = ft_itoa(i);
	if (!num)
		return (NULL);
	name = ft_strjoin("eat_", num);
	if (!name)
	{
		ft_free((void *)&num);
		return (NULL);
	}
	ft_free((void *)&num);
	return (name);
}

int	philo_init(t_info *info)
{
	int		i;
	char	*name;

	semaphore_init(info);
	info->philo = (t_philo *)malloc(sizeof(t_philo) * info->philo_num);
	if (!info->philo)
		return (1);
	i = -1;
	while (++i < info->philo_num)
	{
		memset(&info->philo[i], 0, sizeof(t_philo));
		info->philo[i].info = info;
		info->philo[i].num = i + 1;
		name = sem_eatname(i);
		if (!name)
			return (1);
		info->philo[i].eat = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		if (info->philo[i].eat == SEM_FAILED)
		{
			sem_unlink(name);
			info->philo[i].eat = sem_open(name, O_CREAT | O_EXCL, 0644, 1);
		}
		ft_free((void *)&name);
	}
	return (0);
}
