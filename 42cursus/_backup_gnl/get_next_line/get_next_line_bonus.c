/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:14 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/14 10:59:59 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	*list_fd(t_list **list, int fd)
{
	t_list	*lst;
	t_list	*new;
	int		i;

	lst = *list;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->next = NULL;
	new->index = 0;
	i = 0;
	while (i <= BUFFER_SIZE)
		new->buff[i++] = 0;
	ft_lstadd_back(list, new);
	return (new);
}

int	check_line(int index, char *str)
{
	int	i;

	i = index;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*free_now(t_list **lst, t_list **now)
{
	t_list	*temp;

	if ((*lst)->fd == (*now)->fd)
		*lst = (*now)->next;
	else
	{
		temp = *lst;
		while (temp->next->fd != (*now)->fd && temp->next)
			temp = temp->next;
		temp->next = (*now)->next;
	}
	free(*now);
	*now = NULL;
	return (NULL);
}

char	*temp_front(char *str)
{
	int		len;
	int		i;
	char	*arr;

	len = check_line(0, str);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	i = 0;
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*now;
	char			*temp;
	char			*line;
	ssize_t			size;
	int				i;

	if (fd < 0)
		return (NULL);
	now = list_fd(&list, fd);
	if (!now)
		return (NULL);
	if (now->index < 0)
		return (free_now(&list, &now));
	temp = ft_strjoin("", now, BUFFER_SIZE + 1, 0);
	if (!temp)
		return (free_now(&list, &now));
	size = 1;
	while (size >= 0)
	{
		if (check_line(0, temp))
		{
			line = temp_front(temp);
			free(temp);
			now->index = check_line(now->index, now->buff);
			return (line);
		}
		i = 0;
		while (i <= BUFFER_SIZE)
			now->buff[i++] = 0;
		size = read(fd, now->buff, BUFFER_SIZE);
		if (size < 0)
		{
			free(temp);
			return (free_now(&list, &now));
		}
		if (size == 0)
			break ;
		now->index = 0;
		temp = ft_strjoin(temp, now, size, 1);
		if (!temp)
			return (free_now(&list, &now));
	}
	if (!temp[0])
	{
		free(temp);
		return (free_now(&list, &now));
	}
	now->index = -1;
	return (temp);
}
