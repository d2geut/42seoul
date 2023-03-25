/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:55:54 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/30 07:28:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exit_perror(char *message, int status)
{
	perror(message);
	exit (status);
}

void	exit_error(char *message, int status)
{
	ft_putstr_fd(message, 2);
	exit (status);
}

void	ft_free(void **ptr)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	free(*ptr);
	*ptr = NULL;
}

void	free_2darray(char ***arr)
{
	int	i;

	i = 0;
	while ((*arr)[i])
	{
		ft_free((void **)&((*arr)[i]));
		i++;
	}
	ft_free((void **)(*arr)[i]);
	free(*arr);
	*arr = NULL;
}
