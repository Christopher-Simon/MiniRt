/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 01:42:02 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 05:54:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	test_cub_normal(void)
{
	assert_tuple("01", cuboid_normal(NULL, pos(1, 0.5, -0.8)), vec(1, 0, 0));
	assert_tuple("02", cuboid_normal(NULL, pos(-1, -0.2, 0.9)), vec(-1, 0, 0));
	assert_tuple("03", cuboid_normal(NULL, pos(-0.4, 1, -0.1)), vec(0, 1, 0));
	assert_tuple("04", cuboid_normal(NULL, pos(0.3, -1, -0.7)), vec(0, -1, 0));
	assert_tuple("05", cuboid_normal(NULL, pos(-0.6, 0.3, 1)), vec(0, 0, 1));
	assert_tuple("06", cuboid_normal(NULL, pos(0.4, 0.4, -1)), vec(0, 0, -1));
	assert_tuple("07", cuboid_normal(NULL, pos(1, 1, 1)), vec(1, 0, 0));
	assert_tuple("08", cuboid_normal(NULL, pos(-1, -1, -1)), vec(-1, 0, 0));
}

static void	test(char *id, int inter, t_tuple origin, t_tuple direction)
{
	t_obj	obj;

	if (cuboid_intersection(&obj, get_ray(origin, direction)))
	{
		if (inter)
			printf("\033[32m%s.OK ", id);
		else
			printf("\033[31m%s.KO ", id);
		printf("INTERSECT\t");
	}
	else
	{
		if (inter == 0)
			printf("\033[32m%s.OK ", id);
		else
			printf("\033[31m%s.KO ", id);
		printf("MISS     \t");
	}
	printf("%8g, %8g, %8g | ", origin.x, origin.y, origin.z);
	printf("%8g, %8g, %8g", direction.x, direction.y, direction.z);
	printf("\033[0m\n");
}

#define MISS 0
#define INTER 1

void	test_cub_intersection(void)
{
	test("01", MISS, pos(-2, 0, 0), vec(0.2673, 0.5345, 0.8018));
	test("02", MISS, pos(0, -2, 0), vec(0.8018, 0.2673, 0.5345));
	test("03", MISS, pos(0, 0, -2), vec(0.5345, 0.8018, 0.2673));
	test("04", MISS, pos(2, 0, 2), vec(0, 0, -1));
	test("05", MISS, pos(0, 2, 2), vec(0, -1, 0));
	test("06", MISS, pos(2, 2, 0), vec(-1, 0, 0));
	printf("------------------------------\n");
	test("07", INTER, pos(5, 0.5, 0), vec(-1, 0, 0));
	test("08", INTER, pos(-5, 0.5, 0), vec(1, 0, 0));
	test("09", INTER, pos(0.5, 5, 0), vec(0, -1, 0));
	test("10", INTER, pos(0.5, -5, 0), vec(0, 1, 0));
	test("11", INTER, pos(0.5, 0, 5), vec(0, 0, -1));
	test("12", INTER, pos(0.5, 0, -5), vec(0, 0, 1));
	test("13", INTER, pos(0, 0.5, 0), vec(0, 0, 1));
}
