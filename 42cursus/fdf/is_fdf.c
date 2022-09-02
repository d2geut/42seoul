/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_fdf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 16:14:04 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/01 12:57:19 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_fdf_2(char **arr, int *i)
{
	char	*word;

	word = arr[0];
	while (arr[++*i])
		word = arr[*i];
	if (ft_strncmp(word, "fdf", 4))
	{
		write(2, "File is not fdf.\n", 17);
		return (1);
	}
	return (0);
}

int	is_fdf(char *str)
{
	char	**arr;
	int		i;
	int		return_num;

	arr = ft_split(str, '.');
	if (!arr)
	{
		write(2, "malloc error.\n", 14);
		exit (1);
	}
	i = 0;
	if (!arr[0])
	{
		write(2, "File is not fdf.\n", 17);
		return_num = 1;
	}
	else
		return_num = is_fdf_2(arr, &i);
	ft_2darray_free(&arr);
	return (return_num);
}
