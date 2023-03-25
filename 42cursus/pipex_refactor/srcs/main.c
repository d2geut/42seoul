/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:20:01 by hanryu            #+#    #+#             */
/*   Updated: 2023/02/08 18:59:02 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	**envp_to_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (ft_split(envp[i] + 5, ':'));
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv, char **envp)
{
	char	**path;

	 if (argc < 5)
	 {
	 	exit_error("usage: ./pipex file1 cmd1 ... cmdn file2\n", 1);
	 }
	path = envp_to_path(envp);
	if (path == NULL)
		exit_error("PATH is not exist\n", 1);
	command_process(argc, argv, envp, path);
	free_2darray(&path);
	return (0);
}
