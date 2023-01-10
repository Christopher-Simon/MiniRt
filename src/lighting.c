/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 10:59:03 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/22 14:18:13 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

typedef struct s_magic
{
	t_color	c;
	t_tuple	pos;
	t_ray	cam;
	t_tuple	normal;
}	t_magic;

static t_color	lighting_specular(t_obj *obj, t_light light, t_magic m, \
	t_tuple light_vec)
{
	double	refl_incid;
	double	factor;

	refl_incid = dot_prdt(reflect(negating_tuple(light_vec), m.normal), \
	normalisation(m.cam.dir));
	if (refl_incid <= N_EPSILON)
		return (color(0, 0, 0));
	else
	{
		factor = pow(refl_incid, obj->material.shiny);
		return (scale_colors(light.color, obj->material.specular * factor));
	}
}

static	t_color	lighting_diffusion(t_obj *obj, t_light light, t_magic m)
{
	t_color	new_color;
	t_tuple	light_vec;
	t_tuple	diffuse;
	t_tuple	specular;
	double	incidence;

	new_color = scale_colors(light.color, light.ratio);
	new_color = prod_colors(obj->material.color, new_color);
	light_vec = normalisation(sub_tuples(light.position, m.pos));
	incidence = dot_prdt(light_vec, m.normal);
	if (incidence < N_EPSILON)
		return (color(0, 0, 0));
	diffuse = scale_colors(new_color, obj->material.diffuse * incidence);
	specular = lighting_specular(obj, light, m, light_vec);
	return (add_colors(specular, diffuse));
}

static t_color	lighting(t_obj *obj, t_light light, t_magic m, t_ray cam)
{
	m.cam = cam;
	if (BONUS && obj->is_checker)
	{
		obj->material.color = uv_2d_map(obj->checker_fnct(\
		prod_matx_tuple(obj->m_inverse, m.pos)), \
		obj->checker_specs);
		obj->material.color = norm_color(obj->material.color);
	}
	return (lighting_diffusion(obj, light, m));
}

static bool	is_shadowed(t_tuple pos, t_light *light, t_obj *root)
{
	t_ray		to_light;
	t_obj		*obj;
	t_tuple		direction;
	double		albert;

	direction = (sub_tuples(light->position, pos));
	to_light = get_ray(pos, normalisation(direction));
	albert = magnitude(direction);
	obj = get_hit_obj(root, to_light);
	if (obj->hit == INFINITY)
		return (false);
	if (obj->hit < albert)
		return (true);
	return (false);
}

t_color	manage_lighting(t_rt *f, t_obj *obj, t_ray ray)
{
	t_magic	m;
	t_color	color;
	t_light	*light;

	light = f->li;
	m.pos = position(ray, obj->hit);
	ray.dir = negating_tuple(ray.dir);
	m.normal = normal_at(obj, m.pos, ray);
	if (BONUS && (!obj->in_object || obj->is_skybox))
		manage_texture(obj, m.pos, &m.normal);
	if (obj->is_skybox)
		return (obj->material.color);
	color = scale_colors(f->ambient.color, f->ambient.ratio);
	color = prod_colors(obj->material.color, color);
	m.pos = add_tuples(m.pos, scalar_tuples(m.normal, N_EPSILON));
	while (light)
	{
		if (!is_shadowed(m.pos, light, f->ob))
			m.c = calibrate_rgb(lighting(obj, *light, m, ray));
		else
			m.c = pos(0, 0, 0);
		color = calibrate_rgb(add_colors(color, m.c));
		light = light->next;
	}
	return (color);
}
