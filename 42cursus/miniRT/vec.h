/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 02:05:18 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 17:00:40 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <math.h>

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

t_vec3	vec3(double x, double y, double z);
double	vec_len(t_vec3 vec);
t_vec3	vec_unit(t_vec3 vec);
t_vec3	vec_plus(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_minus(t_vec3 vec1, t_vec3 vec2);
t_vec3	vec_mul(t_vec3 vec, double t);
t_vec3	vec_div(t_vec3 vec, double t);
double	vec_dot(t_vec3 vec1, t_vec3 vec2);

#endif