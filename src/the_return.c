/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_return.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 06:43:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 16:14:38 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	test_area(t_rt *f)
{
	do_ambient(f, 0.5, WHITE);
	do_camera(f, pos(0, 0, -50), vec(0, 0, 1), 90);
	do_light(f, pos(10, 0, 10), 1, WHITE);
	do_plane(f, pos(0, 0, 100), vec(0, 0, -1), (PERU));
	do_sphere(f, pos(0, 0, 0), 10, (CORAL));
	do_ellipsoid(f, pos(5, 0, -10), vec(1, 0, 1), sc(1, 2, 1));
	do_ellipsoid(f, pos(0, 0, 0), vec(1, 0, 1), sc(1, 2, 1));
	do_cuboid(f, pos(0, 0, 0), vec(0, 1, 0), sc(2, 2, 2));
	do_cylinder(f, pos(0, 0, 0), vec(0, 0, 1), 20);
	do_cone(f, pos(0, -1, 0), vec(0, 1, 0), 2);
}

#ifdef BONUS

void	the_return(t_rt *f)
{
	if (MRT_FILE_MODE)
		return ;
	if (MRT_PUTS_MODE)
		return (wcube_putstr(f, f->wcub.txt_buffer, WCUBE_MODE));
	if (MRT_CODE_MODE)
	{
		return (the_lines(f));
		return (test_area(f));
	}
}

#else

void	the_return(t_rt *f)
{
	return ;
	(void)f;
}

#endif
