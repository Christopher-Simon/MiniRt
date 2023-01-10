/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_integer_limits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:07:07 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

#undef TX_NAME
#define TX_NAME "tx_integer_overflow"

bool	tx_integer_overflow(int *i, char *input)
{
	t_llong	value;
	int		k;

	k = 0;
	while (tx_isdigit(input[*i + k]))
		k++;
	if (k > 10)
		return (tx_logr(TX_NAME, TX_FAIL));
	value = tx_atoll(&input[*i], TX_AVAL);
	if (value < INT_MIN || value > INT_MAX)
		return (tx_logr(TX_NAME, TX_FAIL));
	return (tx_logr(TX_NAME, TX_OK));
}
