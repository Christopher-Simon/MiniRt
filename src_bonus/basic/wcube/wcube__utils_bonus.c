/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube__utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:45:18 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 19:42:20 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	cw(t_rt *f, t_2Dpoint p, t_2Dvector v, t_3Dpoint *head)
{
	do_cuboid(f, pos(head->x + p.x * 2 + v.x - 1, \
					head->y - p.y * 2 - v.y - 1, head->z), \
					vec(0, 0, 1), \
					sc(v.x, v.y, 1));
}

void	row(t_rt *f, t_2Dpoint p, t_3Dpoint *head, t_lenght xlen)
{
	t_2Dvector	v;

	v.x = xlen;
	v.y = 1;
	cw(f, p, v, head);
}

void	col(t_rt *f, t_2Dpoint p, t_3Dpoint *head, t_lenght ylen)
{
	t_2Dvector	v;

	v.x = 1;
	v.y = ylen;
	cw(f, p, v, head);
}

void	one(t_rt *f, t_2Dpoint p, t_3Dpoint *head)
{
	t_2Dvector	v;

	v.x = 1;
	v.y = 1;
	cw(f, p, v, head);
}

t_2Dpoint	p2(double x, double y)
{
	t_2Dpoint	p;

	p.x = x;
	p.y = y;
	return (p);
}
