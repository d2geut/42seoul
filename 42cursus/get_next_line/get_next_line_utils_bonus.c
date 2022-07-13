/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 11:12:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/13 14:22:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, t_list *now, int size, int flag)
{
	int		i;
	int		j;
	int		len;
	char	*arr;

	len = size - now->index;
	arr = (char *)malloc(sizeof(char) * (ft_strlen(s1) + len + 1));
	if (!arr)
		return (NULL);
	i = -1;
	while (++i < ft_strlen(s1))
		arr[i] = s1[i];
	j = now->index + 1;
	while (j < size)
		arr[i++] = now->buff[j++];
	arr[i] = '\0';
	if (flag)
	{
		free(s1);
		s1 = NULL;
	}
	return (arr);
}
