/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 11:50:42 by chsimon           #+#    #+#             */
/*   Updated: 2022/11/18 19:16:39 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	sc_check_mode(t_rt *f)
{
	if (MRT_FILE_MODE != 0 && MRT_FILE_MODE != 1)
		rt_exit(f, 94, "invalid MRT_FILE_MODE value");
	if (MRT_CODE_MODE != 0 && MRT_CODE_MODE != 1)
		rt_exit(f, 93, "invalid MRT_CODE_MODE value");
	if (MRT_PUTS_MODE != 0 && MRT_PUTS_MODE != 1)
		rt_exit(f, 92, "invalid MRT_PUTS_MODE value");
	if (MRT_CODE_MODE + MRT_FILE_MODE + MRT_PUTS_MODE < 1)
		rt_exit(f, 91, "no mode actived");
	if (MRT_CODE_MODE + MRT_FILE_MODE + MRT_PUTS_MODE > 1)
		rt_exit(f, 90, "too many modes are active, need only one");
}

static void	sc_check_scene(t_rt *f)
{
	if (!MRT_FILE_MODE)
		return ;
	if (!f->cam)
		rt_exit(f, 2, "error sc_check_scene()");
	if (!f->ambient.active)
		do_ambient(f, 0, WHITE);
	if (!f->ob)
		do_sphere(f, pos(0, 0, 0), 0, WHITE);
}

int	main(int ac, char **av)
{
	t_rt	f;

	ft_bzero(&f, sizeof(t_rt));
	sc_check_mode(&f);
	parser(&f, ac, av);
	sc_check_scene(&f);
	if (smlx_init(&f.mlx, 1))
		rt_exit(&f, 1, "error mlx");
	the_return(&f);
	sc_check_scene(&f);
	obj_lst_getxpm(&f, f.ob);
	raytracing_each_pixel(&f);
	smlx_loop(&f);
	rt_exit(&f, 0, NULL);
	return (1);
}
