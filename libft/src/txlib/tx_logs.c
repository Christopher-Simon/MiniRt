/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_logs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 03:00:52 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 12:40:40 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

void	tx_log(const char *msg)
{
	if (!TX_VERBOSE)
		return ;
	if (TX_COLOR)
		printf(" \033[33m%s\033[0m\n", msg);
	else
		printf(" %s\n", msg);
}

void	tx_logv(const char *msg, bool value)
{
	if (!TX_VERBOSE)
		return ;
	if (TX_COLOR)
	{
		if (value == TX_OK)
			printf(" \033[32m OK\033[0m  %s()\n", msg);
		if (value == TX_FAIL)
			printf("\033[31m FAIL\033[0m %s()\n", msg);
	}
	else
	{
		if (value == TX_OK)
			printf("  OK  %s()\n", msg);
		if (value == TX_FAIL)
			printf(" FAIL %s()\n", msg);
	}
}

bool	tx_logr(const char *msg, bool value)
{
	tx_logv(msg, value);
	return (value);
}

void	tx_log_invalid_symbol(int i, char *input, int k)
{
	if (!TX_VERBOSE)
		return ;
	printf("invalid symbol line %i: Hex[%x] Dec[%d]\n", k, input[i], input[i]);
}
