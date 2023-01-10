/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_comma.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:18:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

#undef TX_NAME
#define TX_NAME "tx_comma"

bool	tx_comma(int *i, char *input, char *p)
{
	if (p[0] != TX_COMMA)
		return (TX_OK);
	if (input[*i] != TX_COMMA)
		return (tx_logr(TX_NAME, TX_FAIL));
	(*i)++;
	return (tx_logr(TX_NAME, TX_OK));
}
