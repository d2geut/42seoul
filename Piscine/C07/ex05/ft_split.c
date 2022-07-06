/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 20:27:42 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/30 20:57:30 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_charset(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	arr_height(char *str, char *charset)
{
	int	i;
	int	flag;
	int	n;

	n = 0;
	i = 0;
	flag = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset) && !flag)
		{
			flag = 1;
			n++;
		}
		if (is_charset(str[i], charset))
			flag = 0;
		i++;
	}
	return (n);
}

int	arrlen(char *pt, char *charset)
{
	int	sum;

	sum = 0;
	while (*(pt + sum) && !is_charset(*(pt + sum), charset))
	{
		sum++;
	}
	return (sum);
}

void	into_arr(char *pt, char *charset, int k, char **arr)
{
	int	i;
	int	len;

	i = 0;
	len = arrlen(pt, charset);
	arr[k] = (char *)malloc(sizeof(char) * (len + 1));
	while (i < len)
	{
		arr[k][i] = *(pt + i);
		i++;
	}
	arr[k][i] = '\0';
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**arr;
	int		k;
	int		flag;

	arr = (char **)malloc(sizeof(char *) * (arr_height(str, charset) + 1));
	arr[arr_height(str, charset)] = 0;
	i = 0;
	k = 0;
	flag = 0;
	while (str[i])
	{
		if (!is_charset(str[i], charset) && !flag)
		{
			into_arr(&str[i], charset, k++, arr);
			flag = 1;
		}
		if (is_charset(str[i], charset))
			flag = 0;
		i++;
	}
	return (arr);
}
