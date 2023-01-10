/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_line_match_pattern.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:51:09 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 18:51:10 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

static int	tx_arfree(char **array)
{
	int	i;

	if (!array)
		return (-1);
	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}

static	void	log_intput(int *i, char *input, char *p, int k)
{
	if (!TX_VERBOSE)
		return ;
	printf("input    %3i:%3i:[%.9s]...\n", k, *i, &input[*i]);
	printf(" \033[32m OK\033[0m  pattern  [%s]\n", p);
}

static	void	log_output(int *i, char *input, int k)
{
	if (!TX_VERBOSE)
		return ;
	printf("output   %3i:%3i:[%.9s]...\n\n", k, *i, &input[*i]);
}

static bool	tx_aline(int *i, char *input, char *p, int k)
{
	log_intput(i, input, p, k);
	if (tx_space(i, input, p))
		return (TX_FAIL);
	if (tx_comma(i, input, p))
		return (TX_FAIL);
	if (tx_float(i, input, p))
		return (TX_FAIL);
	if (tx_integer(i, input, p))
		return (TX_FAIL);
	if (tx_word(i, input, p))
		return (TX_FAIL);
	if (tx_file(i, input, p))
		return (TX_FAIL);
	if (tx_choice(i, input, p))
		return (TX_FAIL);
	log_output(i, input, k);
	return (TX_OK);
}

#undef TX_NAME
#define TX_NAME "tx_line_match_pattern"

int	tx_line_match_pattern(char *input, char *pattern, int k)
{
	char	**regex;
	int		i;
	int		p;

	regex = tx_split(pattern, pattern[0]);
	if (!regex)
		return (TX_MALLOC);
	i = 0;
	p = 0;
	while (regex[p])
	{
		if (tx_aline(&i, input, regex[p], k))
			break ;
		p++;
	}
	if ((input[i] && input[i] != '\n') || regex[p])
	{
		tx_arfree(regex);
		tx_log_invalid_symbol(i, input, k);
		return (tx_logr(TX_NAME, TX_FAIL));
	}
	tx_arfree(regex);
	return (tx_logr(TX_NAME, TX_OK));
}
