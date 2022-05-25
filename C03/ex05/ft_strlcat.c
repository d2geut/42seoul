/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 09:59:43 by hanryu            #+#    #+#             */
/*   Updated: 2022/05/24 19:21:58 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	sum;
	int				i;

	a = 0;
	b = 0;
	i = 0;
	while (dest[a])
		a++;
	while (src[b])
		b++;
	sum = a + b;
	if (size == 0)
		return (b + size);
	while (a < size - 1 && src[i])
	{
		dest[a++] = src[i++];
	}
	dest[a] = '\0';
	if (size < a)
		return (b + size);
	else
		return (sum);
}
