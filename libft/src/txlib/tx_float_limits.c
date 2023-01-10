/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_float_limits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:08:24 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:54 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

#undef TX_NAME
#define TX_NAME "tx_float_overflow"

bool	tx_float_overflow(int *i, char *input)
{
	t_longd	value;
	int		k;

	k = 0;
	while (tx_isdigit(input[*i + k]))
		k++;
	if (k > 10)
		return (tx_logr(TX_NAME, TX_FAIL));
	value = tx_atold(&input[*i], TX_AVAL);
	if (value < INT_MIN || value > INT_MAX)
		return (tx_logr(TX_NAME, TX_FAIL));
	return (tx_logr(TX_NAME, TX_OK));
}
