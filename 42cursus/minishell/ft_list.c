/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 18:58:10 by dyang             #+#    #+#             */
/*   Updated: 2023/02/07 17:13:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_llist	*init_list(void)
{
	t_llist	*list;

	list = (t_llist *)malloc(sizeof(t_llist));
	list->head = NULL;
	list->size = 0;
	return (list);
}

t_node	*init_node(char *data)
{
	t_node		*node;
	t_key_value	*data_s;
	char		*str;
	char		*dest;

	node = (t_node *)malloc(sizeof(t_node));
	data_s = (t_key_value *)malloc(sizeof(t_key_value));
	data_s->global = 0;
	data_s->value = NULL;
	str = ft_strchr(data, '=');
	if (str)
	{
		dest = (char *)malloc(sizeof(char) * (str - data + 1));
		ft_strlcpy(dest, data, str - data + 1);
		data_s->key = dest;
		data_s->value = ft_strdup(str + 1);
		data_s->global = 1;
	}
	else
		data_s->key = ft_strdup(data);
	node->data = data_s;
	node->prev = NULL;
	node->next = NULL;
	return (node);
}

int	is_empty(t_llist *list)
{
	if (list->head)
		return (0);
	else
		return (1);
}

void	free_list(t_llist **list)
{
	t_node	*node;
	t_node	*tmp;
	size_t	i;

	node = list[0]->head;
	i = 0;
	while (++i <= list[0]->size)
	{
		tmp = node->next;
		free(((t_key_value *)(node->data))->key);
		free(((t_key_value *)(node->data))->value);
		free(node->data);
		free(node);
		node = tmp;
	}
	free(list[0]);
}

void	list_add_back(t_llist *list, char *data)
{
	t_node	*node;

	node = init_node(data);
	if (list->head == NULL)
	{
		list->head = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->prev = list->head->prev;
		node->next = list->head;
		list->head->prev->next = node;
		list->head->prev = node;
	}
	list->size++;
}

void	list_remove_at(t_llist *list, int n)
{
	t_node	*node;

	node = list->head;
	if (n < 0 || n >= (int)(list->size))
		return ;
	if (n == 0)
	{
		node = list->head;
		list->head->next->prev = list->head->prev;
		list->head->prev->next = list->head->next;
		list->head = list->head->next;
	}
	else
	{
		node = find_node_at(list, n);
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(node->data);
	free(node);
	list->size--;
}

t_node	*find_node_at(t_llist *list, int n)
{
	t_node	*node;
	size_t	size;
	size_t	mid;
	size_t	i;

	node = list->head;
	size = list->size;
	mid = size / 2;
	i = 0;
	if ((size_t)n < mid)
	{
		while (i++ < (size_t)n)
			node = node->next;
	}
	else
	{
		while (i++ < size - n)
			node = node->prev;
	}
	return (node);
}

int	search_node(t_llist *list, char *data)
{
	t_node	*node;
	size_t	size;
	size_t	d_len;
	size_t	i;

	node = list->head;
	size = list->size;
	d_len = ft_strlen(data);
	i = 0;
	while (i < size)
	{
		if (!ft_strncmp(data, ((t_key_value *)(node->data))->key, d_len))
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

int	search_node_len(t_llist *list, char *data, size_t d_len)
{
	t_node	*node;
	size_t	size;
	size_t	i;

	node = list->head;
	size = list->size;
	i = 0;
	while (i < size)
	{
		if (!ft_strncmp(data, ((t_key_value *)(node->data))->key, d_len))
			return (i);
		node = node->next;
		i++;
	}
	return (-1);
}

void	print_table(t_llist *list)
{
	t_node	*node;
	size_t	size;
	size_t	i;

	node = list->head;
	size = list->size;
	i = 0;
	while (i < size)
	{
		if (((t_key_value *)(node->data))->global)
		{
			if (((t_key_value *)(node->data))->value)
			{
				printf("declare -x %s=\"%s\"\n", ((t_key_value *)(node->data))->key,
					((t_key_value *)(node->data))->value);
			}
			else
				printf("declare -x %s=\"\"\n", ((t_key_value *)(node->data))->key);
		}
		else
			printf("declare -x %s\n", ((t_key_value *)(node->data))->key);
		node = node->next;
		i++;
	}
}

void	env_table(t_llist *list)
{
	t_node	*node;
	size_t	size;
	size_t	i;

	node = list->head;
	size = list->size;
	i = 0;
	while (i < size)
	{
		if (((t_key_value *)(node->data))->global)
		{
			if (((t_key_value *)(node->data))->value)
			{
				printf("%s=%s\n", ((t_key_value *)(node->data))->key,
					((t_key_value *)(node->data))->value);
			}
			else
				printf("%s=\n", ((t_key_value *)(node->data))->key);
		}
		node = node->next;
		i++;
	}
}

void	replace_data_value(t_key_value *data_s, char *str)
{
	free(data_s->value);
	data_s->value = ft_strdup(str);
	data_s->global = 1;
}
