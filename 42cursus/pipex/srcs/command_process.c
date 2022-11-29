/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:37:18 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/30 05:14:23 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**command_argv(char	*str)
{
	char	**arr;

	arr = ft_split(str, ' ');
	return (arr);
}

static void	process_first(int fd[2], char **argv, char **envp, char **command)
{
	int	fd_in;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_perror("infile error");
	if (dup2(fd_in, 0) == -1)
		exit_perror("dup2 error");
	close(fd_in);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		exit_perror("dup2 error");
	close(fd[1]);
	if (execve(command[0], command_argv(argv[2]), envp) == -1)
		exit_perror("execve error");
}

static void	process_second(int fd[2], char **argv, char **envp, char **command)
{
	int	fd_out;

	fd_out = open(argv[4], O_WRONLY);
	if (fd_out < 0)
		exit_perror("outfile error");
	if (dup2(fd_out, 1) == -1)
		exit_perror("dup2 error");
	close(fd_out);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		exit_perror("dup2 error");
	close(fd[0]);
	if (execve(command[1], command_argv(argv[3]), envp) == -1)
		exit_perror("execve error");
}

void	command_process(char **argv, char **envp, char **command)
{
	int		fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;

	if (pipe(fd) == -1)
		exit_perror("pipe error");
	pid_1 = fork();
	if (pid_1 == -1)
		exit_perror("fork error");
	else if (pid_1 == 0)
		process_first(fd, argv, envp, command);
	pid_2 = fork();
	if (pid_2 == -1)
		exit_perror("fork error");
	else if (pid_2 == 0)
		process_second(fd, argv, envp, command);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
}
