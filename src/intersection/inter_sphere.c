/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:46:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:32:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

bool	sphere_intersection(t_obj *obj, t_ray ray)
{
	t_tuple	sp_to_ray;
	double	a;
	double	b;
	double	d;

	sp_to_ray = sub_tuples(ray.origin, pos(0, 0, 0));
	a = dot_prdt(ray.dir, ray.dir);
	b = 2 * dot_prdt(ray.dir, sp_to_ray);
	d = b * b - 4 * a * (dot_prdt(sp_to_ray, sp_to_ray) - 1);
	if (d < 0)
		return (false);
	d = sqrt(d);
	obj->hits[0] = (-b + d) / (2 * a);
	obj->hits[1] = (-b - d) / (2 * a);
	obj->in_object = is_in_object(obj->hits);
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	return (true);
}
