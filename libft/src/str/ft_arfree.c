/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arfree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:52:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/04 13:05:26 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_str.h"

/**
 *  free char**
 * 	0 on success
 * 	-1 if array == NULL
 */
int	ft_arfree(char **array)
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

int	ft_arfree_2(void **array, size_t i)
{
	size_t	j;

	j = 0;
	if (!array)
		return (-1);
	while (j < i)
	{
		free(array[j]);
		j++;
	}
	free(array);
	return (0);
}
