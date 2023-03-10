/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:01:35 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/02 01:01:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uv	plane_map(t_tuple p)
{
	t_uv	res;

	res.u = fmod(p.x, 1);
	res.v = fmod(p.z, 1);
	return (res);
}
