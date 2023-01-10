/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_01234.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:09:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 07:02:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_0(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 1), h, 3);
	col(f, p2(2, 1), h, 3);
	one(f, p2(1, 0), h);
	one(f, p2(1, 4), h);
	h->x += 8;
	return (1);
}

int	wcube_1(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(1, 0), h, 4);
	row(f, p2(0, 4), h, 3);
	one(f, p2(0, 1), h);
	h->x += 8;
	return (1);
}

int	wcube_2(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(2, 1), h, 2);
	row(f, p2(0, 0), h, 2);
	row(f, p2(0, 4), h, 3);
	one(f, p2(1, 2), h);
	one(f, p2(0, 3), h);
	h->x += 8;
	return (1);
}

int	wcube_3(t_rt *f, t_3Dpoint *h)
{
	row(f, p2(0, 0), h, 2);
	row(f, p2(0, 2), h, 2);
	row(f, p2(0, 4), h, 2);
	one(f, p2(2, 1), h);
	one(f, p2(2, 3), h);
	h->x += 8;
	return (1);
}

int	wcube_4(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(2, 0), h, 5);
	row(f, p2(0, 3), h, 3);
	one(f, p2(1, 1), h);
	one(f, p2(0, 2), h);
	one(f, p2(3, 3), h);
	h->x += 10;
	return (1);
}
