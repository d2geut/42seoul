/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 12:40:24 by hanryu            #+#    #+#             */
/*   Updated: 2023/02/07 16:40:00 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

char	is_optionvalid(char *name)
{
	if (!name[0] || !name[1])
		return (0);
	if (name[1] == '-')
	{
		if (!name[2])
			return (0);
		else
			return ('-');
	}
	return (name[1]);
}

int	is_namevalid(char *name, int len)
{
	int	i;

	i = 0;
	while (name[i] && i < len)
	{
		if (!ft_isalnum(name[i]))
			if (name[i] != '_')
				return (0);
		if (i == 0)
			if (ft_isdigit(name[i]))
				return (0);
		i++;
	}
	return (1);
}
