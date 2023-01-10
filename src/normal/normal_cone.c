/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:06:52 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 07:06:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	cone_normal(t_obj *obj, t_tuple p)
{
	double	y;
	double	distance;

	distance = p.x * p.x + p.z * p.z;
	y = sqrt(p.x * p.x + p.z * p.z);
	if (p.y > 0)
		y = -y;
	if (distance < 1 && p.y >= obj->height - N_EPSILON)
		return (set_vector(0, 1, 0));
	return (normalisation(vec(p.x, y, p.z)));
}
