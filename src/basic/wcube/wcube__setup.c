/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube__setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:45:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 14:20:11 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	wcube_strlen(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

static t_3Dpoint	wcube_set_3dp(double x, double y, double z)
{
	t_3Dpoint	head;

	head.x = x;
	head.y = y;
	head.z = z;
	return (head);
}

t_3Dpoint	wcube_setup(t_rt *f, const char *str, t_wcube_mode mode)
{
	double	i;

	i = wcube_strlen(str);
	if (f->ambient.active == 0)
		do_ambient(f, 0.1, WHITE);
	if (mode == WCUBE_STARWARS)
	{
		do_camera(f, pos(5, 10, -50), vec(0, 0, 1), 90);
		do_light(f, pos(100, 0, 0), 1, ORANGE);
		do_light(f, pos(0, 0, -100), 1, ORANGE);
		return (wcube_set_3dp(i * -6 + 3, 1, 0));
	}
	if (mode == WCUBE_STRAIGHT)
	{
		do_camera(f, pos(5, 10, -50), vec(0, 0, 1), 90);
		do_light(f, pos(100, 0, 100), 1, CRIMSON);
		do_light(f, pos(0, 100, 100), 1, CYAN);
		do_light(f, pos(0, 0, -100), 1, LIGHT_GRAY);
		return (wcube_set_3dp(i * -5 + 1, 1, 0));
	}
	do_camera(f, pos(5, 10, -50), vec(0, 0, 1), 90);
	do_light(f, pos(100, 0, 100), 1, CRIMSON);
	do_light(f, pos(0, 100, 100), 1, CYAN);
	do_light(f, pos(0, 0, -100), 1, LIGHT_GRAY);
	return (wcube_set_3dp(i * -6 + 3, 1, 0));
}
