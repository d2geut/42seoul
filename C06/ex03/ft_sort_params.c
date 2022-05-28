/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 21:49:54 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/28 21:53:03 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *src, char *dest)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if (src[i] > dest[i])
			return (1);
		else if (src[i] < dest[i])
			return (0);
		i++;
	}
	return (0);
}

int	ft_strlen3(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (++i < argc - 1)
	{
		j = i;
		while (++j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]))
			{
				temp = *(argv + i);
				*(argv + i) = *(argv + j);
				*(argv + j) = temp;
			}
		}
	}
	i = 0;
	while (++i < argc)
	{
		write(1, argv[i], ft_strlen3(argv[i]));
		write(1, "\n", 1);
	}
	return (0);
}
