/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:40:38 by hanryu            #+#    #+#             */
/*   Updated: 2022/12/30 17:50:29 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info
{
	int	time_die;
	int	time_eat;
	int	time_sleep;
}	t_info;

typedef struct s_philo
{
	struct s_info	*info;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*flag_print;
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
	pthread_t		*thread;
	pthread_mutex_t	*fork;
	pthread_mutex_t	flag_print;
	long long		time_start;
	int				who_die;
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
int			philo_sleep(long long wait);

#endif