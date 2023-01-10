/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_klmno.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:10:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 07:01:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_k(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 5);
	one(f, p2(3, 0), h);
	one(f, p2(2, 1), h);
	one(f, p2(1, 2), h);
	one(f, p2(2, 3), h);
	one(f, p2(3, 4), h);
	h->x += 10;
	return (1);
}

int	wcube_l(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 5);
	row(f, p2(1, 4), h, 2);
	h->x += 8;
	return (1);
}

int	wcube_m(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 4);
	col(f, p2(2, 1), h, 2);
	col(f, p2(4, 1), h, 4);
	one(f, p2(1, 0), h);
	one(f, p2(3, 0), h);
	h->x += 12;
	return (1);
}

int	wcube_n(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 5);
	col(f, p2(3, 0), h, 5);
	one(f, p2(1, 2), h);
	one(f, p2(2, 3), h);
	h->x += 10;
	return (1);
}

int	wcube_o(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 3);
	col(f, p2(3, 1), h, 3);
	row(f, p2(1, 0), h, 2);
	row(f, p2(1, 4), h, 2);
	h->x += 10;
	return (1);
}
