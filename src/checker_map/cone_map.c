/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:02:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/03 07:31:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uv	cone_map(t_tuple p)
{
	double	theta;
	t_uv	res;

	theta = atan2(p.x, p.z);
	res.u = 1 - ((theta / (2 * N_PI)) + 0.5);
	res.v = fmod(sqrt(p.x * p.x + p.z * p.z), 1);
	return (res);
}
