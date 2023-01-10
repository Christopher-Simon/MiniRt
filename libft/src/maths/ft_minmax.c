/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 09:05:55 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:09:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

/**
 *		a has priority if a == b
 */

long	ft_min(const long a, const long b)
{
	if (a <= b)
		return (a);
	return (b);
}

long	ft_max(const long a, const long b)
{
	if (a >= b)
		return (a);
	return (b);
}

double	ft_fmin(const double a, const double b)
{
	if (a <= b)
		return (a);
	return (b);
}

double	ft_fmax(const double a, const double b)
{
	if (a >= b)
		return (a);
	return (b);
}
