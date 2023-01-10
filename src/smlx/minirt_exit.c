/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_exit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:49:25 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/20 16:14:18 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	rt_exit(t_rt *f, int code, char *msg)
{
	sc_shape_list_destroy(f, &f->ob);
	sc_light_list_destroy(&f->li);
	sc_cam_list_destroy(&f->cam);
	if (f->wcub.txt_buffer)
		free(f->wcub.txt_buffer);
	if (f->wcub.txt_buffer_old)
		free(f->wcub.txt_buffer_old);
	if (f->file)
		ft_arfree(f->file);
	smlx_destroy(&f->mlx);
	if (code)
		printf("Error\n");
	if (msg && (code || VERBOSE))
		printf("\033[1;33mEXIT %d : %s\033[0m\n", code, msg);
	if (VERBOSE)
		printf("BONUS %i\n", BONUS);
	exit(code);
}
