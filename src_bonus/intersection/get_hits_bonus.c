/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_hits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:34:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 16:47:32 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	get_cyl_hits(t_obj *obj)
{
	int	i;

	i = -1;
	obj->hits[0] = INFINITY;
	obj->hits[1] = INFINITY;
	while (++i < 4)
	{
		if (obj->tmp_hits[i] < 0 && fabs(obj->tmp_hits[i]) < fabs(obj->hits[0]))
			obj->hits[0] = obj->tmp_hits[i];
	}
	if (obj->hits[0] == INFINITY)
	{
		i = -1;
		while (++i < 4)
		{
			if (obj->tmp_hits[i] > 0 && obj->tmp_hits[i] < obj->hits[0])
				obj->hits[0] = obj->tmp_hits[i];
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (obj->tmp_hits[i] > obj->hits[0] && obj->tmp_hits[i] < obj->hits[1])
			obj->hits[1] = obj->tmp_hits[i];
	}
}

void	get_cone_hits(t_obj *obj)
{
	int	i;

	i = -1;
	obj->hits[0] = INFINITY;
	obj->hits[1] = INFINITY;
	while (++i < 4)
	{
		if (obj->tmp_hits[i] < 0 && fabs(obj->tmp_hits[i]) < fabs(obj->hits[0]))
			obj->hits[0] = obj->tmp_hits[i];
	}
	if (obj->hits[0] == INFINITY)
	{
		i = -1;
		while (++i < 4)
		{
			if (obj->tmp_hits[i] > 0 && obj->tmp_hits[i] < obj->hits[0])
				obj->hits[0] = obj->tmp_hits[i];
		}
	}
	i = -1;
	while (++i < 4)
	{
		if (obj->tmp_hits[i] > obj->hits[0] && obj->tmp_hits[i] < obj->hits[1])
			obj->hits[1] = obj->tmp_hits[i];
	}
}
