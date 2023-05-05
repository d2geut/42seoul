/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hanryu <hanryu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:13:23 by hanryu            #+#    #+#             */
/*   Updated: 2023/05/05 16:40:44 by hanryu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "object.h"

t_sphere	sphere_init(t_vec3 origin, double r)
{
	t_sphere	sp;

	sp.origin = origin;
	sp.r = r;
	return (sp);
}
