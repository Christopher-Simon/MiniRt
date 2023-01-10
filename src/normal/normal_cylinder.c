/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:56:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 07:07:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	cylinder_normal(t_obj *obj, t_tuple p)
{
	double	distance;

	distance = p.x * p.x + p.z * p.z;
	if (distance < 1 && p.y >= obj->height - N_EPSILON)
		return (set_vector(0, 1, 0));
	else if (distance < 1 && p.y <= N_EPSILON)
		return (set_vector(0, -1, 0));
	return (normalisation(vec(p.x, 0, p.z)));
	(void)obj;
}
