/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_stack_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:52:29 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/25 12:40:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	swap_a(t_data *data)
{
	t_stack	*temp;
	t_stack	*next;

	if (!data->top_a)
		return ;
	if (!data->top_a->next)
		return ;
	temp = data->top_a;
	data->top_a = data->top_a->next;
	next = data->top_a->next;
	data->top_a->next = temp;
	temp->next = next;
}

void	swap_b(t_data *data)
{
	t_stack	*temp;
	t_stack	*next;

	if (!data->top_b)
		return ;
	if (!data->top_b->next)
		return ;
	temp = data->top_b;
	data->top_b = data->top_b->next;
	next = data->top_b->next;
	data->top_b->next = temp;
	temp->next = next;
}

void	swap_s(t_data *data)
{
	swap_a(data);
	swap_b(data);
}

void	push_a(t_data *data)
{
	t_stack	*temp;

	if (!data->top_b)
		return ;
	temp = data->top_b;
	data->top_b = data->top_b->next;
	ft_lstadd_front_stack(&data->top_a, temp);
	data->num_a += 1;
	data->num_b -= 1;
}

void	push_b(t_data *data)
{
	t_stack	*temp;

	if (!data->top_a)
		return ;
	temp = data->top_a;
	data->top_a = data->top_a->next;
	ft_lstadd_front_stack(&data->top_b, temp);
	data->num_a -= 1;
	data->num_b += 1;
}
