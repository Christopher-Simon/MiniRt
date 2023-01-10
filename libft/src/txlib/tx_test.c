/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_test.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:52:17 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/09 12:52:26 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

void	tx_test(char *input, char *pattern, int index_line)
{
	int	ret;

	ret = tx_line_match_pattern(input, pattern, index_line);
	if (ret == TX_MALLOC)
		exit(1);
	if (ret == TX_FAIL)
		printf("\033[1;31m FAILURE \033[0m\n");
	printf("\033[1;32m SUCCESS \033[0m\n");
}
