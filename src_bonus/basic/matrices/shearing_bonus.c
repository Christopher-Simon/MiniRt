/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 06:56:25 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/20 07:25:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_shx	shx(double x_y, double x_z)
{
	t_shx	shx;

	shx.y = x_y;
	shx.z = x_z;
	return (shx);
}

t_shy	shy(double y_x, double y_z)
{
	t_shy	shy;

	shy.x = y_x;
	shy.z = y_z;
	return (shy);
}

t_shz	shz(double z_x, double z_y)
{
	t_shz	shz;

	shz.x = z_x;
	shz.y = z_y;
	return (shz);
}

t_matx4	shear(t_shx shx, t_shy shy, t_shz shz)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = 1;
	mat.m[1][1] = 1;
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	mat.m[0][1] = shx.y;
	mat.m[0][2] = shx.z;
	mat.m[1][0] = shy.x;
	mat.m[1][2] = shy.z;
	mat.m[2][0] = shz.x;
	mat.m[2][1] = shz.y;
	return (mat);
}
