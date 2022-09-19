/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_color_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:36:10 by hanryu            #+#    #+#             */
/*   Updated: 2022/09/19 13:40:54 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

static int	get_r(int rgb)
{
	return (0xFF & (rgb >> 16));
}

static int	get_g(int rgb)
{
	return (0xFF & (rgb >> 8));
}

static int	get_b(int rgb)
{
	return (0xFF & rgb);
}

int	pixel_color(t_map start, t_map end, int d, int i)
{
	int	red;
	int	green;
	int	blue;

	red = (int)(get_r(start.color) * ((double)i / d) + \
	get_r(end.color) * (1 - ((double)i / d)));
	green = (int)(get_g(start.color) * ((double)i / d) + \
	get_g(end.color) * (1 - ((double)i / d)));
	blue = (int)(get_b(start.color) * ((double)i / d) + \
	get_b(end.color) * (1 - ((double)i / d)));
	return (create_rgb(red, green, blue));
}
