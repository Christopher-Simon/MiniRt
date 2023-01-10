/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 06:41:20 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/02 07:24:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	smlx_destroy(t_smlx *mlx)
{
	int	i;

	i = 0;
	while (i < mlx->nb_img)
	{
		if (mlx->img[i].id)
		{
			mlx_destroy_image(mlx->id, mlx->img[i].id);
			free(mlx->img[i].title);
		}
		mlx->img[i].id = NULL;
		mlx->img[i].title = NULL;
		i++;
	}
	free(mlx->img);
	mlx->nb_img = 0;
	mlx->img = NULL;
	if (mlx->win)
		mlx_destroy_window(mlx->id, mlx->win);
	mlx->win = NULL;
	if (mlx->id)
		mlx_destroy_display(mlx->id);
	free(mlx->id);
	mlx->id = NULL;
}
