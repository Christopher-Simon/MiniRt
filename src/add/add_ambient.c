/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 06:33:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 15:46:07 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_ambient		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 *
 * 	get_ambient		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 * 
 * 	add_ambient		:	add unique ambient to the main struct
 * 						e_element	->	f->ambient 
 **/

void	do_ambient(t_rt *f, double ratio, int color)
{
	t_element	e;

	new_element(&e);
	e.ratio = ratio;
	e.color = hex_to_rgb(color);
	add_ambient(f, e);
}

int	get_ambient(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	if (f->ambient.active)
		return (0);
	new_element(&e);
	info = check(f, input, TX_PATTERN_AMBIENT);
	e.ratio = ft_atof(info[1]);
	e.color = atof3(info[2], info[3], info[4], COLOR);
	ft_arfree(info);
	add_ambient(f, e);
	return (1);
}

void	add_ambient(t_rt *f, t_element e)
{
	log_element(e, "AMBIENT", E_AMBIENT);
	if (f->ambient.active)
		rt_exit(f, 1, "too many add_ambient()");
	f->ambient.ratio = e.ratio;
	f->ambient.color = norm_color(e.color);
	f->ambient.active = 1;
}
