/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_integer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:22:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

static bool	tx_integer_nolimit(int *i, char *input, char *p)
{
	if (p[2] != TX_RANGE_CLOSE)
		return (TX_OK);
	if (tx_digit_or_sign(i, input))
		return (TX_FAIL);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	return (TX_OK);
}

static bool	tx_integer_positive(int *i, char *input, char *p)
{
	if (p[2] != TX_POSITIVE)
		return (TX_OK);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	return (TX_OK);
}

static bool	tx_integer_ranged(int *i, char *input, char *p)
{
	int	value;
	int	min;
	int	max;

	if (p[2] == TX_RANGE_CLOSE || p[2] == TX_POSITIVE)
		return (TX_OK);
	value = tx_atoi(&input[*i], TX_AVAL);
	min = tx_atoi(&p[2], TX_AMIN);
	max = tx_atoi(tx_strchr((&p[2]) + 1, TX_RANGE_SEP) + 1, TX_AMAX);
	if (min >= 0 && input[*i] == '-')
		return (TX_FAIL);
	if (tx_digit_or_sign(i, input))
		return (TX_FAIL);
	if (tx_strict_digit(i, input))
		return (TX_FAIL);
	if (tx_notin_range(value, min, max))
		return (TX_FAIL);
	return (TX_OK);
}

#undef TX_NAME
#define TX_NAME "tx_integer"

bool	tx_integer(int *i, char *input, char *p)
{
	if (p[0] != TX_INTEGER || p[1] != TX_RANGE_OPEN)
		return (TX_OK);
	if (tx_integer_overflow(i, input))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_integer_nolimit(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_integer_positive(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_integer_ranged(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	return (tx_logr(TX_NAME, TX_OK));
}
