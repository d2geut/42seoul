/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 11:53:08 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 17:58:49 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_ray	ray_init(t_vec3 origin, t_vec3 dir)
{
	t_ray	ray;

	ray.origin = origin;
	ray.dir = vec_unit(dir);
	return (ray);
}

t_vec3	ray_at(t_ray *ray, double len)
{
	t_vec3	at;

	at = vec_plus(ray->origin, vec_mul(ray->dir, len));
	return (at);
}

t_ray	ray_camera(t_camera *cam, double x, double y)
{
	t_ray	ray;

	ray.origin = cam->origin;
	// leftbottom + x * hori + y * ver - origin
	ray.dir = vec_unit(vec_minus(vec_plus(cam->leftbottom_point, vec_plus(vec_mul(cam->horizontal, x), vec_mul(cam->vertical, y))), cam->origin));
	return (ray);
}

t_vec3	ray_color(t_ray *ray, t_sphere sp)
{
	t_vec3	color;
	double	t;

	if (hit_sphere(ray, sp))
		return (vec3(1, 0, 0));

	t = 0.5 * (ray->dir.y + 1.0);
	color.x = (1 - t) + t * 0.5;
	color.y = (1 - t) + t * 0.7;
	color.z = 1;
	return (color);
}
