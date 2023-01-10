/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_word.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 00:41:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:30 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

static bool	tx_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

#undef TX_NAME
#define TX_NAME "tx_word"

bool	tx_word(int *i, char *input, char *p)
{
	if (0 == tx_isalpha(p[0]) || p[1] == TX_RANGE_OPEN)
		return (TX_OK);
	if (0 == tx_isalpha(input[*i]))
		return (tx_logr(TX_NAME, TX_FAIL));
	while (tx_isalpha(input[*i]))
	{
		if (input[*i] != *p)
			return (tx_logr(TX_NAME, TX_FAIL));
		p++;
		(*i)++;
	}
	return (tx_logr(TX_NAME, TX_OK));
}
