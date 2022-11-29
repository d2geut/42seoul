/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:20:01 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/30 05:14:12 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	file_access(char *infile, char *outfile)
{
	int	fd;

	if (access(infile, R_OK))
		perror(infile);
	fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 00644);
	if (fd < 0)
		exit_perror(outfile);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	char	**command;

	if (argc != 5)
	{
		exit_error("usage: ./pipex file1 cmd1 cmd2 file2\n");
	}
	file_access(argv[1], argv[4]);
	command = command_path(argc, argv, envp);
	command_process(argv, envp, command);
	free_2darray(&command);
	system("leaks pipex");
	return (0);
}
