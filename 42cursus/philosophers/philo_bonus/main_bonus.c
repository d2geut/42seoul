/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 08:56:33 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/05 11:01:32 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_info	info;

	if (!(argc == 5 || argc == 6))
		exit_error("argc error\n", 1);
	if (argv_init(argc, argv) || info_init(&info, argc, argv))
		exit_error("argv error\n", 1);
	if (philo_init(&info))
		exit_error("philo init error\n", 1);
	philo_start(&info);
	philo_monitor(&info);
	return (0);
}
