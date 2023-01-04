/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:40:38 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/04 16:43:52 by hanryu           ###   ########.fr       */
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
	int				philo_num;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	long long		time_start;
	sem_t			*fork;
	sem_t			*flag_print;
	sem_t			*die;
	struct s_philo	*philo;
}	t_info;

typedef struct s_philo
{
	struct s_info	*info;
	pid_t			pid;
	int				num;
	long long		last_eat;
	int				cnt_eat;
	sem_t			*eat;
}	t_philo;

int			argv_init(int argc, char **argv);
int			info_init(t_info *info, int argc, char **argv);
int			philo_init(t_info *info);
char		*sem_eatname(int i);
int			philo_start(t_info *info);
void		ft_free(void **ptr);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_itoa(int n);
int			exit_error(char *str, int status);
long long	getlongtime(void);
void		philo_print(char *str, t_philo *philo);
int			ft_atoi(const char *str);
void		philo_sleep(long long wait);
size_t		ft_strlen(const char *str);

#endif