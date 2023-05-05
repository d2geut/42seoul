/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_object.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:58:04 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 17:58:24 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

int	hit_sphere(t_ray *ray, t_sphere sp)
{
	double	a;
	double	b;
	double	c;
	t_vec3	oc;

	// 판별식 b^2-4ac이 0보다 크면 구를 hit하고, 작으면 x
	oc = vec_minus(ray->origin, sp.origin);
	a = vec_dot(ray->dir, ray->dir);
	b = 2 * vec_dot(ray->dir, oc);
	c = vec_dot(oc, oc) - pow(sp.r, 2);
	if (pow(b, 2) - 4 * a * c > 0)
		return (1);
	else
		return (0);
}
