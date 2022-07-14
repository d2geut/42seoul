/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/14 19:06:28 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *now)
{
	t_list	*temp;

	if (!(*lst))
	{
		*lst = now;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = now;
}

int	ft_strlen_and(char *str, int flag)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (flag)
			str[i] = 0;
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, t_list *now, int size, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*arr;

	len = ft_strlen_and(s1, 0);
	arr = (char *)malloc(sizeof(char) * (len + size - now->index + 1));
	if (!arr)
	{
		free(s1);
		s1 = NULL;
		return (NULL);
	}
	i = -1;
	while (++i < len)
		arr[i] = s1[i];
	j = now->index;
	while (j <= size)
		arr[i++] = now->buff[j++];
	if (flag)
	{
		free(s1);
		s1 = NULL;
	}
	return (arr);
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
