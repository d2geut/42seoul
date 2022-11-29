/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:52:16 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/29 23:17:55 by hanryu           ###   ########.fr       */
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

static char	*pathcommand_exist(char **path, char *str)
{
	int		i;
	char	*joinstr1;
	char	*joinstr2;

	i = 0;
	while (path[i])
	{
		joinstr1 = ft_strjoin(path[i], "/");
		joinstr2 = ft_strjoin(joinstr1, str);
		if (access(joinstr2, X_OK) == 0)
		{
			ft_free((void **)&joinstr1);
			return (joinstr2);
		}
		ft_free((void **)&joinstr1);
		ft_free((void **)&joinstr2);
		i++;
	}
	return (NULL);
}

static char	*command_exist(char **path, char *command)
{
	char	*ptr;
	char	*str;
	char	*joinstr;

	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK))
			exit_error("command not found\n");
		return (ft_strdup(command));
	}
	ptr = ft_strchr(command, ' ');
	if (ptr)
		str = ft_substr(command, 0, ptr - command);
	else
		str = ft_strdup(command);
	joinstr = pathcommand_exist(path, str);
	ft_free((void **)&str);
	if (!joinstr)
		exit_error("command not found\n");
	return (joinstr);
}

char	**command_path(int argc, char **argv, char **envp)
{
	char	**path;
	char	**command;
	int		i;

	path = envp_to_path(envp);
	i = 0;
	while (path[i])
		printf("%s\n", path[i++]);
	if (path == NULL)
		exit_error("PATH is not exist\n");
	command = (char **)malloc(sizeof(char *) * (argc - 2));
	if (!command)
		exit_error("memory error\n");
	command[argc - 3] = NULL;
	i = 0;
	while (i < argc - 3)
	{
		command[i] = command_exist(path, argv[2 + i]);
		if (!command[i])
			exit_error("memory error\n");
		i++;
	}
	free_2darray(&path);
	return (command);
}
