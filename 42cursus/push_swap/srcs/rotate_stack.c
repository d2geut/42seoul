/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:41:44 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/04 17:01:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data)
{
	t_stack	*last;

	if (!data->top_a || !data->top_a->next)
		return ;
	last = ft_lstlast_stack(data->top_a);
	last->next = data->top_a;
	data->top_a = data->top_a->next;
	last->next->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	t_stack	*last;

	if (!data->top_b || !data->top_b->next)
		return ;
	last = ft_lstlast_stack(data->top_b);
	last->next = data->top_b;
	data->top_b = data->top_b->next;
	last->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_r(t_data *data)
{
	t_stack	*last;

	if (!data->top_a || !data->top_b || \
	!data->top_a->next || !data->top_b->next)
		return ;
	last = ft_lstlast_stack(data->top_a);
	last->next = data->top_a;
	data->top_a = data->top_a->next;
	last->next->next = NULL;
	last = ft_lstlast_stack(data->top_b);
	last->next = data->top_b;
	data->top_b = data->top_b->next;
	last->next->next = NULL;
	write(1, "rr\n", 3);
}
