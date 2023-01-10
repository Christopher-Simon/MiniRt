/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neg_tuple.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 04:26:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:33:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	scalar_tuples(t_tuple t1, double scalar)
{
	t_tuple	res;

	res.x = t1.x * scalar;
	res.y = t1.y * scalar;
	res.z = t1.z * scalar;
	res.w = t1.w;
	return (res);
}

t_tuple	add_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	res;

	res.x = t1.x + t2.x;
	res.y = t1.y + t2.y;
	res.z = t1.z + t2.z;
	if (t1.w && t2.w)
		res.w = 1;
	else
		res.w = t1.w + t2.w;
	return (res);
}

t_tuple	sub_tuples(t_tuple t1, t_tuple t2)
{
	t_tuple	res;

	res.x = t1.x - t2.x;
	res.y = t1.y - t2.y;
	res.z = t1.z - t2.z;
	res.w = t1.w - t2.w;
	return (res);
}

t_tuple	negating_tuple(t_tuple t1)
{
	if (t1.w)
		return (sub_tuples(pos(0, 0, 0), t1));
	else
		return (sub_tuples(set_vector(0, 0, 0), t1));
}
