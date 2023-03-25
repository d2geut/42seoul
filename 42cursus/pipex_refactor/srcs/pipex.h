/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 13:44:30 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/24 14:06:48 by hanryu           ###   ########.fr       */
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

void	command_process(int argc, char **argv, char **envp, char **path);
char	*command_exist(char **path, char *command);
void	exit_perror(char *message, int status);
void	exit_error(char *message, int status);
void	ft_free(void **ptr);
void	free_2darray(char ***arr);

#endif