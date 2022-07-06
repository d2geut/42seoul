/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 13:16:52 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/25 21:29:22 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	base_length(int *n, char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[*n])
	{
		if (base[*n] == '+' || base[*n] == '-')
			return (0);
		(*n)++;
	}
	if (*n <= 1)
		return (0);
	while (i < *n - 1)
	{
		j = i + 1;
		while (j < *n)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	base_print(int n, char *base, int num)
{
	if (num < n)
		write(1, base + num, 1);
	else
	{
		base_print(n, base, num / n);
		write(1, base + (num % n), 1);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	n;
	int	err;

	n = 0;
	if (base_length(&n, base))
	{
		if (nbr == -2147483648)
		{
			err = nbr % n;
			err = -err;
			nbr = nbr / n;
			nbr = -nbr;
			write(1, "-", 1);
			base_print(n, base, nbr);
			write(1, &base[err], 1);
		}
		else if (nbr < 0)
		{
			write(1, "-", 1);
			nbr = -nbr;
			base_print(n, base, nbr);
		}
		else
			base_print(n, base, nbr);
	}
}
