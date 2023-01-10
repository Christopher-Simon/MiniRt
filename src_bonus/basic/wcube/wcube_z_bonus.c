/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_z.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:09:47 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/31 07:00:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

int	wcube_z(t_rt *f, t_3Dpoint *h)
{
	row(f, p2(0, 0), h, 4);
	row(f, p2(0, 4), h, 4);
	one(f, p2(2, 1), h);
	one(f, p2(1, 2), h);
	one(f, p2(0, 3), h);
	h->x += 10;
	return (1);
}

int	wcube_quest(t_rt *f, t_3Dpoint *h)
{
	row(f, p2(0, 0), h, 3);
	one(f, p2(2, 1), h);
	one(f, p2(1, 2), h);
	one(f, p2(1, 4), h);
	h->x += 8;
	return (1);
}

int	wcube_excla(t_rt *f, t_3Dpoint *h)
{
	col(f, p2(0, 0), h, 3);
	one(f, p2(0, 4), h);
	h->x += 4;
	return (1);
}

int	wcube_minus(t_rt *f, t_3Dpoint *h)
{
	row(f, p2(0, 2), h, 3);
	h->x += 8;
	return (1);
}

int	wcube_space(t_rt *f, t_3Dpoint *h)
{
	h->x += 12;
	return (1);
	(void)f;
}
