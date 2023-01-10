/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 01:36:22 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:32:33 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

char	*tx_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int	tx_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

#undef TX_NAME
#define TX_NAME "tx_notin_range"

bool	tx_notin_range(double value, double min, double max)
{
	if (value < min || value > max)
		return (tx_logr(TX_NAME, TX_FAIL));
	return (tx_logr(TX_NAME, TX_OK));
}

#undef TX_NAME
#define TX_NAME "tx_digit_or_sign"

bool	tx_digit_or_sign(int *i, char *input)
{
	if (false == tx_isdigit(input[*i]) && input[*i] != '-')
		return (tx_logr(TX_NAME, TX_FAIL));
	if (input[*i] == '-')
		(*i)++;
	return (tx_logr(TX_NAME, TX_OK));
}

#undef TX_NAME
#define TX_NAME "tx_strict_digit"

bool	tx_strict_digit(int *i, char *input)
{
	if (false == tx_isdigit(input[*i]))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (TX_FRONT_ZERO)
	{
		if (input[*i] == '0' && tx_isdigit(input[*i + 1]))
			return (tx_logr(TX_NAME, TX_FAIL));
	}
	else
		tx_log("check TX_FRONT_ZERO -> DISABLED");
	while (tx_isdigit(input[*i]))
		(*i)++;
	return (tx_logr(TX_NAME, TX_OK));
}
