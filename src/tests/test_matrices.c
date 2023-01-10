/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_matrices.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:08:40 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 05:42:47 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	test_matrices_diff(void)
{
	t_matx4	a;
	t_matx4	b;

	a = identity_matrice();
	b = identity_matrice();
	assert_matrix("1", a, b);
	a = identity_matrice();
	b = identity_matrice();
	a.m[0][0] = 0;
	assert_matrix("2", a, b);
	a = identity_matrice();
	b = identity_matrice();
	a.m[3][3] = 0;
	assert_matrix("3", a, b);
	a = identity_matrice();
	b = identity_matrice();
	a.m[3][3] = 1.000001;
	assert_matrix("4", a, b);
	a = identity_matrice();
	b = identity_matrice();
	a.m[3][3] = 1 + N_EPSILON;
	assert_matrix("5", a, b);
}
