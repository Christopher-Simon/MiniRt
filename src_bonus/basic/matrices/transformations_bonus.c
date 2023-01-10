/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 18:15:07 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/09 14:32:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_matx4	translation(double x, double y, double z)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = 1;
	mat.m[1][1] = 1;
	mat.m[2][2] = 1;
	mat.m[3][3] = 1;
	mat.m[0][3] = x;
	mat.m[1][3] = y;
	mat.m[2][3] = z;
	return (mat);
}

t_matx4	scaling(double x, double y, double z)
{
	t_matx4	mat;

	ft_bzero(&mat, sizeof(mat));
	mat.m[0][0] = x;
	mat.m[1][1] = y;
	mat.m[2][2] = z;
	mat.m[3][3] = 1;
	return (mat);
}

t_tuple	prod_matx_tuple(t_matx4 mat, t_tuple tup)
{
	t_tuple	res;

	res.x = mat.m[0][0] * tup.x + \
		mat.m[0][1] * tup.y + \
		mat.m[0][2] * tup.z + \
		mat.m[0][3] * tup.w;
	res.y = mat.m[1][0] * tup.x + \
		mat.m[1][1] * tup.y + \
		mat.m[1][2] * tup.z + \
		mat.m[1][3] * tup.w;
	res.z = mat.m[2][0] * tup.x + \
		mat.m[2][1] * tup.y + \
		mat.m[2][2] * tup.z + \
		mat.m[2][3] * tup.w;
	res.w = mat.m[3][0] * tup.x + \
		mat.m[3][1] * tup.y + \
		mat.m[3][2] * tup.z + \
		mat.m[3][3] * tup.w;
	return (res);
}

void	obj_transform(t_obj *obj, t_matx4 M)
{
	obj->m = m_prod(obj->m, M);
}
