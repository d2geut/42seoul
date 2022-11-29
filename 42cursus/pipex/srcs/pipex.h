/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:44:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/29 23:01:03 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>

char	**command_path(int argc, char **argv, char **envp);
void	command_process(char **argv, char **command);
void	exit_perror(char *message);
void	exit_error(char *message);
void	ft_free(void **ptr);
void	free_2darray(char ***arr);

#endif