/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:57:56 by hanryu            #+#    #+#             */
/*   Updated: 2023/02/07 17:17:37 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

void	builtin_echo(char **argv)
{
	int	i;
	int	j;
	int	flag;

	i = 1;
	flag = 0;
	while (argv[++i] && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][++j])
			if (argv[i][j] != 'n')
				break ;
		if (argv[i][j])
			break ;
	}
	if (i != 2)
		flag = 1;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	if (!flag)
		printf("\n");
}

void	builtin_pwd(char **argv)
{
	char	*str;
	char	option;
	
	if (argv[2] && argv[2][0] == '-' && argv[2][1])
	{
		option = is_optionvalid(argv[2]);
		if (option)
		{
			printf("builtin: pwd: -%c: invalid option\npwd: usage: pwd\n", option);
			return ;
		}
	}
	str = getcwd(NULL, 0);
	if (str == NULL)
		perror("builtin: pwd");
	else
		printf("%s\n", str);
	free(str);
}

void	builtin_cd(char **argv)
{
	char	*errmsg;
	char	option;

	if (!argv[2])
	{
		write(2, "builtin: cd: Invalid argument\n", 30);
		return ;
	}
	if (argv[2] && argv[2][0] == '-' && argv[2][1])
	{
		option = is_optionvalid(argv[2]);
		if (option)
		{
			printf("builtin: cd: -%c: invalid option\ncd: usage: cd\n", option);
			return ;
		}
	}
	if (chdir(argv[2]))
	{
		errmsg = ft_strjoin("builtin: cd: ", argv[2]);
		perror(errmsg);
		free(errmsg);
	}
	printf("==result==\n");
	builtin_pwd(argv);
}

void	builtin_env(char **argv)
{
	char	option;

	option = 0;
	if (argv[2])
	{
		if (argv[2][0] == '-')
		{
			option = is_optionvalid(argv[2]);
			if (!argv[2][1])
				option = '-';
			if (option && option != '-')
			{
				printf("env: illegal option -- %c\nusage: env\n", option);
				return ;
			}
		}
		else
		{
			write(2, "env: Argument list too long\n", 28);
			return ;
		}
	}
	if (!option)
		env_table(list);
}

void	builtin_unset(char **argv)
{
	int		i;
	char	option;

	i = 1;
	while (argv[++i])
	{
		if (i == 2 && argv[2][0] == '-' && argv[2][1])
		{
			option = is_optionvalid(argv[2]);
			if (option)
			{
				printf("builtin: unset: -%c: invalid option\nunset: usage: unset [name ...]\n", option);
				return ;
			}
			continue ;
		}
		if (!is_namevalid(argv[i], ft_strlen(argv[i])))
			printf("builtin: unset: '%s': not a valid identifier\n", argv[i]);
		else
		{
			printf("remove %d\n", search_node(list, argv[i]));
			list_remove_at(list, search_node(list, argv[i]));
			printf("==result==\n");	// unset 결과 출력을 위한 임시 코드
			print_table(list); //
		}
	}
}

void	builtin_export_2(char *str)
{
	int		n;
	char	*len;

	len = ft_strchr(str, '=');
	if (len)
		n = search_node_len(list, str, len - str);
	else
		n = search_node(list, str);
	if (n == -1)
		list_add_back(list, str);
	else if (len)
		replace_data_value((t_key_value *)(find_node_at(list, n)->data), len + 1);
}

void	builtin_export(char **argv)
{
	int		i;
	char	option;

	i = 1;
	if (argv[2] && argv[2][0] == '-' && argv[2][1])
	{
		option = is_optionvalid(argv[2]);
		if (option)
		{
			printf("builtin: export: -%c: invalid option\nexport: usage: export [name[=value] ...]\n", option);
			return ;
		}
		i++;
		printf("====export====\n"); // export 결과 출력
		return ;
	}
	while (argv[++i])
	{
		if (!is_namevalid(argv[i], ft_strchr(argv[i], '=') - argv[i]))
			printf("builtin: export: '%s': not a valid identifier\n", argv[i]);
		else
			builtin_export_2(argv[i]);
	}
	if (i == 2)
		printf("====export====\n"); // export 결과 출력
	printf("==result==\n");	// unset 결과 출력을 위한 임시 코드
	print_table(list); //
}

int	execute_builtin(char **argv)
{
	if (!ft_strncmp(argv[1], "echo", 5))
		builtin_echo(argv);
	else if (!ft_strncmp(argv[1], "pwd", 4))
		builtin_pwd(argv);
	else if (!ft_strncmp(argv[1], "cd", 3))
		builtin_cd(argv);
	else if (!ft_strncmp(argv[1], "env", 4))
		builtin_env(argv);
	else if (!ft_strncmp(argv[1], "unset", 6))
		builtin_unset(argv);
	else if (!ft_strncmp(argv[1], "export", 7))
		builtin_export(argv);
	// else if (!ft_strncmp(argv[1], "exit", 5))
	// 	return ;
	else
		return (1);
	return (0);
}
