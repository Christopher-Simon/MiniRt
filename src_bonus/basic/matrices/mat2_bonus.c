/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:12:36 by chsimon           #+#    #+#             */
/*   Updated: 2022/10/20 10:32:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_matrix2(t_matx2 m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			printf("%5.2f ", m.m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	fill_matrix2(t_matx2 *m, double M[2][2])
{
	int	i;
	int	j;

	i = 0;
	while (i < 2)
	{
		j = 0;
		while (j < 2)
		{
			m->m[i][j] = M[i][j];
			j++;
		}
		i++;
	}
}

t_matx2	submatrix3(t_matx3 m, int row, int col)
{
	t_matx2	res;
	int		i;
	int		j;
	int		r;
	int		c;

	i = -1;
	r = 0;
	while (++i < 3)
	{
		if (i == row)
			i++;
		j = 0;
		c = 0;
		while (j < 3)
		{
			if (j == col)
				j++;
			if (j == 3 || i == 3)
				break ;
			res.m[r][c++] = m.m[i][j++];
		}
		r++;
	}
	return (res);
}

double	determinant_2(t_matx2 m)
{
	return (m.m[0][0] * m.m[1][1] - m.m[0][1] * m.m[1][0]);
}
