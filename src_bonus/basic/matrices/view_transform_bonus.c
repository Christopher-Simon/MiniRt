/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:41:36 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/13 20:54:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

typedef struct s_3_vecs
{
	t_tuple	up;
	t_tuple	left;
}	t_3_vecs;

t_3_vecs	get_3_vecs_spe(t_tuple forward, double dot)
{
	t_3_vecs	vec;

	if (dot == -1)
		vec.up = set_vector(0, 0, 1);
	else
		vec.up = set_vector(0, 0, -1);
	vec.left = normalisation(cross_prdt(forward, vec.up));
	return (vec);
}

t_3_vecs	get_3_vecs(t_tuple forward, double dot, t_tuple up)
{
	t_3_vecs	vec;

	if (dot == -1 || dot == 1)
		return (get_3_vecs_spe(forward, dot));
	vec.left = normalisation(cross_prdt(forward, up));
	vec.up = normalisation(cross_prdt(vec.left, forward));
	return (vec);
}

t_matx4	view_transform(t_tuple from, t_tuple forward)
{
	t_3_vecs	vec;
	t_tuple		up;
	t_matx4		result;
	double		dot;

	if (forward.w)
		log_printf("forward not a vector");
	up = set_vector(0, 1, 0);
	dot = dot_prdt(forward, up);
	vec = get_3_vecs(forward, dot, up);
	ft_bzero(&result, sizeof(t_matx4));
	result.m[0][0] = vec.left.x;
	result.m[0][1] = vec.left.y;
	result.m[0][2] = vec.left.z;
	result.m[1][0] = vec.up.x;
	result.m[1][1] = vec.up.y;
	result.m[1][2] = vec.up.z;
	result.m[2][0] = negating_tuple(forward).x;
	result.m[2][1] = negating_tuple(forward).y;
	result.m[2][2] = negating_tuple(forward).z;
	result.m[3][3] = 1;
	from = negating_tuple(from);
	return (m_prod(result, translation(from.x, from.y, from.z)));
}
