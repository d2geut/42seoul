/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:02:42 by hanryu            #+#    #+#             */
/*   Updated: 2022/07/06 18:43:18 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int			i;
	char		*dest_cpy;
	const char	*src_cpy;

	dest_cpy = (char *)dest;
	src_cpy = (const char *)src;
	if (dest - src <= 0)
	{
		i = 0;
		while (i < (int) n)
		{
			dest_cpy[i] = src_cpy[i];
			i++;
		}
	}
	else
	{
		i = n - 1;
		while (0 <= i)
		{
			dest_cpy[i] = src_cpy[i];
			i--;
		}
	}
	return (dest);
}
