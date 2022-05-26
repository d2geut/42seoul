/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 20:01:32 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/25 17:24:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_space(char c)
{
	if (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c
		== '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	is_plusminus(char c, int *minus)
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

int	ft_atoi(char *str)
{
	int	i;
	int	minus;
	int	num;

	i = 0;
	minus = 0;
	num = 0;
	while (is_space(str[i]))
		i++;
	while (is_plusminus(str[i], &minus))
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		num *= 10;
		if (minus % 2)
			num -= str[i] - 48;
		else
			num += str[i] - 48;
		i++;
	}
	return (num);
}
