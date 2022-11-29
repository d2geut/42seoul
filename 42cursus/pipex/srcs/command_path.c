/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:52:16 by hanryu            #+#    #+#             */
/*   Updated: 2022/11/30 07:28:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

char	*command_exist(char **path, char *command)
{
	char	*ptr;
	char	*str;
	char	*joinstr;

	if (ft_strchr(command, '/'))
	{
		if (access(command, X_OK))
			exit_error("command not found\n", 127);
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
		exit_error("command not found\n", 127);
	return (joinstr);
}
