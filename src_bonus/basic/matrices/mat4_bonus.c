/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mat4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 11:34:52 by chsimon           #+#    #+#             */
/*   Updated: 2022/10/24 04:11:23 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	print_matrix4(t_matx4 m)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			printf("%5.5f ", m.m[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	fill_matrix4(t_matx4 *m, double M[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			m->m[i][j] = M[i][j];
			j++;
		}
		i++;
	}
}

t_matx4	m_prod(t_matx4 a, t_matx4 b)
{
	t_matx4	m;
	int		row;
	int		col;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			m.m[row][col] = a.m[row][0] * b.m[0][col] + \
				a.m[row][1] * b.m[1][col] + \
				a.m[row][2] * b.m[2][col] + \
				a.m[row][3] * b.m[3][col];
			col++;
		}
		row++;
	}
	return (m);
}

t_matx4	identity_matrice(void)
{
	t_matx4	m;

	ft_bzero(&m, sizeof(m));
	m.m[0][0] = 1;
	m.m[1][1] = 1;
	m.m[2][2] = 1;
	m.m[3][3] = 1;
	return (m);
}

t_matx4	transpose_matrice(t_matx4 m)
{
	t_matx4	t;
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			t.m[i][j] = m.m[j][i];
			j++;
		}
		i++;
	}
	return (t);
}
