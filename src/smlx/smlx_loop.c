/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 20:07:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:25:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static int	key_press_st(int keycode, t_rt *f)
{
	if (keycode == ESCAPE)
		rt_exit(f, EXIT_SUCCESS, "exit_escape");
	if (MRT_PUTS_MODE == 0)
		return (0);
	if (ft_isalnum(keycode) || keycode == ' ')
		hook_wcube_add_char(keycode, f);
	if (keycode == ENTER)
		hook_wcube_update(f);
	return (0);
}

static int	exit_cross_st(t_rt *f)
{
	rt_exit(f, EXIT_SUCCESS, "exit_cross");
	return (0);
}

int	smlx_loop(t_rt *f)
{
	mlx_put_image_to_window(f->mlx.id, f->mlx.win, f->mlx.img[0].id, 0, 0);
	mlx_hook(f->mlx.win, 2, 1L << 0, &key_press_st, f);
	mlx_hook(f->mlx.win, 17, 0, &exit_cross_st, f);
	mlx_loop(f->mlx.id);
	return (0);
}
