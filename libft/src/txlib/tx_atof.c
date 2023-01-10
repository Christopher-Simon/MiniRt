/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:49:33 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 12:41:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

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

double	tx_atof(const char *str, const char *msg)
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
	if (TX_VERBOSE)
		printf(" \033[32m OK\033[0m  tx_atof(%s)->(%f)\n"\
			, msg, nbr * sign);
	return (nbr * sign);
}
