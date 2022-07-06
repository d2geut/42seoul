/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 12:44:03 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/30 17:07:50 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	base_print(int n, int num)
{
	if (num < n)
		return (1);
	else
		return (base_print(n, num / n) + 1);
}

char	*ft_putnbr_base(long num, char *base, int minus)
{
	int		n;
	int		len;
	char	*arr;

	n = 0;
	len = 0;
	while (base[n])
		n++;
	len = base_print(n, num);
	if (minus % 2 && num != 0)
		len++;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (minus % 2 && num != 0)
		arr[0] = '-';
	arr[len] = '\0';
	if (num == 0)
		arr[0] = base[0];
	while (num)
	{
		arr[--len] = base[num % n];
		num = num / n;
	}
	return (arr);
}
