/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 08:59:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 15:44:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_plane		:	dev wrapper for add_()
 * 						to make an object directly into the code
 * 						params		->	e_element
 * 
 * 	get_plane		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_plane		:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_obj *
 **/

void	do_plane(t_rt *f, t_tuple coord, t_tuple angle, int color)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.angle = angle;
	e.color = hex_to_rgb(color);
	add_plane(f, e);
}

int	get_plane(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	new_element(&e);
	info = check(f, input, TX_PATTERN_PLANE);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	e.angle = atof3(info[4], info[5], info[6], VECTOR);
	e.color = atof3(info[7], info[8], info[9], COLOR);
	if (BONUS)
	{
		e.diffuse = ft_atof(info[10]);
		e.specular = ft_atof(info[11]);
		e.shiny = ft_atof(info[12]);
		e.checker = is_checker(info[13]);
	}
	ft_arfree(info);
	add_plane(f, e);
	return (1);
}

void	add_plane(t_rt *f, t_element e)
{
	t_obj	*ob;

	log_element(e, "PLANE", E_PLANE);
	ob = olst_new_obj(f, e);
	ob->sh = E_PLANE;
	ob->inter_fnct = &plane_intersection;
	ob->normal_fnct = &plane_normal;
	ob->checker_fnct = &plane_map;
	ob->checker_specs = add_checker(2, 2, e.color);
	ob->m = m_prod(m_rot_vec_y(e.angle), ob->m);
	ob->m = m_prod(translation(e.coord.x, e.coord.y, e.coord.z), ob->m);
	ob->m_inverse = inverse_matrix(ob->m);
}
