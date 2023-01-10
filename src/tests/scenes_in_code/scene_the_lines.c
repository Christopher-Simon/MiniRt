/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_the_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 06:01:48 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 11:39:42 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	line_sphere(t_rt *f, double y, double z, double xgap)
{
	t_element	e;
	int			i;

	new_element(&e);
	e.coord = pos(0, y, z);
	e.color = color_picker(12);
	e.diameter = 1;
	add_sphere(f, e);
	i = 1;
	while (i <= 12)
	{
		e.coord.x = -xgap * i;
		e.color = color_picker(i);
		add_sphere(f, e);
		e.coord.x = xgap * i;
		e.color = color_picker(i + 12);
		add_sphere(f, e);
		i++;
	}
}

void	line_cuboid(t_rt *f, double y, double z, double xgap)
{
	t_element	e;
	int			i;

	new_element(&e);
	e.coord = pos(0, y, z);
	e.angle = vec(0, 0, 1);
	e.scale = sc(1, 1, 1);
	e.color = color_picker(12);
	add_cuboid(f, e);
	i = 1;
	while (i <= 12)
	{
		e.coord.x = xgap * -i;
		e.angle = vec(i * 0.02, i * -0.04, i * 0.08);
		e.color = color_picker(i);
		add_cuboid(f, e);
		e.coord.x = xgap * i;
		e.angle = vec(i * 0.08, i * 0.04, i * -0.05);
		e.color = color_picker(i);
		e.color = color_picker(i + 12);
		add_cuboid(f, e);
		i++;
	}
}

void	line_cone(t_rt *f, double y, double z, double xgap)
{
	t_element	e;
	int			i;

	new_element(&e);
	e.coord = pos(0, y, z);
	e.angle = vec(0, 0, 1);
	e.scale = sc(1, 1, 1);
	e.color = color_picker(12);
	add_cone(f, e);
	i = 1;
	while (i <= 12)
	{
		e.coord.x = xgap * -i;
		e.angle = vec(i * -0.05, i * 0.04, i * 0.08);
		e.color = color_picker(i);
		add_cone(f, e);
		e.coord.x = xgap * i;
		e.angle = vec(i * 0.08, i * -0.04, i * 0.02);
		e.color = color_picker(i + 12);
		add_cone(f, e);
		i++;
	}
}

static void	line_cylinder(t_rt *f, double y, double z, double xgap)
{
	t_element	e;
	int			i;

	new_element(&e);
	e.coord = pos(0, y, z);
	e.angle = vec(0, 0, 1);
	e.diameter = 1;
	e.height = 3;
	e.color = color_picker(12);
	add_cylinder(f, e);
	i = 1;
	while (i <= 12)
	{
		e.coord.x = xgap * -i;
		e.angle = vec(i * 0.02, i * 0.04, i * -0.08);
		e.color = color_picker(i);
		add_cylinder(f, e);
		e.coord.x = xgap * i;
		e.angle = vec(i * -0.08, i * 0.04, i * 0.05);
		e.color = color_picker(i + 12);
		add_cylinder(f, e);
		i++;
	}
}

void	the_lines(t_rt *f)
{
	do_ambient(f, 0.1, WHITE);
	do_camera(f, pos(0, 10, -50), vec(0, -0.2, 1), 90);
	do_light(f, pos(20, 0, -50), 1, WHITE);
	do_plane(f, pos(-100, 0, 100), vec(1, 0, 0), (RED));
	do_plane(f, pos(100, 0, 100), vec(1, 0, 0), (BLUE));
	do_plane(f, pos(0, -40, 100), vec(0, 1, 0), (PERU));
	line_cuboid(f, 15, 10, 5);
	line_sphere(f, 0, 10, 5);
	line_cone(f, -15, 10, 5);
	line_cylinder(f, -30, 10, 5);
}
