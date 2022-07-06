/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:14:50 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/25 21:27:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_length2(int *n, char *base)
{
	int	i;
	int	j;

	i = -1;
	while (base[*n])
	{
		if (base[*n] == '+' || base[*n] == '-' || base[*n] == ' ' || base[*n]
			== '\n' || base[*n] == '\t' || base[*n] == '\v' || base[*n]
			== '\f' || base[*n] == '\r')
			return (0);
		(*n)++;
	}
	if (*n <= 1)
		return (0);
	while (++i < *n - 1)
	{
		j = i + 1;
		while (j < *n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
	}
	return (1);
}

int	is_space2(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c
		== '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	is_plusminus2(char c, int *minus)
{
	if (c == '+' || c == '-')
	{
		if (c == '-')
			(*minus)++;
		return (1);
	}
	else
		return (0);
}

int	is_inbase(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	int	minus;
	int	num;
	int	n;

	minus = 0;
	num = 0;
	n = 0;
	if (base_length2(&n, base))
	{
		while (is_space2(*str))
			str++;
		while (is_plusminus2(*str, &minus))
			str++;
		while (is_inbase(*str, base) != -1)
		{
			num *= n;
			if (minus % 2)
				num -= is_inbase(*str, base);
			else
				num += is_inbase(*str, base);
			str++;
		}
	}
	return (num);
}
