/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 06:10:17 by hanryu            #+#    #+#             */
/*   Updated: 2023/04/09 16:52:04 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "camera.h"
#include "vec.h"

t_camera	camera_set()
{
	t_camera	camera;

	camera.origin = vec3(0, 0, 0);
	camera.image_x = 2000;
	camera.image_y = 1000;
	camera.viewport_width = 2;
	camera.viewport_height = 1;
	camera.focal_length = 1;
	camera.horizontal = vec3(camera.viewport_width, 0, 0);
	camera.vertical = vec3(0, camera.viewport_height, 0);
	camera.leftbottom_point = vec_minus(camera.origin, \
	vec_plus(vec_plus(vec_div(camera.horizontal, 2), vec_div(camera.vertical, 2)), \
	vec3(0, 0, camera.focal_length)));
	return (camera);
}
