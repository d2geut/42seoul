/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:40:38 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/02 17:14:42 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <semaphore.h>

typedef struct s_info
{
	int	time_die;
	int	time_eat;
	int	time_sleep;
}	t_info;

typedef struct s_philo
{
	struct s_info	*info;
	int				num;
	long long		time_start;
	long long		last_eat;
	int				cnt_eat;
	int				*who_die;
}	t_philo;

typedef struct s_monitor
{
	int				philo_num;
	int				must_eat;
	struct s_philo	*philo;
	long long		time_start;
	int				who_die;
	pid_t			*philo;
	sem_t			fork;
	sem_t			flag_print;
	sem_t			*eat;
	sem_t			die;
}	t_monitor;



void		philo_print(char *str, t_philo *philo, int *flag);
void		philo_hard_print(char *str, t_philo *philo);
void		error_print(char *str, pthread_mutex_t flag_print);
int			print_error(char *str);
int			ft_atoi(const char *str);
long long	getlongtime(void);
int			philo_start(t_monitor *monitor);
int			free_monitor(t_monitor *monitor);
void		mutex_array_destroy(pthread_mutex_t *arr, int num);
int			all_free_destroy(t_monitor *monitor);
int			thread_create_error(t_monitor *monitor, pthread_t mtr);
void		error_print(char *str, pthread_mutex_t flag_print);
void		philo_sleep(long long wait);
int			monitor_init_2(t_monitor *monitor);
int			philo_thread_2(t_philo *philo);

#endif