/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:59:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 17:48:38 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_sphere		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 * 
 * 	get_sphere		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_sphere		:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_obj *
 **/

void	do_sphere(t_rt *f, t_tuple coord, double diameter, int color)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.diameter = diameter;
	e.color = hex_to_rgb(color);
	add_sphere(f, e);
}

int	get_sphere(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	new_element(&e);
	info = check(f, input, TX_PATTERN_SPHERE);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	e.diameter = ft_atof(info[4]);
	e.color = atof3(info[5], info[6], info[7], COLOR);
	if (BONUS)
	{
		e.diffuse = ft_atof(info[8]);
		e.specular = ft_atof(info[9]);
		e.shiny = ft_atof(info[10]);
		e.checker = is_checker(info[11]);
		e.texfile = is_file(info[12]);
		e.bumfile = is_file(info[13]);
		e.skybox = is_skybox(info[14]);
	}
	ft_arfree(info);
	add_sphere(f, e);
	return (1);
}

void	add_sphere(t_rt *f, t_element e)
{
	t_obj	*ob;

	log_element(e, "SPHERE", E_SPHERE);
	ob = olst_new_obj(f, e);
	ob->sh = E_SPHERE;
	ob->inter_fnct = &sphere_intersection;
	ob->normal_fnct = &sphere_normal;
	ob->checker_fnct = &sphere_map;
	ob->checker_specs = add_checker(16, 8, e.color);
	e.diameter /= 2;
	ob->m = m_prod(scaling(e.diameter, e.diameter, e.diameter), ob->m);
	ob->m = m_prod(translation(e.coord.x, e.coord.y, e.coord.z), ob->m);
	ob->m_inverse = inverse_matrix(ob->m);
}
