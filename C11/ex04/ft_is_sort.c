/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:29:44 by hanryu            #+#    #+#             */
/*   Updated: 2022/06/05 15:59:57 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	sortn(int *tab, int *i, int length, int (*f)(int, int))
{
	int	n;

	*i = 1;
	n = 0;
	while (!f(tab[*i - 1], tab[*i]) && *i < length)
		(*i)++;
	if (*i < length)
	{
		if (f(tab[*i - 1], tab[*i]) > 0)
			n = 1;
		else
			n = 0;
	}
	return (n);
}

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	n;

	if (length <= 1)
		return (1);
	n = sortn(tab, &i, length, f);
	while (i < length)
	{
		if (n)
		{
			if (f(tab[i - 1], tab[i]) < 0)
				return (0);
		}
		else
		{
			if (f(tab[i - 1], tab[i]) > 0)
				return (0);
		}
		i++;
	}
	return (1);
}
