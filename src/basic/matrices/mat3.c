/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 17:33:57 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/08 06:38:00 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	fill_matrix3(t_matx3 *m, double M[3][3])
{
	int	i;
	int	j;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m->m[i][j] = M[i][j];
			j++;
		}
		i++;
	}
}

t_matx3	submatrix4(t_matx4 m, int row, int col)
{
	t_matx3	res;
	int		i;
	int		j;
	int		r;
	int		c;

	i = -1;
	r = 0;
	while (++i < 4)
	{
		if (i == row)
			i++;
		j = 0;
		c = 0;
		while (j < 4)
		{
			if (j == col)
				j++;
			if (j == 4 || i == 4)
				break ;
			res.m[r][c++] = m.m[i][j++];
		}
		r++;
	}
	return (res);
}

double	minor(t_matx3 M, int row, int col)
{
	return (determinant_2(submatrix3(M, row, col)));
}

double	cofactor_3(t_matx3 M, int row, int col)
{
	double	res;

	res = minor(M, row, col);
	if (row + col % 2)
		res *= -1;
	return (res);
}

double	determinant_3(t_matx3 M, int row)
{
	double	res;
	int		i;

	i = 0;
	res = 0;
	while (i < 3)
	{
		res += (M.m[row][i] * cofactor_3(M, row, i));
		i++;
	}
	return (res);
}
