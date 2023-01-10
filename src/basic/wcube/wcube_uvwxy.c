/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_uvwxy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:10:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 07:01:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_u(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 4);
	col(f, p2(3, 0), h, 4);
	row(f, p2(1, 4), h, 2);
	h->x += 10;
	return (1);
}

int	wcube_v(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 3);
	col(f, p2(4, 0), h, 3);
	one(f, p2(1, 3), h);
	one(f, p2(3, 3), h);
	one(f, p2(2, 4), h);
	h->x += 12;
	return (1);
}

int	wcube_w(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 4);
	col(f, p2(4, 0), h, 4);
	col(f, p2(2, 1), h, 3);
	row(f, p2(1, 4), h, 3);
	h->x += 12;
	return (1);
}

int	wcube_x(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 2);
	col(f, p2(2, 0), h, 2);
	col(f, p2(0, 3), h, 2);
	col(f, p2(2, 3), h, 2);
	one(f, p2(1, 2), h);
	h->x += 8;
	return (1);
}

int	wcube_y(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 3);
	col(f, p2(2, 0), h, 3);
	col(f, p2(1, 2), h, 3);
	h->x += 8;
	return (1);
}
