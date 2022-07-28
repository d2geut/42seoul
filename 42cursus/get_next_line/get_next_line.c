/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:14 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/15 15:46:10 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_list	*list_fd(t_list **list, int fd)
{
	t_list		*lst;
	t_list		*now;
	long long	i;

	lst = *list;
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	now = (t_list *)malloc(sizeof(t_list));
	if (!now)
		return (NULL);
	now->fd = fd;
	now->next = NULL;
	now->index = 0;
	i = 0;
	while (i <= BUFFER_SIZE)
		now->buff[i++] = 0;
	ft_lstadd_back(list, now);
	return (now);
}

static char	*temp_front(char *str)
{
	int		len;
	int		i;
	char	*arr;

	len = check_line(0, str);
	arr = (char *)malloc(sizeof(char) * (len + 1));
	if (!arr)
	{
		free(str);
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	free(str);
	return (arr);
}

static int	check_size(ssize_t size, char **temp)
{
	if (size < 0)
	{
		free(*temp);
		*temp = NULL;
		return (0);
	}
	return (2);
}

static int	check_buff(char **temp, char **line, int fd, t_list *now)
{
	ssize_t	size;

	while (1)
	{
		if (check_line(0, *temp))
		{
			*line = temp_front(*temp);
			if (!(*line))
				return (0);
			now->index = check_line(now->index, now->buff);
			return (1);
		}
		(void)ft_strlen_and(now->buff, 1);
		size = read(fd, now->buff, BUFFER_SIZE);
		if (size <= 0)
			return (check_size(size, temp));
		now->index = 0;
		*temp = ft_strjoin(*temp, now, size, 1);
		if (!(*temp))
			return (0);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*now;
	char			*temp;
	char			*line;
	int				flag;

	now = list_fd(&list, fd);
	if (!now)
		return (NULL);
	temp = ft_strjoin("", now, BUFFER_SIZE + 1, 0);
	if (!temp)
		return (free_now(&list, &now));
	flag = check_buff(&temp, &line, fd, now);
	if (flag == 1)
		return (line);
	else if (flag == 0)
		return (free_now(&list, &now));
	if (!temp[0])
	{
		free(temp);
		return (free_now(&list, &now));
	}
	return (temp);
}
