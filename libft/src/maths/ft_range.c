/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 20:51:09 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/29 21:08:19 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

bool	in_range(double value, double min, double max)
{
	return (value >= min && value <= max);
}

bool	notin_range(double value, double min, double max)
{
	return (value < min || value > max);
}
