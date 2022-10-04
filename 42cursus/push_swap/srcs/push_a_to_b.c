/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a_to_b.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 10:20:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/04 15:11:37 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ra_rb(t_data *data, int i, int j)
{
	int	a;
	int	b;
	int	c;

	c = ft_min(i, j);
	a = i - c;
	b = j - c;
	while (c--)
		rotate_r(data);
	while (a--)
		rotate_a(data);
	while (b--)
		rotate_b(data);
}

static void	ra_rrb(t_data *data, int i, int j)
{
	int	b;

	b = data->num_b - j;
	while (i--)
		rotate_a(data);
	while (b--)
		r_rotate_b(data);
}

static void	rra_rb(t_data *data, int i, int j)
{
	int	a;

	a = data->num_a - i;
	while (a--)
		r_rotate_a(data);
	while (j--)
		rotate_b(data);
}

static void	rra_rrb(t_data *data, int i, int j)
{
	int	a;
	int	b;
	int	c;

	c = ft_min(data->num_a - i, data->num_b - j);
	a = data->num_a - i - c;
	b = data->num_b - j - c;
	while (c--)
		r_rotate_r(data);
	while (a--)
		r_rotate_a(data);
	while (b--)
		r_rotate_b(data);
}

void	push_a_to_b(t_data *data, int i, int j, int oper)
{
	if (oper == 1)
		ra_rb(data, i, j);
	else if (oper == 2)
		ra_rrb(data, i, j);
	else if (oper == 3)
		rra_rb(data, i, j);
	else
		rra_rrb(data, i, j);
	push_b(data);
}
