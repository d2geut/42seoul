/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:16:53 by hanryu            #+#    #+#             */
/*   Updated: 2023/04/09 16:41:50 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec.h"

typedef struct s_camera
{
	t_vec3	origin;
	int		image_x;
	int		image_y;
	double	viewport_width;
	double	viewport_height;
	double	focal_length;
	t_vec3	horizontal;
	t_vec3	vertical;
	t_vec3	leftbottom_point;
}	t_camera;

// typedef struct s_viewport
// {
// 	int	x;
// 	int	y;
// }	t_viewport;

t_camera	camera_set();

#endif