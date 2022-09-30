/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_over_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 12:25:51 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/30 12:59:36 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	argv_over_four(t_data *data)
{
	t_stack	*temp;
	
	push_b(data);
	push_b(data);
	while (data->num_a)
	{
		temp = data->top_a;
		while (temp)
		{
			
		}
	}
}