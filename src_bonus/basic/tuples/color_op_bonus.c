/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:23:15 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 06:35:35 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_color	sub_colors(t_color t1, t_color t2)
{
	t_color	res;

	if (!t1.w || !t2.w)
		log_printf("Sub colors : both tuples need to be points\n");
	res.x = t1.x - t2.x;
	res.y = t1.y - t2.y;
	res.z = t1.z - t2.z;
	res.w = 1;
	return (res);
}

t_color	add_colors(t_color t1, t_color t2)
{
	t_color	res;

	if (!t1.w)
	{
		log_tuple(t1);
		log_printf("add_colors : t1 needs to be points\n");
	}
	if (!t2.w)
	{
		log_tuple(t2);
		log_printf("add_colors : t2 needs to be points\n");
	}
	res.x = t1.x + t2.x;
	res.y = t1.y + t2.y;
	res.z = t1.z + t2.z;
	res.w = 1;
	return (res);
}

t_color	prod_colors(t_color t1, t_color t2)
{
	t_color	res;

	if (!t1.w || !t2.w)
		log_printf("prod_colors : both tuples need to be points\n");
	res.x = t1.x * t2.x;
	res.y = t1.y * t2.y;
	res.z = t1.z * t2.z;
	res.w = 1;
	return (res);
}

t_color	scale_colors(t_color t1, double scalar)
{
	t_color	res;

	if (!t1.w)
		log_printf("scalar_colors : tuple needs to be points\n");
	res.x = t1.x * scalar;
	res.y = t1.y * scalar;
	res.z = t1.z * scalar;
	res.w = 1;
	return (res);
}
