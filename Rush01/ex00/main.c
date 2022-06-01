/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 09:26:30 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/28 14:57:22 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	make_array(int *input);

int	main(int argc, char **argv)
{
	int	i;
	int	n;
	int	input[17];

	if (argc == 2)
	{
		i = 0;
		n = 0;
		while (argv[1][i])
		{
			if (!(argv[1][i] == ' '))
				input[n++] = argv[1][i] - '0';
			if (n > 16)
			{
				write(2, "Error\n", 6);
				return (0);
			}
			i++;
		}
		input[16] = -1;
		make_array(input);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
