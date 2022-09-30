/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:49:47 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/23 12:51:08 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	r_rotate_a(t_data *data)
{
	t_stack	*last;

	if (!data->top_a)
		return ;
	last = ft_lstlast_stack(data->top_a);
	last->next = data->top_a;
	data->top_a = last;
	write(1, "ra\n", 3);
}