/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 09:29:42 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/30 12:29:52 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static int	num_error(char *str, long long *num)
{
	int	i;
	int	minus;

	*num = 0;
	i = 0;
	minus = 1;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = -1;
	while ('0' <= str[i] && str[i] <= '9')
	{
		*num = *num * 10;
		if (minus > 0)
			*num += str[i] - '0';
		else
			*num -= str[i] - '0';
		if (INT_MAX < (*num) || (*num) < INT_MIN)
			return (1);
		i++;
	}
	if (str[i])
		return (1);
	return (0);
}

static void	split_num(char *str, t_data *data)
{
	char		**arr;
	int			i;
	long long	num;

	arr = ft_split(str, ' ');
	if (!arr)
		write_error();
	i = 0;
	while (arr[i])
	{
		if (num_error(arr[i], &num))
		{
			ft_2darray_free(&arr);
			write_error();
		}
		if (ft_lstadd_back_stack(&(data->top_a), ft_lstnew_stack(num)))
		{
			ft_2darray_free(&arr);
			ft_lstclear_stack(&(data->top_a));
			write_error();
		}
		i++;
	}
	ft_2darray_free(&arr);
}

static void	stack_num(int argc, char **argv, t_data *data)
{
	long long	num;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (num_error(argv[i], &num))
			write_error();
		if (ft_lstadd_back_stack(&(data->top_a), ft_lstnew_stack(num)))
		{
			ft_lstclear_stack(&(data->top_a));
			write_error();
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_stack	*temp;

	if (argc < 2)
		write_error();
	else if (argc == 2)
		split_num(argv[1], &data);
	else
		stack_num(argc, argv, &data);
	data.num_a = ft_lstsize_stack(data.top_a);
	data.num_b = 0;
	if (data.num_a < 4)
		argv_two_three(&data);
	else
		argv_over_four(&data);

	printf("---sort---\n");
	temp = data.top_a;
	while (temp)
	{
		printf("%d\n", temp->number);
		temp = temp->next;
	}
	return (0);
}
