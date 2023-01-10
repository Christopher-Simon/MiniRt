/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 09:23:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 15:47:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_cylinder		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 * 
 * 	get_cylinder	:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_cylinder	:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_obj *
 **/

void	do_cylinder(t_rt *f, t_tuple coord, t_tuple angle, double h)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.angle = angle;
	e.diameter = 4;
	e.height = h;
	e.color = hex_to_rgb(LIME);
	add_cylinder(f, e);
}

int	get_cylinder(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	new_element(&e);
	info = check(f, input, TX_PATTERN_CYLINDER);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	e.angle = atof3(info[4], info[5], info[6], VECTOR);
	e.diameter = ft_atof(info[7]);
	e.height = ft_atof(info[8]);
	e.color = atof3(info[9], info[10], info[11], COLOR);
	if (BONUS)
	{
		e.diffuse = ft_atof(info[12]);
		e.specular = ft_atof(info[13]);
		e.shiny = ft_atof(info[14]);
		e.checker = is_checker(info[15]);
	}
	ft_arfree(info);
	add_cylinder(f, e);
	return (1);
}

void	add_cylinder(t_rt *f, t_element e)
{
	t_obj	*ob;

	log_element(e, "CYLINDER", E_CYLINDER);
	ob = olst_new_obj(f, e);
	ob->sh = E_CYLINDER;
	ob->inter_fnct = &cylinder_intersection;
	ob->normal_fnct = &cylinder_normal;
	ob->checker_fnct = &cylinder_map;
	ob->checker_specs = add_checker(4, 2, e.color);
	ob->m = m_prod(scaling(e.diameter, e.height, e.diameter), ob->m);
	ob->m = m_prod(m_rot_vec_y(normalisation(e.angle)), ob->m);
	ob->m = m_prod(translation(e.coord.x, e.coord.y, e.coord.z), ob->m);
	ob->m_inverse = inverse_matrix(ob->m);
}
