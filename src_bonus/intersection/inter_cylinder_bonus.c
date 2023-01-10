/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter_cylinder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:55:42 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 16:49:15 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

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
		return ;
	obj->tmp_hits[0] = (0 - ray.origin.y) / ray.dir.y;
	obj->tmp_hits[1] = (obj->height - ray.origin.y) / ray.dir.y;
	if (check_cap(ray, obj->tmp_hits[0]) == 0)
		obj->tmp_hits[0] = INFINITY;
	if (check_cap(ray, obj->tmp_hits[1]) == 0)
		obj->tmp_hits[1] = INFINITY;
	obj->hit = get_smallest_intersect(obj->tmp_hits[0], obj->tmp_hits[1]);
}

static double	cylinder_equation(t_ray ray, t_abcd *abcd)
{
	abcd->a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	if (abcd->a < N_EPSILON)
		return (-1);
	abcd->b = 2 * ray.origin.x * ray.dir.x + \
		2 * ray.origin.z * ray.dir.z;
	abcd->c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	abcd->d = abcd->b * abcd->b - 4 * abcd->a * abcd->c;
	return (abcd->d);
}

// static void	get_cylinder_hits(t_obj *obj)
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

static bool	d_is_negative(t_obj *obj)
{
	obj->hits[0] = obj->tmp_hits[0];
	obj->hits[1] = obj->tmp_hits[1];
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	obj->in_object = is_in_object(obj->hits);
	if (obj->hit == INFINITY)
		return (false);
	return (true);
}

bool	cylinder_intersection(t_obj *obj, t_ray ray)
{
	t_abcd	abcd;
	double	y0;

	intersect_caps(obj, ray);
	abcd.d = cylinder_equation(ray, &abcd);
	if (abcd.d < N_EPSILON)
		return (d_is_negative(obj));
	abcd.d = sqrt(abcd.d);
	obj->tmp_hits[2] = (-abcd.b - abcd.d) / (2 * abcd.a);
	obj->tmp_hits[3] = (-abcd.b + abcd.d) / (2 * abcd.a);
	y0 = ray.origin.y + obj->tmp_hits[2] * ray.dir.y;
	if (y0 < 0 || y0 > obj->height)
		obj->tmp_hits[2] = INFINITY;
	y0 = ray.origin.y + obj->tmp_hits[3] * ray.dir.y;
	if (y0 < 0 || y0 > obj->height)
		obj->tmp_hits[3] = INFINITY;
	get_cyl_hits(obj);
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	if (obj->hit == INFINITY)
		return (false);
	obj->in_object = is_in_object(obj->hits);
	return (true);
}

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
		return ;
	obj->tmp_hits[0] = (0 - ray.origin.y) / ray.dir.y;
	obj->tmp_hits[1] = (obj->height - ray.origin.y) / ray.dir.y;
	if (check_cap(ray, obj->tmp_hits[0]) == 0)
		obj->tmp_hits[0] = INFINITY;
	if (check_cap(ray, obj->tmp_hits[1]) == 0)
		obj->tmp_hits[1] = INFINITY;
	obj->hit = get_smallest_intersect(obj->tmp_hits[0], obj->tmp_hits[1]);
}

static double	cylinder_equation(t_ray ray, t_abcd *abcd)
{
	abcd->a = pow(ray.dir.x, 2) + pow(ray.dir.z, 2);
	if (abcd->a < N_EPSILON)
		return (-1);
	abcd->b = 2 * ray.origin.x * ray.dir.x + \
		2 * ray.origin.z * ray.dir.z;
	abcd->c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	abcd->d = abcd->b * abcd->b - 4 * abcd->a * abcd->c;
	return (abcd->d);
}

static bool	d_is_negative(t_obj *obj)
{
	obj->hits[0] = obj->tmp_hits[0];
	obj->hits[1] = obj->tmp_hits[1];
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	obj->in_object = is_in_object(obj->hits);
	if (obj->hit == INFINITY)
		return (false);
	return (true);
}

bool	cylinder_intersection(t_obj *obj, t_ray ray)
{
	t_abcd	abcd;
	double	y0;

	intersect_caps(obj, ray);
	abcd.d = cylinder_equation(ray, &abcd);
	if (abcd.d < N_EPSILON)
		return (d_is_negative(obj));
	abcd.d = sqrt(abcd.d);
	obj->tmp_hits[2] = (-abcd.b - abcd.d) / (2 * abcd.a);
	obj->tmp_hits[3] = (-abcd.b + abcd.d) / (2 * abcd.a);
	y0 = ray.origin.y + obj->tmp_hits[2] * ray.dir.y;
	if (y0 < 0 || y0 > obj->height)
		obj->tmp_hits[2] = INFINITY;
	y0 = ray.origin.y + obj->tmp_hits[3] * ray.dir.y;
	if (y0 < 0 || y0 > obj->height)
		obj->tmp_hits[3] = INFINITY;
	get_cyl_hits(obj);
	obj->hit = get_smallest_intersect(obj->hits[0], obj->hits[1]);
	if (obj->hit == INFINITY)
		return (false);
	obj->in_object = is_in_object(obj->hits);
	return (true);
}
*/
