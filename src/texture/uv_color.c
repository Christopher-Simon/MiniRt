/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 18:41:13 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:10:14 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/*
	if (x > (unsigned int)img->width || y > (unsigned int)img->height)
		return (BLACK);
*/

static unsigned int	get_color(t_img *img, t_uv uv)
{
	unsigned int	color;
	char			*dest;
	unsigned int	x;
	unsigned int	y;

	x = round(uv.u * (img->width - 1));
	y = round(uv.v * (img->height - 1));
	dest = img->addr + x * (img->bpp / 8) \
		+ (img->height - y) * img->len;
	color = *(unsigned int *) dest;
	return (color);
}

t_color	uv_color(t_img *img, t_uv uv)
{
	return (norm_color(hex_to_rgb(get_color(img, uv))));
}
