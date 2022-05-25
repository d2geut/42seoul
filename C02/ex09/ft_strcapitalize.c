/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 20:14:19 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/23 21:15:28 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	array(char *str, int i)
{
	if (!('a' <= str[i - 1] && str[i - 1] <= 'z'))
		if (!('A' <= str[i - 1] && str[i - 1] <= 'Z'))
			if (!('0' <= str[i - 1] && str[i - 1] <= '9'))
				if ('a' <= str[i] && str[i] <= 'z')
					str[i] -= 32;
	if (('0' <= str[i - 1] && str[i - 1] <= 'z'))
		if (!(91 <= str[i - 1] && str[i - 1] <= 96))
			if (!(58 <= str[i - 1] && str[i - 1] <= 64))
				if ('A' <= str[i] && str[i] <= 'Z')
					str[i] += 32;
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	if ('a' <= str[0] && str[0] <= 'z')
		str[0] -= 32;
	i = 0;
	while (str[i])
	{
		array(str, i);
		i++;
	}
	return (str);
}
