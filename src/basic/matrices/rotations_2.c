/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:29:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:30:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_matx4	rotation_x_rad(double degrees)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = 1;
	mat.m[1][1] = cos(degrees);
	mat.m[1][2] = -sin(degrees);
	mat.m[2][1] = sin(degrees);
	mat.m[2][2] = cos(degrees);
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	rotation_y_rad(double degrees)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = cos(degrees);
	mat.m[0][2] = sin(degrees);
	mat.m[1][1] = 1;
	mat.m[2][0] = -sin(degrees);
	mat.m[2][2] = cos(degrees);
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	rotation_z_rad(double degrees)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = cos(degrees);
	mat.m[0][1] = -sin(degrees);
	mat.m[1][0] = sin(degrees);
	mat.m[1][1] = cos(degrees);
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	m_rot_vec_y(t_tuple vec)
{
	t_matx4	m;
	double	xy_len;
	double	z_angle;
	double	x_angle;
	double	vec_len;

	vec_len = magnitude(vec);
	xy_len = sqrt(vec.x * vec.x + vec.y * vec.y);
	if (xy_len == 0)
	{
		if (vec.x > 0)
			z_angle = ft_deg_to_rad(90);
		else
			z_angle = ft_deg_to_rad(-90);
	}
	else
		z_angle = acos(vec.y / xy_len);
	x_angle = acos(xy_len / vec_len);
	if (vec.z < 0)
		x_angle = -x_angle;
	if (vec.x > 0)
		z_angle = -z_angle;
	m = m_prod(rotation_z_rad(z_angle), rotation_x_rad(x_angle));
	return (m);
}
