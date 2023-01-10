/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_choice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:08 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 16:17:46 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

static bool	tx_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

#undef TX_NAME
#define TX_NAME "tx_arcmp"

static bool	tx_arcmp(int *i, char *input, char *p)
{
	char	**splitted;
	char	*name;
	int		k;

	name = &input[*i];
	k = 0;
	while (tx_isalpha(input[*i + k]) || input[*i + k] == '_')
		k++;
	name = ft_strldup(name, k + 1);
	if (name == NULL)
		return (tx_logr(TX_NAME, TX_FAIL));
	splitted = tx_split(p, TX_CHOICE);
	if (!splitted)
		return (free(name), tx_logr(TX_NAME, TX_FAIL));
	k = 0;
	while (splitted[k])
	{
		if (TX_VERBOSE)
			printf("          : %s('%s' == '%s')\n", \
				TX_NAME, name, splitted[k]);
		if (0 == ft_strcmp(splitted[k], name))
			return (ft_arfree(splitted), free(name), tx_logr(TX_NAME, TX_OK));
		k++;
	}
	return (ft_arfree(splitted), free(name), tx_logr(TX_NAME, TX_FAIL));
}

#undef TX_NAME
#define TX_NAME "tx_choice"

bool	tx_choice(int *i, char *input, char *p)
{
	if (p[0] != TX_CHOICE)
		return (TX_OK);
	if (0 == tx_isalpha(input[*i]))
		return (tx_logr(TX_NAME, TX_FAIL));
	if (tx_arcmp(i, input, p))
		return (tx_logr(TX_NAME, TX_FAIL));
	while (tx_isalpha(input[*i]) || input[*i] == '_')
		(*i)++;
	return (tx_logr(TX_NAME, TX_OK));
}
