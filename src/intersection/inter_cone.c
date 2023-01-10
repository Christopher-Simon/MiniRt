/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cone.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:15:46 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 16:47:22 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.dir.x;
	z = ray.origin.z + t * ray.dir.z;
	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

static void	intersect_caps(t_obj *obj, t_ray ray)
{
	if (ft_fabs(ray.dir.y) < N_EPSILON)
	{
		obj->tmp_hits[2] = INFINITY;
		return ;
	}
	obj->tmp_hits[2] = (obj->height - ray.origin.y) / ray.dir.y;
	if (!check_cap(ray, obj->tmp_hits[2]))
		obj->tmp_hits[2] = INFINITY;
	return ;
}

static bool	cone_compute(t_obj *obj, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	d;

	a = pow(ray.dir.x, 2) - pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	b = 2 * ray.origin.x * ray.dir.x - 2 * ray.origin.y * ray.dir.y + \
		2 * ray.origin.z * ray.dir.z;
	c = pow(ray.origin.x, 2) - pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	if (a == 0 && b)
		return (obj->hit = -c / 2 * b, true);
	if (a == 0)
		return (obj->hit = INFINITY, false);
	d = b * b - 4 * a * c;
	if (d < 0)
		return (obj->hit = INFINITY, false);
	d = sqrt(d);
	obj->tmp_hits[0] = (-b - d) / (2 * a);
	obj->tmp_hits[1] = (-b + d) / (2 * a);
	return (true);
}

void	cone_intersect_part_1(t_obj *obj, t_ray ray)
{
	double	y0;

	obj->tmp_hits[0] = INFINITY;
	obj->tmp_hits[1] = INFINITY;
	obj->tmp_hits[2] = INFINITY;
	obj->tmp_hits[3] = INFINITY;
	intersect_caps(obj, ray);
	cone_compute(obj, ray);
	if (obj->tmp_hits[0] != INFINITY)
	{
		y0 = ray.origin.y + obj->tmp_hits[0] * ray.dir.y;
		if (y0 < 0 || y0 > obj->height)
			obj->tmp_hits[0] = INFINITY;
	}
	if (obj->tmp_hits[1] != INFINITY)
	{
		y0 = ray.origin.y + obj->tmp_hits[1] * ray.dir.y;
		if (y0 < 0 || y0 > obj->height)
			obj->tmp_hits[1] = INFINITY;
	}
}

bool	cone_intersection(t_obj *obj, t_ray ray)
{
	cone_intersect_part_1(obj, ray);
	get_cone_hits(obj);
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	if (obj->hit == INFINITY)
		return (false);
	obj->in_object = is_in_object(obj->hits);
	return (true);
}

// void	get_cone_hits(t_obj *obj)
// {
// 	int	i;

// 	i = 0;
// 	obj->hits[0] = INFINITY;
// 	obj->hits[1] = INFINITY;
// 	while (i < 4)
// 	{
// 		if (obj->tmp_hits[i] < 0 && fabs(obj->tmp_hits[i]) < fabs(obj->hits[0]))
// 			obj->hits[0] = obj->tmp_hits[i];
// 		i++;
// 	}
// 	if (obj->hits[0] == INFINITY)
// 	{
// 		i = 0;
// 		while (i < 4)
// 		{
// 			if (obj->tmp_hits[i] > 0 && obj->tmp_hits[i] < obj->hits[0])
// 				obj->hits[0] = obj->tmp_hits[i];
// 			i++;
// 		}
// 	}
// 	i = 0;
// 	while (i < 4)
// 	{
// 		if (obj->tmp_hits[i] > obj->hits[0] && obj->tmp_hits[i] < obj->hits[1])
// 			obj->hits[1] = obj->tmp_hits[i];
// 		i++;
// 	}
// }

/*
typedef struct s_abcd
{
	double	a;
	double	b;
	double	c;
	double	d;
}	t_abcd;

static bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.dir.x;
	z = ray.origin.z + t * ray.dir.z;
	if (x * x + z * z <= 1)
		return (true);
	return (false);
}

static void	intersect_caps(t_obj *obj, t_ray ray)
{
	if (ft_fabs(ray.dir.y) < N_EPSILON)
	{
		obj->tmp_hits[2] = INFINITY;
		return ;
	}
	obj->tmp_hits[2] = (obj->height - ray.origin.y) / ray.dir.y;
	if (!check_cap(ray, obj->tmp_hits[2]))
		obj->tmp_hits[2] = INFINITY;
}

static bool	cone_compute(t_obj *obj, t_ray ray)
{
	t_abcd	st;

	st.a = pow(ray.dir.x, 2) - pow(ray.dir.y, 2) + pow(ray.dir.z, 2);
	st.b = 2 * ray.origin.x * ray.dir.x - 2 * ray.origin.y * ray.dir.y + \
		2 * ray.origin.z * ray.dir.z;
	st.c = pow(ray.origin.x, 2) - pow(ray.origin.y, 2) + pow(ray.origin.z, 2);
	if (st.a == 0 && st.b)
	{
		obj->hit = -st.c / 2 * st.b;
		return (true);
	}
	if (st.a == 0)
	{
		obj->hit = INFINITY;
		return (false);
	}
	st.d = st.b * st.b - 4 * st.a * st.c;
	if (st.d < 0)
	{
		obj->hit = INFINITY;
		return (false);
	}
	obj->tmp_hits[0] = (-st.b - sqrt(st.d)) / (2 * st.a);
	obj->tmp_hits[1] = (-st.b + sqrt(st.d)) / (2 * st.a);
	return (true);
}

static void	get_cone_hits(t_obj *obj)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (obj->tmp_hits[i] < 0 && fabs(obj->tmp_hits[i]) < fabs(obj->hits[0]))
			obj->hits[0] = obj->tmp_hits[i];
		i++;
	}
	if (obj->hits[0] == INFINITY)
	{
		i = 0;
		while (i < 4)
		{
			if (obj->tmp_hits[i] > 0 && obj->tmp_hits[i] < obj->hits[0])
				obj->hits[0] = obj->tmp_hits[i];
			i++;
		}
	}
	i = -1;
	while (i++ < 4)
	{
		if (obj->tmp_hits[i] > obj->hits[0] && obj->tmp_hits[i] < obj->hits[1])
			obj->hits[1] = obj->tmp_hits[i];
	}
}

bool	cone_intersection(t_obj *obj, t_ray ray)
{
	double	y0;

	set_infinity(obj);
	intersect_caps(obj, ray);
	cone_compute(obj, ray);
	if (obj->tmp_hits[0] != INFINITY)
	{
		y0 = ray.origin.y + obj->tmp_hits[0] * ray.dir.y;
		if (y0 < 0 || y0 > obj->height)
			obj->tmp_hits[0] = INFINITY;
	}
	if (obj->tmp_hits[1] != INFINITY)
	{
		y0 = ray.origin.y + obj->tmp_hits[1] * ray.dir.y;
		if (y0 < 0 || y0 > obj->height)
			obj->tmp_hits[1] = INFINITY;
	}
	get_cone_hits(obj);
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	if (obj->hit == INFINITY)
		return (false);
	obj->in_object = is_in_object(obj->hits);
	return (true);
}
*/
