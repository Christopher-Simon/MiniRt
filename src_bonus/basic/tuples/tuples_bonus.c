/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:50:55 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/14 01:11:57 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	magnitude(t_tuple t)
{
	double	x;
	double	y;
	double	z;
	double	w;
	double	res;

	if (t.w)
		log_printf("mag : Not a vector\n");
	x = t.x * t.x;
	y = t.y * t.y;
	z = t.z * t.z;
	w = t.w * t.w;
	res = x + y + z + w;
	return (sqrt(res));
}

t_tuple	normalisation(t_tuple t)
{
	t_tuple	res;
	double	mag;

	if (t.w)
		log_printf("normal : Not a vector\n");
	mag = 1 / magnitude(t);
	res.x = t.x * mag;
	res.y = t.y * mag;
	res.z = t.z * mag;
	res.w = t.w * mag;
	return (res);
}

double	dot_prdt(t_tuple t1, t_tuple t2)
{
	double	res;

	res = t1.x * t2.x;
	res += t1.y * t2.y;
	res += t1.z * t2.z;
	res += t1.w * t2.w;
	return (res);
}

t_tuple	cross_prdt(t_tuple t1, t_tuple t2)
{
	t_tuple	res;

	if (t1.w || t2.w)
		log_printf("cross product : Not a vector\n");
	res.x = t1.y * t2.z - t1.z * t2.y;
	res.y = t1.z * t2.x - t1.x * t2.z;
	res.z = t1.x * t2.y - t1.y * t2.x;
	res.w = 0;
	return (res);
}

t_tuple	reflect(t_tuple	in, t_tuple	normal)
{
	double	dot;

	if (in.w || normal.w)
		log_printf("Reflect : Both tuples need to be vectors\n");
	dot = dot_prdt(in, normal);
	normal.x = normal.x * 2 * dot;
	normal.y = normal.y * 2 * dot;
	normal.z = normal.z * 2 * dot;
	return (sub_tuples(in, normal));
}
