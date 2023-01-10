/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inverse_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 07:39:49 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/20 07:42:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

double	cofactor_4(t_matx4 M, int row, int col)
{
	double	res;

	res = determinant_3(submatrix4(M, row, col), 0);
	if ((row + col) % 2)
		res *= -1;
	return (res);
}

double	determinant_4(t_matx4 M, int row)
{
	double	res;
	int		i;

	i = 0;
	res = 0;
	while (i < 4)
	{
		res += (M.m[row][i] * cofactor_4(M, row, i));
		i++;
	}
	return (res);
}

int	is_invertible(t_matx4 M)
{
	if (determinant_4(M, 0) == 0)
		return (0);
	return (1);
}

t_matx4	inverse_matrix(t_matx4	M)
{
	t_matx4	mat;
	int		row;
	int		col;
	double	determinant;

	determinant = determinant_4(M, 0);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			mat.m[col][row] = cofactor_4(M, row, col) / determinant;
			col++;
		}
		row++;
	}
	return (mat);
}
