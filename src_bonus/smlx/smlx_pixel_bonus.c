/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smlx_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 07:25:59 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 18:39:28 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	smlx_pixel(t_img *img, int x, int y, int hex_color)
{
	char			*dest;
	int				offset;
	unsigned int	color;

	color = hex_color;
	offset = y * img->len + x * (img->bpp / 8);
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}
