/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 06:34:57 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 06:36:25 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_tuple	set_tuple(double x, double y, double z, double w)
{
	t_tuple	tup;

	tup.x = x;
	tup.y = y;
	tup.z = z;
	tup.w = w;
	return (tup);
}

t_color	calibrate_rgb(t_color color)
{
	if (color.x > 1)
		color.x = 1;
	if (color.y > 1)
		color.y = 1;
	if (color.z > 1)
		color.z = 1;
	return (color);
}

t_color	hex_to_rgb(int hex)
{
	t_color	color;

	color.x = ((hex >> 16) & 0xFF);
	color.y = ((hex >> 8) & 0xFF);
	color.z = ((hex) & 0xFF);
	color.w = 1;
	return (color);
}

t_color	norm_color(t_color color)
{
	color.x /= 255.0;
	color.y /= 255.0;
	color.z /= 255.0;
	color.w = 1;
	return (color);
}

t_tuple	color(double x, double y, double z)
{
	return (set_tuple(x, y, z, 1));
}
