/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_normal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:43:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:14:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*
static t_tbn	tbn_spe(t_tuple normal, double dot)
{
	t_tbn	tbn;

	tbn.t = set_vector(1, 0, 0);
	(void)dot;
	// if (dot == 1)
	// 	tbn.b = normalisation(cross_prdt(normal, tbn.t));
	// else
		tbn.b = normalisation(cross_prdt(tbn.t, normal));
	return (tbn);
}
*/

static t_tbn	tbn_spe(t_tuple normal, double dot)
{
	t_tbn	tbn;

	tbn.t = set_vector(1, 0, 0);
	(void)dot;
	tbn.b = normalisation(cross_prdt(tbn.t, normal));
	return (tbn);
}

static t_tbn	init_tbn(t_tuple normal)
{
	t_tbn	tbn;
	t_tuple	z;
	double	dot;

	z = set_vector(0, 0, 1);
	dot = dot_prdt(z, normal);
	if (dot == 1 || dot == -1)
		return (tbn_spe(normal, dot));
	tbn.t = normalisation(cross_prdt(normal, z));
	tbn.b = normalisation(cross_prdt(tbn.t, normal));
	return (tbn);
}

static t_matx4	get_tbn(t_tuple normal)
{
	t_matx4	mat_tbn;
	t_tbn	tbn;

	mat_tbn = identity_matrice();
	tbn = init_tbn(normal);
	mat_tbn.m[0][0] = tbn.t.x;
	mat_tbn.m[0][1] = tbn.t.y;
	mat_tbn.m[0][2] = tbn.t.z;
	mat_tbn.m[1][0] = tbn.b.x;
	mat_tbn.m[1][1] = tbn.b.y;
	mat_tbn.m[1][2] = tbn.b.z;
	mat_tbn.m[2][0] = normal.x;
	mat_tbn.m[2][1] = normal.y;
	mat_tbn.m[2][2] = normal.z;
	return (mat_tbn);
}

static unsigned int	get_color(t_img *img, t_uv uv)
{
	unsigned int	color;
	char			*dest;
	unsigned int	x;
	unsigned int	y;

	x = round(uv.u * (img->width - 1));
	y = round(uv.v * (img->height - 1));
	dest = img->addr + x * (img->bpp / 8) \
		+ (img->height - y) * img->len;
	color = *(unsigned int *) dest;
	return (color);
}

t_tuple	uv_normal(t_img *img, t_uv uv, t_tuple normal)
{
	t_color	c;
	t_tuple	newtruc;

	c = norm_color(hex_to_rgb(get_color(img, uv)));
	c.x = c.x * 2 - 1;
	c.y = c.y * 2 - 1;
	c.z = c.z * 2 - 1;
	newtruc = normalisation(vec(c.x, c.y, c.z));
	return (normalisation(prod_matx_tuple(get_tbn(normal), newtruc)));
}
