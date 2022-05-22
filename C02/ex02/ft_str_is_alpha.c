/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 14:07:35 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/22 18:30:09 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	if (str[0])
	{
		while (str[i])
		{
			if ('A' <= str[i] && str[i] <= 'Z')
				return (1);
			else if ('a' <= str[i] && str[i] <= 'z')
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}
