/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 20:37:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/02/08 18:53:13 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**command_argv(char	*str)
{
	char	**arr;

	arr = ft_split(str, ' ');
	return (arr);
}

// static void	process_first(int fd[2], char **argv, char **envp, char **path)
// {
// 	int		fd_in;
// 	char	*command_path;

// 	fd_in = open(argv[1], O_RDONLY);
// 	if (fd_in < 0)
// 		exit_perror(argv[1], 1);
// 	if (dup2(fd_in, 0) == -1)
// 		exit_perror("dup2 error", 1);
// 	close(fd_in);
// 	close(fd[0]);
// 	if (dup2(fd[1], 1) == -1)
// 		exit_perror("dup2 error", 1);
// 	close(fd[1]);
// 	command_path = command_exist(path, argv[2]);
// 	if (!command_path)
// 		exit_error("memory error", 1);
// 	if (execve(command_path, command_argv(argv[2]), envp) == -1)
// 		exit_perror("execve error", 126);
// }

// static void	process_second(int fd[2], char **argv, char **envp, char **path)
// {
// 	int		fd_out;
// 	char	*command_path;

// 	fd_out = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 00644);
// 	if (fd_out < 0)
// 		exit_perror(argv[4], 1);
// 	if (dup2(fd_out, 1) == -1)
// 		exit_perror("dup2 error", 1);
// 	close(fd_out);
// 	close(fd[1]);
// 	if (dup2(fd[0], 0) == -1)
// 		exit_perror("dup2 error", 1);
// 	close(fd[0]);
// 	command_path = command_exist(path, argv[3]);
// 	if (!command_path)
// 		exit_error("memory error", 1);
// 	if (execve(command_path, command_argv(argv[3]), envp) == -1)
// 		exit_perror("execve error", 126);
// }

int	fork_process(int i, int argc, char **argv, char **envp, char **path, int *fd_file)
{
	int		fd[2];
	pid_t	pid;
	char	*command_path;
	int		status;

	if (i == 1)
	{
		pid = fork();
		if (pid == 0)
		{
			dup2(fd_file[0], 0);
			dup2(fd_file[1], 1);
			close(fd_file[0]);
			close(fd_file[1]);
			command_path = command_exist(path, argv[argc - i - 1]);
			if (execve(command_path, command_argv(argv[argc- i - 1]), envp) == -1)
				exit_perror("execve error", 126);
		}
		close(fd_file[0]);
		close(fd_file[1]);
		waitpid(pid, &status, 0);
	}
	else
	{
		pipe(fd);
		pid = fork();
		if (pid == 0)
		{
			close(fd[0]);
			dup2(fd_file[0], 0);
			dup2(fd[1], 1);
			close(fd_file[0]);
			close(fd[1]);
			command_path = command_exist(path, argv[argc - i - 1]);
			if (execve(command_path, command_argv(argv[argc- i - 1]), envp) == -1)
				exit_perror("execve error", 126);
		}
		close(fd_file[0]);
		close(fd[1]);
		fd_file[0] = fd[0];
		status = fork_process(i - 1, argc, argv, envp, path, fd_file);
		waitpid(pid, NULL, 0);
	}
	return (status);
}

void	command_process(int argc, char **argv, char **envp, char **path)
{
	int		status;
	int		fd_file[2];

	fd_file[0] = open(argv[1], O_RDONLY);
	if (fd_file[0] < 0)
		exit_perror(argv[1], 1);
	fd_file[1] = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd_file[1] < 0)
		exit_perror(argv[argc - 1], 1);
	status = fork_process(argc - 3, argc, argv, envp, path, fd_file);
	if (WEXITSTATUS(status))
		exit(WEXITSTATUS(status));
}
