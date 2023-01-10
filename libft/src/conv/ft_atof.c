/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 03:46:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/29 07:07:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_conv.h"

static double	_get_fractional_part(const char *str)
{
	double	fractional_part;
	int		nb_zero;

	fractional_part = 0;
	nb_zero = 0;
	while (*str == '0')
	{
		nb_zero++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		fractional_part *= 10;
		fractional_part += *str - 48;
		nb_zero++;
		str++;
	}
	while (nb_zero)
	{
		fractional_part /= 10.0;
		nb_zero--;
	}
	return (fractional_part);
}

double	ft_atof(const char *str)
{
	double	nbr;
	double	sign;

	nbr = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (*str == '.')
		nbr += _get_fractional_part(str + 1);
	return (nbr * sign);
}
