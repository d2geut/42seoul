/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_two_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 11:51:39 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/04 17:14:51 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	argv_three(t_data *data, int two, int three)
{
	if (two < 0 && three < 0)
	{
		if (two < three)
		{
			swap_a(data);
			rotate_a(data);
		}
	}
	else if (two > 0 && three < 0)
		swap_a(data);
	else if (two < 0 && three > 0)
		r_rotate_a(data);
	else if (two > 0 && three > 0)
	{
		if (two > three)
			rotate_a(data);
		else
		{
			swap_a(data);
			r_rotate_a(data);
		}
	}
}

void	argv_two_three(t_data *data)
{
	if (data->num_a == 2)
	{
		if (data->top_a->number > data->top_a->next->number)
			swap_a(data);
	}
	else if (data->num_a > 2)
	{
		argv_three(data, data->top_a->number - data->top_a->next->number, \
		data->top_a->number - data->top_a->next->next->number);
	}
}

static void	push_b_to_a(t_data *data, int num)
{
	while (data->num_b)
	{
		if (data->top_b->number < num)
			break ;
		push_a(data);
	}
}

void	stack_a_left(t_data *data)
{
	int	small;
	int	mid;
	int	big;

	argv_three(data, data->top_a->number - data->top_a->next->number, \
	data->top_a->number - data->top_a->next->next->number);
	small = data->top_a->number;
	mid = data->top_a->next->number;
	big = data->top_a->next->next->number;
	push_b_to_a(data, big);
	r_rotate_a(data);
	push_b_to_a(data, mid);
	r_rotate_a(data);
	push_b_to_a(data, small);
	r_rotate_a(data);
	while (data->num_b)
		push_a(data);
}
