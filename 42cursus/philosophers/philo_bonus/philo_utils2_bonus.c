/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 10:04:40 by hanryu            #+#    #+#             */
/*   Updated: 2023/01/04 10:05:13 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len_1;
	size_t	len_2;
	size_t	i;
	size_t	j;
	char	*arr;

	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	arr = (char *)malloc(sizeof(char) * (len_1 + len_2 + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len_1)
	{
		arr[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		arr[i++] = s2[j++];
	arr[i] = '\0';
	return (arr);
}

static int	str_len(int n)
{
	if (!n)
		return (0);
	return (1 + str_len(n / 10));
}

char	*ft_itoa(int n)
{
	int		buff;
	int		minus;
	char	*str;

	buff = 0;
	minus = 1;
	if (n <= 0)
		buff++;
	if (n < 0)
		minus = -1;
	buff += str_len(n);
	str = (char *)malloc(sizeof(char) * (buff + 1));
	if (!str)
		return (NULL);
	str[buff--] = '\0';
	if (minus < 0 && n)
		str[0] = '-';
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[buff--] = minus * (n % 10) + '0';
		n = n / 10;
	}
	return (str);
}
