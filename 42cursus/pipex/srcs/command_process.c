/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:37:18 by hanryu            #+#    #+#             */
/*   Updated: 2022/12/05 15:39:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**command_argv(char	*str)
{
	char	**arr;

	arr = ft_split(str, ' ');
	return (arr);
}

static void	process_first(int fd[2], char **argv, char **envp, char **path)
{
	int		fd_in;
	char	*command_path;

	fd_in = open(argv[1], O_RDONLY);
	if (fd_in < 0)
		exit_perror(argv[1], 1);
	if (dup2(fd_in, 0) == -1)
		exit_perror("dup2 error", 1);
	close(fd_in);
	close(fd[0]);
	if (dup2(fd[1], 1) == -1)
		exit_perror("dup2 error", 1);
	close(fd[1]);
	command_path = command_exist(path, argv[2]);
	if (!command_path)
		exit_error("memory error", 1);
	if (execve(command_path, command_argv(argv[2]), envp) == -1)
		exit_perror("execve error", 126);
}

static void	process_second(int fd[2], char **argv, char **envp, char **path)
{
	int		fd_out;
	char	*command_path;

	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd_out < 0)
		exit_perror(argv[4], 1);
	if (dup2(fd_out, 1) == -1)
		exit_perror("dup2 error", 1);
	close(fd_out);
	close(fd[1]);
	if (dup2(fd[0], 0) == -1)
		exit_perror("dup2 error", 1);
	close(fd[0]);
	command_path = command_exist(path, argv[3]);
	if (!command_path)
		exit_error("memory error", 1);
	if (execve(command_path, command_argv(argv[3]), envp) == -1)
		exit_perror("execve error", 126);
}

void	command_process(char **argv, char **envp, char **path)
{
	int		fd[2];
	pid_t	pid_1;
	pid_t	pid_2;
	int		status;

	if (pipe(fd) == -1)
		exit_perror("pipe error", 1);
	pid_1 = fork();
	if (pid_1 == -1)
		exit_perror("fork error", 1);
	else if (pid_1 == 0)
		process_first(fd, argv, envp, path);
	pid_2 = fork();
	if (pid_2 == -1)
		exit_perror("fork error", 1);
	else if (pid_2 == 0)
		process_second(fd, argv, envp, path);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid_1, &status, 0);
	waitpid(pid_2, &status, 0);
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
}
