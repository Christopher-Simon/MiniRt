/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_wcube.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:24:30 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:26:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	update_buffer(t_rt *f)
{
	if (f->wcub.txt_buffer)
	{
		if (f->wcub.txt_buffer_old)
		{
			free(f->wcub.txt_buffer_old);
			f->wcub.txt_buffer_old = ft_strdup(f->wcub.txt_buffer);
		}
		free(f->wcub.txt_buffer);
		f->wcub.txt_buffer = NULL;
	}
}

void	hook_wcube_update(t_rt *f)
{
	if (!f->wcub.txt_buffer && !f->wcub.txt_buffer_old)
		return ;
	if (f->wcub.txt_buffer && f->wcub.txt_buffer_old)
	{
		if (0 == ft_strcmp(f->wcub.txt_buffer, f->wcub.txt_buffer_old))
			return ;
	}
	sc_cam_list_destroy(&f->cam);
	sc_shape_list_destroy(f, &f->ob);
	sc_light_list_destroy(&f->li);
	if (f->mlx.img[0].id)
		mlx_destroy_image(f->mlx.id, f->mlx.img[0].id);
	mlx_clear_window(f->mlx.id, f->mlx.win);
	f->mlx.img[0].id = mlx_new_image(f->mlx.id, f->mlx.win_x, f->mlx.win_y);
	if (!f->mlx.img[0].id)
		rt_exit(f, 33, "mlx_new_image() failed");
	the_return(f);
	raytracing_each_pixel(f);
	mlx_put_image_to_window(f->mlx.id, f->mlx.win, f->mlx.img[0].id, 0, 0);
	update_buffer(f);
}

void	hook_wcube_add_char(int keycode, t_rt *f)
{
	char	*new;

	if (f->wcub.txt_buffer)
	{
		new = ft_strjoin(f->wcub.txt_buffer, ".");
		free(f->wcub.txt_buffer);
	}
	else
		new = ft_strdup(".");
	new[ft_strlen(new) - 1] = keycode;
	f->wcub.txt_buffer = new;
}
