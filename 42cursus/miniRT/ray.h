/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:50:53 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 17:58:00 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "vec.h"
# include "camera.h"
# include "object.h"

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

t_ray	ray_init(t_vec3 origin, t_vec3 dir);
t_vec3	ray_at(t_ray *ray, double len);
t_ray	ray_camera(t_camera *cam, double x, double y);
t_vec3	ray_color(t_ray *ray, t_sphere sp);

int		hit_sphere(t_ray *ray, t_sphere sp);

#endif