/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_cuboid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:37:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 07:07:04 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static double	max(double x, double y, double z)
{
	if (x >= y && x >= z)
		return (x);
	if (y >= z && y >= x)
		return (y);
	if (z >= x && z >= y)
		return (z);
	return (INFINITY);
}

t_tuple	cuboid_normal(t_obj *obj, t_tuple p)
{
	double	m;

	m = max(fabs(p.x), fabs(p.y), fabs(p.z));
	if (m == fabs(p.x))
		return (normalisation(set_vector(p.x, 0, 0)));
	else if (m == fabs(p.y))
		return (normalisation(set_vector(0, p.y, 0)));
	return (normalisation(set_vector(0, 0, p.z)));
	(void)obj;
}
