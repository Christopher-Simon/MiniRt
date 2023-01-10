/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 17:40:24 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/20 14:47:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_check	add_checker(double w, double h, t_color rgb)
{
	return (get_checker(w, h, rgb, scale_colors(rgb, 0.7)));
}

t_check	get_checker(double width, double height, t_tuple rgb_1, t_tuple rgb_2)
{
	t_check	checker;

	checker.height = height;
	checker.width = width;
	checker.rgb_1 = rgb_1;
	checker.rgb_2 = rgb_2;
	return (checker);
}

t_color	uv_2d_map(t_uv p, t_check checker)
{
	int	scaled_u;
	int	scaled_v;

	scaled_u = floor(p.u * checker.width);
	scaled_v = floor(p.v * checker.height);
	if ((scaled_u + scaled_v) % 2 == 0)
		return (checker.rgb_1);
	else
		return (checker.rgb_2);
}
