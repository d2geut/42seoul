/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_over_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:25:51 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/04 16:56:47 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	choose_rotate(t_data *data, int i, int j, int *oper)
{
	int	min;

	min = i + j - ft_min(i, j);
	*oper = 1;
	if (i + data->num_b - j < min)
	{
		min = i + data->num_b - j;
		*oper = 2;
	}
	if (data->num_a - i + j < min)
	{
		min = data->num_a - i + j;
		*oper = 3;
	}
	if (data->num_a - i + data->num_b - j - \
	ft_min(data->num_a - i, data->num_b - j) < min)
	{
		min = data->num_a - i + data->num_b - j - \
		ft_min(data->num_a - i, data->num_b - j);
		*oper = 4;
	}
	return (min);
}

static int	search_stack_b(t_stack *top_b, t_stack *a)
{
	t_stack	*temp;
	int		i;
	int		min;
	int		index;

	min = a->number - top_b->number;
	i = 1;
	index = 0;
	temp = top_b->next;
	while (temp)
	{
		if (((min < 0) && (0 < a->number - temp->number || \
		a->number - temp->number < min)) || (min > 0 && 0 < a->number - \
		temp->number && a->number - temp->number < min))
		{
			min = a->number - temp->number;
			index = i;
		}
		temp = temp->next;
		i++;
	}
	return (index);
}

void	search_stack_a(t_data *data, int *i_min, int *j_min, int *oper_min)
{
	t_stack	*temp;
	int		i;
	int		j;
	int		oper;
	int		min;

	min = choose_rotate(data, *i_min, *j_min, oper_min);
	temp = data->top_a->next;
	i = 1;
	while (temp)
	{
		j = search_stack_b(data->top_b, temp);
		if (choose_rotate(data, i, j, &oper) < min)
		{
			min = choose_rotate(data, i, j, &oper);
			*i_min = i;
			*j_min = j;
			*oper_min = oper;
		}
		temp = temp->next;
		i++;
	}
}

void	rot_stack_b(t_data *data, int max)
{
	t_stack	*temp;
	int		j;
	int		j_max;

	j_max = 0;
	temp = data->top_b->next;
	j = 1;
	while (temp)
	{
		if (max < temp->number)
		{
			max = temp->number;
			j_max = j;
		}
		temp = temp->next;
		j++;
	}
	j = ft_min(j_max, data->num_b - j_max);
	while (j--)
	{
		if (j_max < data->num_b - j_max)
			rotate_b(data);
		else
			r_rotate_b(data);
	}
}

void	argv_over_four(t_data *data)
{
	int	i;
	int	j;
	int	oper;

	push_b(data);
	if (data->num_a > 3)
		push_b(data);
	while (data->num_a > 3)
	{
		i = 0;
		j = search_stack_b(data->top_b, data->top_a);
		search_stack_a(data, &i, &j, &oper);
		push_a_to_b(data, i, j, oper);
	}
	rot_stack_b(data, data->top_b->number);
	stack_a_left(data);
}
