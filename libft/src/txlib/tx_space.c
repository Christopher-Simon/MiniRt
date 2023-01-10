/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:08:58 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

static bool	tx_isspace(int c, char *spaces_set)
{
	while (*spaces_set)
	{
		if (c == *spaces_set)
			return (true);
		spaces_set++;
	}
	return (false);
}

#undef TX_NAME
#define TX_NAME "tx_space"

bool	tx_space(int *i, char *input, char *p)
{
	if (p[0] != TX_SPACE || p[1] != TX_SPACE)
		return (TX_OK);
	if (0 == tx_isspace(input[*i], TX_SPACE_SET))
		return (tx_logr(TX_NAME, TX_FAIL));
	while (tx_isspace(input[*i], TX_SPACE_SET))
		(*i)++;
	return (tx_logr(TX_NAME, TX_OK));
}
