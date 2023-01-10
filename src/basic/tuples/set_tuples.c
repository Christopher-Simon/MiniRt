/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_tuples.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:17:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:32:32 by sloquet          ###   ########.fr       */
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

/** POINT */
t_tuple	pos(double x, double y, double z)
{
	return (set_tuple(x, y, z, 1));
}

/** VECTOR */
t_tuple	set_vector(double x, double y, double z)
{
	return (set_tuple(x, y, z, 0));
}

t_tuple	vec(double x, double y, double z)
{
	return (set_tuple(x, y, z, 0));
}

t_tuple	sc(double x, double y, double z)
{
	return (set_tuple(x, y, z, 0));
}
