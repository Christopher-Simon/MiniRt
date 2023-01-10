/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cuboid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:10:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:12:24 by sloquet          ###   ########.fr       */
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

static double	min(double x, double y, double z)
{
	if (x <= y && x <= z)
		return (x);
	if (y <= z && y <= x)
		return (y);
	if (z <= x && z <= y)
		return (z);
	return (-INFINITY);
}

typedef struct s_t2
{
	double	min;
	double	max;
}	t_t2;

static t_t2	check_axis(double origin, double direction)
{
	t_t2	t;
	double	tmin_num;
	double	tmax_num;

	tmin_num = (-1 - origin);
	tmax_num = (1 - origin);
	if (fabs(direction) >= N_EPSILON)
	{
		t.min = tmin_num / direction;
		t.max = tmax_num / direction;
	}
	else
	{
		t.min = tmin_num * INFINITY;
		t.max = tmax_num * INFINITY;
	}
	if (t.min > t.max)
		ft_dswap(&t.min, &t.max);
	return (t);
}

bool	cuboid_intersection(t_obj *obj, t_ray ray)
{
	double	tmin;
	double	tmax;
	t_t2	xt;
	t_t2	yt;
	t_t2	zt;

	xt = check_axis(ray.origin.x, ray.dir.x);
	yt = check_axis(ray.origin.y, ray.dir.y);
	zt = check_axis(ray.origin.z, ray.dir.z);
	tmin = max(xt.min, yt.min, zt.min);
	tmax = min(xt.max, yt.max, zt.max);
	obj->hit = INFINITY;
	if (tmin > tmax)
		return (false);
	obj->hit = get_smallest_intersect(tmin, tmax);
	return (true);
}
