/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 02:42:29 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/04 18:00:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

#ifndef WIN_SIZE_X
# define WIN_SIZE_X 800
#endif

#ifndef WIN_SIZE_Y
# define WIN_SIZE_Y 600
#endif

#ifndef WIN_TITLE
# define WIN_TITLE "undefine WIN_TITLE"
#endif

static int	smlx_new_window(t_smlx *mlx)
{
	mlx->win_x = WIN_SIZE_X;
	mlx->win_y = WIN_SIZE_Y;
	if (mlx->win_x < 100 || mlx->win_y < 100)
		return (1);
	mlx->win = mlx_new_window(mlx->id, mlx->win_x, mlx->win_y, WIN_TITLE);
	if (!mlx->win)
		return (1);
	return (0);
}

static int	smlx_new_image(t_smlx *mlx, t_img *img, int idn)
{
	img->idn = idn;
	img->width = mlx->win_x;
	img->height = mlx->win_y;
	if (mlx->win_x < 1 || mlx->win_y < 1)
		return (1);
	img->id = mlx_new_image(mlx->id, mlx->win_x, mlx->win_y);
	if (!img->id)
		return (1);
	img->addr = mlx_get_data_addr(img->id, &img->bpp, &img->len, &img->end);
	if (!img->addr)
		return (1);
	img->title = ft_itoa(idn);
	if (!img->title)
		return (1);
	return (0);
}

int	smlx_init(t_smlx *mlx, int nb_img)
{
	int	i;

	ft_memset(mlx, 0, sizeof(t_smlx));
	mlx->id = mlx_init();
	if (!mlx->id)
		return (1);
	if (smlx_new_window(mlx))
		return (1);
	mlx->nb_img = nb_img;
	if (mlx->nb_img < 1)
		return (1);
	mlx->img = ft_calloc(sizeof(t_img) * mlx->nb_img);
	if (!mlx->img)
		return (1);
	i = 0;
	while (i < mlx->nb_img)
	{
		if (smlx_new_image(mlx, &mlx->img[i], i))
			return (1);
		i++;
	}
	return (0);
}
