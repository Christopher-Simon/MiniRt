/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:22:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 12:05:21 by sloquet          ###   ########.fr       */
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
#define TX_NAME "tx_file"

bool	tx_file(int *i, char *input, char *p)
{
	if (ft_strcmp(p, TX_FILE))
		return (TX_OK);
	if (input[*i] != TX_FILE_SEP)
		return (tx_logr(TX_NAME, TX_FAIL));
	(*i)++;
	while (input[*i])
	{
		if (tx_isspace(input[*i], TX_SPACE_SET))
			return (tx_logr(TX_NAME, TX_FAIL));
		if (input[*i] == TX_FILE_SEP)
		{
			(*i)++;
			return (tx_logr(TX_NAME, TX_OK));
		}
		(*i)++;
	}
	return (tx_logr(TX_NAME, TX_FAIL));
}
