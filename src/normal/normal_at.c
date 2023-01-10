/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:57:05 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 18:01:31 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	normal_at(t_obj *obj, t_tuple world_pt, t_ray ray)
{
	t_tuple	obj_pt;
	t_tuple	obj_normal;
	t_tuple	wd_normal;

	obj_pt = prod_matx_tuple(obj->m_inverse, world_pt);
	obj_normal = obj->normal_fnct(obj, obj_pt);
	wd_normal = prod_matx_tuple(transpose_matrice(obj->m_inverse), obj_normal);
	wd_normal.w = 0;
	wd_normal = normalisation(wd_normal);
	if (obj->sh == E_PLANE && dot_prdt(wd_normal, ray.dir) < N_EPSILON)
		return (negating_tuple(wd_normal));
	if (obj->sh == E_CUBOID && dot_prdt(wd_normal, ray.dir) < N_EPSILON)
		return (negating_tuple(wd_normal));
	if (obj->in_object)
		return (negating_tuple(wd_normal));
	return (wd_normal);
}
