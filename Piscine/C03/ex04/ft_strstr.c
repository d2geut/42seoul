/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:30:59 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/24 09:55:41 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	search(char *str, char *to_find, int n2, int i2)
{
	int	j;

	j = 0;
	while (j < n2)
	{
		if (to_find[j] != str[i2])
			return (0);
		j++;
		i2++;
	}
	return (1);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	n1;
	int	n2;
	int	i;

	n1 = 0;
	n2 = 0;
	while (str[n1])
		n1++;
	while (to_find[n2])
		n2++;
	i = 0;
	while (i + n2 <= n1)
	{
		if (search(str, to_find, n2, i))
			return (str + i);
		i++;
	}
	return (0);
}
