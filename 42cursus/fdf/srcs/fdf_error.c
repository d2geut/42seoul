/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 10:59:24 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 14:29:07 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fdf_error(int n)
{
	if (n == 1)
		write(2, "Out of memory.\n", 15);
	else if (n == 2)
		write(2, "File is not fdf.\n", 17);
	else if (n == 3)
		write(2, "Include wrong format word.\n", 27);
	else if (n == 4)
		write(2, "Include wrong line length.\n", 27);
	exit (1);
}
