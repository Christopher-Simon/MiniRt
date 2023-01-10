/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:01:08 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/02 01:01:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uv	sphere_map(t_tuple p)
{
	double	theta;
	t_tuple	vec;
	double	radius;
	double	phi;
	t_uv	res;

	theta = atan2(p.x, p.z);
	vec = set_vector(p.x, p.y, p.z);
	radius = magnitude(vec);
	phi = acos(p.y / radius);
	res.u = theta / (2 * N_PI);
	res.u = 1 - (res.u + 0.5);
	res.v = 1 - phi / N_PI;
	return (res);
}
