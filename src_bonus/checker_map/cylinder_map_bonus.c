/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 01:02:26 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/03 07:32:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_uv	cylinder_map(t_tuple p)
{
	double	theta;
	t_uv	res;

	theta = atan2(p.x, p.z);
	res.u = theta / (2 * N_PI);
	res.u = (1 - (res.u + 0.5)) * 2;
	res.v = fmod(p.y, 1);
	return (res);
}
