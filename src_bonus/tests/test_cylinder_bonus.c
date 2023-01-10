/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:42:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 05:41:53 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	test_cyl_normal(void)
{
	t_obj	ob;

	ob.hit = INFINITY;
	assert_tuple("01", cylinder_normal(&ob, pos(1, 0.5, -0.8)), vec(1, 0, 0));
	assert_tuple("02", cylinder_normal(&ob, pos(-1, -0.2, 0.9)), vec(-1, 0, 0));
	assert_tuple("03", cylinder_normal(&ob, pos(-0.4, 1, -0.1)), vec(0, 1, 0));
	assert_tuple("04", cylinder_normal(&ob, pos(0.3, -1, -0.7)), vec(0, -1, 0));
	assert_tuple("05", cylinder_normal(&ob, pos(-0.6, 0.3, 1)), vec(0, 0, 1));
	assert_tuple("06", cylinder_normal(&ob, pos(0.4, 0.4, -1)), vec(0, 0, -1));
	assert_tuple("07", cylinder_normal(&ob, pos(1, 1, 1)), vec(1, 0, 0));
	assert_tuple("08", cylinder_normal(&ob, pos(-1, -1, -1)), vec(-1, 0, 0));
}

static void	test(char *id, int inter, t_tuple origin, t_tuple direction)
{
	t_obj	ob;

	ob.hit = INFINITY;
	ob.hits[0] = INFINITY;
	ob.hits[1] = INFINITY;
	if (cylinder_intersection(&ob, get_ray(origin, direction)))
	{
		if (inter)
			printf("\033[32m%s.OK ", id);
		else
			printf("\033[31m%s.KO ", id);
		printf("INTERSECT\t");
	}
	else
	{
		if (inter)
			printf("\033[32m%s.OK ", id);
		else
			printf("\033[31m%s.KO ", id);
		printf("MISS     \t");
	}
	printf("%8g, %8g, %8g | ", origin.x, origin.y, origin.z);
	printf("%8g, %8g, %8g | ", direction.x, direction.y, direction.z);
	printf("h1 %8g, h2 %8g\033[0m\n", ob.hits[0], ob.hits[1]);
}

#define MISS 0
#define INTER 1

void	test_cyl_intersection(void)
{
	test("01", MISS, pos(0, 1.5, 0), vec(0.1, 1, 0));
	test("02", MISS, pos(0, 3, -5), vec(0, 0, 1));
	test("03", MISS, pos(0, 0, -5), vec(0, 0, 1));
	test("04", MISS, pos(0, 2, -5), vec(0, 0, 1));
	test("05", MISS, pos(0, 1, -5), vec(0, 0, 1));
	test("06", INTER, pos(0, 1.5, -2), vec(0, 0, 1));
}
