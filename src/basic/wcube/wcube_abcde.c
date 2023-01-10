/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_abcde.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:10:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 06:59:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_a(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 4);
	col(f, p2(3, 1), h, 4);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 3), h, 2);
	h->x += 10;
	return (1);
}

int	wcube_b(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 5);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 2), h, 2);
	row(f, p2(1, 4), h, 2);
	one(f, p2(3, 1), h);
	one(f, p2(3, 3), h);
	h->x += 10;
	return (1);
}

int	wcube_c(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 3);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 4), h, 2);
	one(f, p2(3, 1), h);
	one(f, p2(3, 3), h);
	h->x += 10;
	return (1);
}

int	wcube_d(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 5);
	col(f, p2(3, 1), h, 3);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 4), h, 2);
	h->x += 10;
	return (1);
}

int	wcube_e(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 3);
	row(f, p2(1, 0), h, 3);
	row(f, p2(1, 2), h, 2);
	row(f, p2(1, 4), h, 3);
	h->x += 10;
	return (1);
}
