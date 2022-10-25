/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:07:24 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/25 11:50:15 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstadd_back_stack(t_stack **lst, t_stack *new)
{
	t_stack	*temp;
	int		flag;

	flag = 0;
	if (!lst || !new)
		return (0);
	if (!(*lst))
	{
		*lst = new;
		return (0);
	}
	temp = *lst;
	if (temp->number == new->number)
		flag = 1;
	while (temp->next)
	{
		temp = temp->next;
		if (temp->number == new->number)
			flag = 1;
	}
	temp->next = new;
	return (flag);
}

void	ft_lstadd_front_stack(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	if (!lst || !new)
		return ;
	temp = *lst;
	*lst = new;
	new->next = temp;
}

void	ft_lstclear_stack(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!lst || !(*lst))
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

t_stack	*ft_lstlast_stack(t_stack *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

t_stack	*ft_lstnew_stack(int num)
{
	t_stack	*lst;

	lst = (t_stack *)malloc(sizeof(t_stack));
	if (!lst)
		return (NULL);
	lst->number = num;
	lst->next = NULL;
	return (lst);
}
