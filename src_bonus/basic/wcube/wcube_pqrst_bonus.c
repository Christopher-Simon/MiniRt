/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_pqrst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:10:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 07:01:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_p(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 4);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 2), h, 2);
	one(f, p2(3, 1), h);
	h->x += 10;
	return (1);
}

int	wcube_q(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 3);
	col(f, p2(3, 1), h, 3);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 4), h, 2);
	one(f, p2(4, 4), h);
	h->x += 12;
	return (1);
}

int	wcube_r(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 4);
	col(f, p2(3, 3), h, 2);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 2), h, 2);
	one(f, p2(3, 1), h);
	h->x += 10;
	return (1);
}

int	wcube_s(t_rt *f, t_3Dpoint *h)
{
	row(f, p2(1, 0), h, 3);
	row(f, p2(1, 2), h, 2);
	row(f, p2(0, 4), h, 3);
	one(f, p2(0, 1), h);
	one(f, p2(3, 3), h);
	h->x += 10;
	return (1);
}

int	wcube_t(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(1, 1), h, 4);
	row(f, p2(0, 0), h, 3);
	h->x += 8;
	return (1);
}
