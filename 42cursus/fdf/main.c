/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 15:38:06 by hanryu            #+#    #+#             */
/*   Updated: 2022/08/26 16:49:14 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	is_fdf(char *str)
{
	char	**arr;
	char	*word;
	int		i;
	int		return_num;

	return_num = 0;
	arr = ft_split(str, '.');
	if (!arr)
	{
		write(2, "malloc error.\n", 14);
		return (1);
	}
	word = arr[0];
	i = 0;
	while (arr[++i])
		word = arr[i];
	if (ft_strncmp(word, "fdf", 4))
	{
		write(2, "File is not fdf.\n", 17);
		return_num = 1;
	}
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (return_num);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many files.\n", 16);
	else
	{
		if (is_fdf(argv[1]))
			return (0);
		fd = open(argv[1], O_RDONLY);
		if (fd >= 0)
			write(1, "IS FDF\n", 7);
		else
			write(2, "Cannot read file.\n", 18);
	}
	return (0);
}
