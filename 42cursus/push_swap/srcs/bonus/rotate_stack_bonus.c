/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:41:44 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/25 12:39:02 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate_a(t_data *data)
{
	t_stack	*last;

	if (!data->top_a || !data->top_a->next)
		return ;
	last = ft_lstlast_stack(data->top_a);
	last->next = data->top_a;
	data->top_a = data->top_a->next;
	last->next->next = NULL;
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
}

void	rotate_r(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
