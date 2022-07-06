/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:33:12 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/05 09:37:11 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doop.h"

long	operator(char **argv, int value1, int value2)
{
	long	num;

	num = 0;
	if (argv[2][0] == '+' && argv[2][1] == 0)
		num = value1 + value2;
	else if (argv[2][0] == '-' && argv[2][1] == 0)
		num = value1 - value2;
	else if (argv[2][0] == '*' && argv[2][1] == 0)
		num = value1 * value2;
	else if (argv[2][0] == '/' && argv[2][1] == 0)
		num = value1 / value2;
	else if (argv[2][0] == '%' && argv[2][1] == 0)
		num = value1 % value2;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	return (num);
}

int	main(int argc, char **argv)
{
	int		value1;
	int		value2;
	long	num;

	if (argc != 4)
		return (0);
	value1 = ft_atoi(argv[1]);
	value2 = ft_atoi(argv[3]);
	if ((argv[2][0] == '/' || argv[2][0] == '%') && argv[2][1] == 0)
	{
		if (value2 == 0 && argv[2][0] == '/')
		{
			write(1, "Stop : division by zero\n", 24);
			return (0);
		}
		else if (value2 == 0 && argv[2][0] == '%')
		{
			write(1, "Stop : modulo by zero\n", 22);
			return (0);
		}
	}
	num = operator(argv, value1, value2);
	print_nbr(num);
	write(1, "\n", 1);
	return (0);
}
