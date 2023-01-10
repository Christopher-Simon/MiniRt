/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_float.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:57:06 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:52 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

#undef TX_NAME
#define TX_NAME "tx_fractional_part"

static bool	tx_fractional_part(int *i, char *input)
{
	if (input[*i] == '.')
	{
		(*i)++;
		if (false == tx_isdigit(input[*i]))
			return (tx_logr(TX_NAME, TX_FAIL));
		while (tx_isdigit(input[*i]))
			(*i)++;
	}
	return (tx_logr(TX_NAME, TX_OK));
}

static bool	tx_float_nolimit(int *i, char *input, char *p)
{
	if (p[2] != TX_RANGE_CLOSE)
		return (TX_OK);
	if (tx_digit_or_sign(i, input))
		return (TX_FAIL);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	if (tx_fractional_part(i, input))
		return (TX_FAIL);
	return (TX_OK);
}

static bool	tx_float_positive(int *i, char *input, char *p)
{
	if (p[2] != TX_POSITIVE)
		return (TX_OK);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	if (tx_fractional_part(i, input))
		return (TX_FAIL);
	return (TX_OK);
}

bool	tx_float_ranged(int *i, char *input, char *p)
{
	double	value;
	double	min;
	double	max;

	if (p[2] == TX_RANGE_CLOSE || p[2] == TX_POSITIVE)
		return (TX_OK);
	value = tx_atof(&input[*i], TX_AVAL);
	min = tx_atof(&p[2], TX_AMIN);
	max = tx_atof(tx_strchr((&p[2]) + 1, TX_RANGE_SEP) + 1, TX_AMAX);
	if (min >= 0 && input[*i] == '-')
		return (TX_FAIL);
	if (tx_digit_or_sign(i, input))
		return (TX_FAIL);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	if (tx_fractional_part(i, input))
		return (TX_FAIL);
	if (tx_notin_range(value, min, max))
		return (TX_FAIL);
	return (TX_OK);
}

#undef TX_NAME
#define TX_NAME "tx_float"

bool	tx_float(int *i, char *input, char *p)
{
	if (p[0] != TX_FLOAT || p[1] != TX_RANGE_OPEN)
		return (TX_OK);
	if (tx_float_overflow(i, input))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_float_nolimit(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_float_positive(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_float_ranged(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	return (tx_logr(TX_NAME, TX_OK));
}
