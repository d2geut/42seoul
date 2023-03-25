/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyang <dyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:56:47 by dyang             #+#    #+#             */
/*   Updated: 2023/01/27 15:57:53 by dyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	leaks(void)
{
	system("leaks minishell");
}

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
	t_llist	*list;
	char	*str;

	atexit(leaks);
	argc = 0;
	argv = 0;
	list = init_list();
	set_envp(list, envp);
	while (1)
	{
		str = readline("minishell$ ");
		if (str)
		{
			if (parse(str))
				;
			else
				printf("minishell: command not found: %s\n", str);
		}
		else
			break ;
		add_history(str);
		free(str);
	}
	free_list(&list);
}
