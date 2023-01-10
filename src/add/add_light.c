/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:33:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 13:50:08 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_light		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 * 
 * 	get_light		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_light		:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_light *
 **/

void	do_light(t_rt *f, t_tuple coord, double ratio, int color)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.ratio = ratio;
	e.color = hex_to_rgb(color);
	add_light(f, e);
}

int	get_light(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	if (llst_size(f->li) && BONUS == 0)
		return (0);
	new_element(&e);
	info = check(f, input, TX_PATTERN_LIGHT);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	log_printf("%s\n", info[4]);
	e.ratio = ft_atof(info[4]);
	log_printf("%f\n", e.ratio);
	if (BONUS)
		e.color = atof3(info[5], info[6], info[7], COLOR);
	else
		e.color = hex_to_rgb(WHITE);
	ft_arfree(info);
	add_light(f, e);
	return (1);
}

// void	add_light(t_rt *f, t_element e) -> light_lst.c
