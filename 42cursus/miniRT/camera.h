/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 05:16:53 by hanryu            #+#    #+#             */
/*   Updated: 2023/03/26 06:04:48 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
# define CAMERA_H

# include "vec.h"

typedef struct s_camera
{
	t_vec3	origin;
	int		viewport_x;
	int		viewport_y;
	int		focal_length;
}	t_camera;

t_camera	camera()

#endif