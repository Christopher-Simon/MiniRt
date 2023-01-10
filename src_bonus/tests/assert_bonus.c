/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 07:29:53 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/14 01:14:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	print_matrix4_diff(t_matx4 m, t_matx4 q)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (ft_fequal(m.m[i][j], q.m[i][j]))
				printf("\e[1;33m%5.5f \e[0m", m.m[i][j]);
			else
				printf("%5.5f ", m.m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	assert_matrix(char *id, t_matx4 a, t_matx4 b)
{
	int		x;
	int		y;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (ft_fequal(a.m[y][x], b.m[y][x]))
			{
				printf("%s\n", id);
				printf("\e[1;33m%s.KO matrices differ\n\e[0m", id);
				print_matrix4_diff(a, b);
				print_matrix4_diff(b, a);
				return ;
			}
			x++;
		}
		y++;
	}
	printf("\e[1;32m%s.OK matrices are equal\n", id);
	c_reset();
}

void	assert_tuple(char *id, t_tuple a, t_tuple b)
{
	if (a.w == b.w && a.x == b.x && a.y == b.y && a.z == b.z)
	{
		printf("\033[32m%s.OK ", id);
		printf("IS EQUAL \t");
	}
	else
	{
		printf("\033[31m%s.KO ", id);
		printf("IS DIFF  \t");
	}
	printf("%8g, %8g, %8g | %8g, %8g, %8g", a.x, a.y, a.z, b.x, b.y, b.z);
	printf("\033[0m\n");
}
