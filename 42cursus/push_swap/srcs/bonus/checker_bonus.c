/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 14:52:47 by hanryu            #+#    #+#             */
/*   Updated: 2022/10/24 12:34:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static int	execute_command(t_data *data, char *line)
{
	if (!ft_memcmp(line, "sa\n", 4))
		swap_a(data);
	else if (!ft_memcmp(line, "sb\n", 4))
		swap_b(data);
	else if (!ft_memcmp(line, "ss\n", 4))
		swap_s(data);
	else if (!ft_memcmp(line, "pa\n", 4))
		push_a(data);
	else if (!ft_memcmp(line, "pb\n", 4))
		push_b(data);
	else if (!ft_memcmp(line, "ra\n", 4))
		rotate_a(data);
	else if (!ft_memcmp(line, "rb\n", 4))
		rotate_b(data);
	else if (!ft_memcmp(line, "rr\n", 4))
		rotate_r(data);
	else if (!ft_memcmp(line, "rra\n", 5))
		r_rotate_a(data);
	else if (!ft_memcmp(line, "rrb\n", 5))
		r_rotate_b(data);
	else if (!ft_memcmp(line, "rrr\n", 5))
		r_rotate_r(data);
	else
		return (1);
	return (0);
}

static int	stack_a_sorted(t_data *data)
{
	t_stack	*temp;

	temp = data->top_a;
	if (!temp)
		return (0);
	while (temp->next)
	{
		if (temp->number > temp->next->number)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	enter_command(t_data *data)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (execute_command(data, line))
		{
			ft_free((void **)&line);
			ft_lstclear_stack(&data->top_a);
			ft_lstclear_stack(&data->top_b);
			write_error();
		}
		ft_free((void **)&line);
	}
	if (!data->num_b && !stack_a_sorted(data))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}
