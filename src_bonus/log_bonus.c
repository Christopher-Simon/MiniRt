/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 05:34:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 18:15:21 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	log_element(t_element e, char *name, t_name n)
{
	if (!VERBOSE)
		return ;
	printf("%s\n", name);
	if (n > 0)
		printf("coord    : %.3f,%.3f,%.3f(%.3f)\n", \
						e.coord.x, e.coord.y, e.coord.z, e.coord.w);
	if (n == E_AMBIENT || n == E_LIGHT)
		printf("ratio    : %.3f\n", e.ratio);
	if (n == E_CAMERA)
		printf("fov      : %.3f\n", e.cam_fov);
	if (n > 2)
		printf("angle    : %.3f,%3f,%3f(%.3f)\n", \
						e.angle.x, e.angle.y, e.angle.z, e.angle.w);
	if (n == E_SPHERE || n == E_CYLINDER)
		printf("diameter : %.3f\n", e.diameter);
	if (n == E_CYLINDER)
		printf("height   : %.3f\n", e.height);
	if (n != E_CAMERA)
		printf("color    : %.3f,%.3f,%.3f(%.3f)\n", \
						e.color.x, e.color.y, e.color.z, e.color.w);
	if (n >= E_PLANE || n == E_SPHERE)
		printf("texture  : [%s]\nbumpmap  : [%s]\n", e.texfile, e.bumfile);
	printf("------------------------------\n");
}

void	log_printf(char *str, ...)
{
	va_list	ap;
	int		i;

	if (!VERBOSE)
		return ;
	i = 0;
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'f')
				printf("%f", va_arg(ap, double));
			if (str[i] == 'd')
				printf("%d", va_arg(ap, int));
		}
		else
			printf("%c", str[i]);
		i++;
	}
	va_end(ap);
}

void	log_tuple(t_tuple tup)
{
	log_printf("This tuple ");
	if (tup.w == 1)
		log_printf("is a point\n");
	else if (tup.w == 0)
		log_printf("is a vector\n");
	printf("x %4g		y %4g		z %4g\n", tup.x, tup.y, tup.z);
}
