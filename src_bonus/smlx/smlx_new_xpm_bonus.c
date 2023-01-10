/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_new_xpm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:50:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:19:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	smlx_log(t_img *img)
{
	return ;
	printf("\nSMLX_NEW_XPM\n");
	printf("img.title  : [%s]\n", img->title);
	printf("img.id     : [%p]\n", img->id);
	printf("img.idn    : [%i]\n", img->idn);
	printf("img.addr   : [%p]\n", img->addr);
	printf("img.width  : [%i]\n", img->width);
	printf("img.height : [%i]\n", img->height);
}

int	smlx_new_xpm(t_smlx *mlx, t_img *img)
{
	if (img->title == NULL)
		return (0);
	img->id = mlx_xpm_file_to_image(mlx->id, img->title, \
		&img->width, &img->height);
	if (!img->id)
		return (1);
	img->addr = mlx_get_data_addr(img->id, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		return (1);
	smlx_log(img);
	return (0);
}
