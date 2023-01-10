/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:29:51 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:30:29 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_matx4	rotation_x(double degrees)
{
	t_matx4	mat;
	double	r;

	r = ft_deg_to_rad(degrees);
	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = 1;
	mat.m[1][1] = cos(r);
	mat.m[1][2] = -sin(r);
	mat.m[2][1] = sin(r);
	mat.m[2][2] = cos(r);
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	rotation_y(double degrees)
{
	t_matx4	mat;
	double	r;

	r = ft_deg_to_rad(degrees);
	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = cos(r);
	mat.m[0][2] = sin(r);
	mat.m[1][1] = 1;
	mat.m[2][0] = -sin(r);
	mat.m[2][2] = cos(r);
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	rotation_z(double degrees)
{
	t_matx4	mat;
	double	r;

	r = ft_deg_to_rad(degrees);
	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = cos(r);
	mat.m[0][1] = -sin(r);
	mat.m[1][0] = sin(r);
	mat.m[1][1] = cos(r);
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	return (mat);
}

t_matx4	m_rotation(t_tuple degrees)
{
	t_matx4	m;

	m = m_prod(rotation_z(degrees.z), rotation_y(degrees.y));
	m = m_prod(m, rotation_x(degrees.x));
	return (m);
}
