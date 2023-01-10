/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   each_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:02:54 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:15:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static bool	intersection(t_obj *obj, t_ray ray)
{
	ray = transform_ray(ray, obj->m_inverse);
	if (obj->inter_fnct(obj, ray))
		return (true);
	return (false);
}

t_obj	*get_hit_obj(t_obj *root, t_ray ray)
{
	t_obj	*obj;
	t_obj	*obj_closest;

	obj = root;
	obj_closest = root;
	obj_closest->hit = INFINITY;
	while (obj)
	{
		obj->hit = INFINITY;
		if (intersection(obj, ray))
		{
			if (obj->hit < obj_closest->hit)
				obj_closest = obj;
		}
		obj = obj->next;
	}
	if (obj_closest->hit < N_EPSILON)
		obj_closest->hit = INFINITY;
	return (obj_closest);
}

static int	t_color_rgb_to_hex(t_color color)
{
	return (rgb_to_hex(color.x * 255, color.y * 255, color.z * 255));
}

void	raytracing_each_pixel(t_rt *f)
{
	t_ray		ray;
	t_obj		*obj_closest;
	t_color		color;
	double		y;
	double		x;

	y = 0;
	while (y < f->mlx.win_y)
	{
		x = 0;
		while (x < f->mlx.win_x)
		{
			ray = ray_to_pixel(*f->cam, x, y);
			obj_closest = get_hit_obj(f->ob, ray);
			if (obj_closest->hit < INFINITY)
			{
				color = manage_lighting(f, obj_closest, ray);
				smlx_pixel(&f->mlx.img[0], x, y, t_color_rgb_to_hex(color));
			}
			x++;
		}
		y++;
	}
}
