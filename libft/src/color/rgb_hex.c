/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 03:12:49 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/02 03:13:03 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_color.h"

int	rgb_to_hex(int r, int g, int b)
{
	return (((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff));
}

double	hex_to_rgb_r(int hex)
{
	double	r;

	r = ((hex >> 16) & 0xFF) / 255.0;
	return (r);
}

double	hex_to_rgb_g(int hex)
{
	double	g;

	g = ((hex >> 8) & 0xFF) / 255.0;
	return (g);
}

double	hex_to_rgb_b(int hex)
{
	double	b;

	b = ((hex) & 0xFF) / 255.0;
	return (b);
}
