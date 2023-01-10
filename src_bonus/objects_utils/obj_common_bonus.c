/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_common.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:14:50 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/18 19:21:32 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	new_element(t_element *e)
{
	ft_memset(e, 0, sizeof(t_element));
	e->coord.w = 1;
	e->height = 1;
	e->color.x = 255;
	e->color.y = 255;
	e->color.z = 255;
	e->color.w = 1;
	e->diffuse = 0.9;
	e->specular = 0.6;
	e->shiny = 200;
}

bool	is_in_object(double hits[2])
{
	if (hits[0] < N_EPSILON && hits[1] < N_EPSILON)
		return (false);
	if (hits[0] >= N_EPSILON && hits[1] >= N_EPSILON)
		return (false);
	return (true);
}

double	get_smallest_intersect(double i, double k)
{
	if (i < N_EPSILON)
		i = INFINITY;
	if (k < N_EPSILON)
		k = INFINITY;
	if (i < k)
		return (i);
	return (k);
}

char	**check(t_rt *f, char *input, char *pattern)
{
	int		ret;
	char	**data;

	ret = tx_line_match_pattern(input, pattern, f->index_line);
	if (ret == TX_MALLOC)
		rt_exit(f, 1, "malloc");
	if (ret == TX_FAIL)
		rt_exit(f, 3, "error rt file");
	data = ft_split_set(input, "\n\t ,");
	if (data == NULL)
		rt_exit(f, 1, "malloc");
	return (data);
}
