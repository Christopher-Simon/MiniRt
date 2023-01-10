/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:10:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/03 05:45:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	plane_intersection(t_obj *obj, t_ray ray)
{
	if (ft_fabs(ray.dir.y) < N_EPSILON)
		return (false);
	obj->hit = -ray.origin.y / ray.dir.y;
	if (obj->hit > 0)
		return (true);
	obj->hit = INFINITY;
	return (false);
}
