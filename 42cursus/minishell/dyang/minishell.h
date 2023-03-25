/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dyang <dyang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:53:31 by dyang             #+#    #+#             */
/*   Updated: 2023/01/31 14:11:56 by dyang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "./libft/libft.h"

typedef struct s_node
{
	void			*data;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_llist
{
	t_node	*head;
	size_t	size;
}	t_llist;

typedef struct s_key_value
{
	char	*key;
	char	*value;
}	t_key_value;

t_llist	*init_list(void);
t_node	*init_node(char *data);
int		is_empty(t_llist *list);
void	free_list(t_llist **list);
void	list_add_back(t_llist *list, char *data);
void	list_remove_at(t_llist *list, int n);
t_node	*find_node_at(t_llist *list, int n);
int		search_node(t_llist *list, char *data);
void	print_table(t_llist *list);

#endif