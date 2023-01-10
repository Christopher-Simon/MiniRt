/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 18:06:45 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/18 19:31:44 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_ray	get_ray(t_tuple	origin, t_tuple direction)
{
	t_ray	ray;

	if (!origin.w)
		log_printf("POINT Uncorrect tuples\n");
	if (direction.w)
		log_printf("VECTOR Uncorrect tuples\n");
	ray.origin = origin;
	ray.dir = direction;
	return (ray);
}

t_tuple	position(t_ray ray, double t)
{
	t_tuple	res;

	res.x = ray.origin.x + ray.dir.x * t;
	res.y = ray.origin.y + ray.dir.y * t;
	res.z = ray.origin.z + ray.dir.z * t;
	res.w = 1;
	return (res);
}

t_ray	transform_ray(t_ray ray, t_matx4 M)
{
	t_ray	raysult;

	raysult.dir = prod_matx_tuple(M, ray.dir);
	raysult.origin = prod_matx_tuple(M, ray.origin);
	return (raysult);
}

t_ray	ray_to_pixel(t_cam cam, int x, int y)
{
	double	xoffset;
	double	yoffset;
	double	worldx;
	double	worldy;
	t_ray	ray;

	xoffset = (x + 0.5) * cam.pixel_size;
	yoffset = (y + 0.5) * cam.pixel_size;
	worldx = cam.half_width - xoffset;
	worldy = cam.half_height - yoffset;
	ray.dir = prod_matx_tuple(cam.inv_m, pos(worldx, worldy, -1));
	ray.origin = prod_matx_tuple(cam.inv_m, pos(0, 0, 0));
	ray.dir = normalisation(sub_tuples(ray.dir, ray.origin));
	return (ray);
}
