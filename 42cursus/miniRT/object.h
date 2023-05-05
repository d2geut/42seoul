/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:05:29 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 16:27:34 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECT_H
# define OBJECT_H

# include "vec.h"

typedef struct s_sphere
{
	t_vec3	origin;
	double	r;
}	t_sphere;

t_sphere	sphere_init(t_vec3 origin, double r);

#endif