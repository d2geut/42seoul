/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:49:47 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/04 17:01:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*lstlast_before(t_stack *lst)
{
	t_stack	*temp;

	temp = lst;
	while (lst && lst->next)
	{
		lst = lst->next;
		if (!lst->next)
			break ;
		temp = lst;
	}
	return (temp);
}

void	r_rotate_a(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;

	if (!data->top_a || !data->top_a->next)
		return ;
	temp = lstlast_before(data->top_a);
	last = temp->next;
	last->next = data->top_a;
	data->top_a = last;
	temp->next = NULL;
	write(1, "rra\n", 4);
}

void	r_rotate_b(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;

	if (!data->top_b || !data->top_b->next)
		return ;
	temp = lstlast_before(data->top_b);
	last = temp->next;
	last->next = data->top_b;
	data->top_b = last;
	temp->next = NULL;
	write(1, "rrb\n", 4);
}

void	r_rotate_r(t_data *data)
{
	t_stack	*temp;
	t_stack	*last;

	if (!data->top_a || !data->top_a->next || \
	!data->top_b || !data->top_b->next)
		return ;
	temp = lstlast_before(data->top_a);
	last = temp->next;
	last->next = data->top_a;
	data->top_a = last;
	temp->next = NULL;
	temp = lstlast_before(data->top_b);
	last = temp->next;
	last->next = data->top_b;
	data->top_b = last;
	temp->next = NULL;
	write(1, "rrr\n", 4);
}
