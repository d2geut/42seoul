/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:17:24 by hanryu            #+#    #+#             */
/*   Updated: 2023/02/07 16:20:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_llist	*list;

void	set_envp(t_llist *list, char **envp)
{
	while (*envp)
	{
		list_add_back(list, *envp);
		envp++;
	}
}

int	main(int argc, char **argv, char **envp)
{
	list = init_list();
	set_envp(list, envp);
	if (argc == 1)
	{
		printf("usage: ./builtin <command> ..\n");
		return (0);
	}
	if (!execute_builtin(argv))
		return (0);
	printf("Command is not builtin\n");
	return (0);
}
