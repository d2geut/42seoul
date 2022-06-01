/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 10:29:47 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/31 13:08:46 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	strsize(int size, char **strs)
{
	int	sum;
	int	i;
	int	j;

	i = 0;
	sum = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			sum++;
		}
		i++;
	}
	return (sum);
}

int	size_sep(char *sep)
{
	int	sum;

	sum = 0;
	while (sep[sum])
	{
		sum++;
	}
	return (sum);
}

void	arr_in(int size, char **strs, char *sep, char *arr)
{
	int	i;
	int	j;
	int	n;

	i = 0;
	n = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			arr[n++] = strs[i][j++];
		j = 0;
		if (!(i == size - 1))
			while (sep[j])
				arr[n++] = sep[j++];
		i++;
	}
	arr[n] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*arr;

	if (size <= 0)
	{
		arr = (char *)malloc(1);
		arr[0] = '\0';
		return (arr);
	}
	arr = (char *)malloc(strsize(size, strs) + size_sep(sep) * (size - 1) + 1);
	arr_in(size, strs, sep, arr);
	return (arr);
}
