/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cuboid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 10:27:52 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 18:20:45 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_cuboid		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 * 
 * 	get_cuboid		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_cuboid		:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_obj *
 **/

void	do_cuboid(t_rt *f, t_tuple coord, t_tuple angle, t_tuple scale)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.angle = angle;
	e.scale = scale;
	e.color = hex_to_rgb(MAGENTA);
	add_cuboid(f, e);
}

int	get_cuboid(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	if (BONUS == 0)
		return (0);
	new_element(&e);
	info = check(f, input, TX_PATTERN_CUBOID);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	e.angle = atof3(info[4], info[5], info[6], VECTOR);
	e.scale = atof3(info[7], info[8], info[9], VECTOR);
	e.color = atof3(info[10], info[11], info[12], COLOR);
	if (BONUS)
	{
		e.diffuse = ft_atof(info[13]);
		e.specular = ft_atof(info[14]);
		e.shiny = ft_atof(info[15]);
		e.checker = is_checker(info[16]);
	}
	ft_arfree(info);
	add_cuboid(f, e);
	return (1);
}

void	add_cuboid(t_rt *f, t_element e)
{
	t_obj	*ob;

	log_element(e, "CUBOID", E_CUBOID);
	ob = olst_new_obj(f, e);
	ob->sh = E_CUBOID;
	ob->inter_fnct = &cuboid_intersection;
	ob->normal_fnct = &cuboid_normal;
	ob->checker_fnct = &cuboid_map;
	ob->checker_specs = add_checker(2, 2, e.color);
	ob->m = m_prod(scaling(e.scale.x, e.scale.y, e.scale.z), ob->m);
	if (MRT_PUTS_MODE)
		ob->m = m_prod(m_rotation(normalisation(e.angle)), ob->m);
	else
		ob->m = m_prod(m_rot_vec_y(normalisation(e.angle)), ob->m);
	ob->m = m_prod(translation(e.coord.x, e.coord.y, e.coord.z), ob->m);
	ob->m_inverse = inverse_matrix(ob->m);
}
