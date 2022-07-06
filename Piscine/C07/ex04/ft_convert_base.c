/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:43:57 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/30 16:59:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_putnbr_base(long nbr, char *base, int minus);

int	base_length(char *base)
{
	int	i;
	int	j;
	int	n;

	i = -1;
	n = -1;
	while (base[++n])
	{
		if (base[n] == '+' || base[n] == '-' || base[n] == ' ' || base[n]
			== '\n' || base[n] == '\t' || base[n] == '\v' || base[n]
			== '\f' || base[n] == '\r')
			return (0);
	}
	if (n <= 1)
		return (0);
	while (++i < n - 1)
	{
		j = i;
		while (++j < n)
		{
			if (base[i] == base[j])
				return (0);
		}
	}
	return (1);
}

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

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		minus;
	long	num;
	int		n;

	minus = 0;
	num = 0;
	n = 0;
	while (base_from[n])
		n++;
	if (!(base_length(base_from) && base_length(base_to)))
		return (0);
	while (is_space(*nbr))
		nbr++;
	while (is_plusminus(*nbr, &minus))
		nbr++;
	while (is_inbase(*nbr, base_from) != -1)
	{
		num *= n;
		num += is_inbase(*nbr, base_from);
		nbr++;
	}
	return (ft_putnbr_base(num, base_to, minus));
}
