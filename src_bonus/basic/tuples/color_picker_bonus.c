/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_picker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 23:24:56 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/08 06:31:43 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_color	color_picker_a(int i)
{
	if (i == 0)
		return (hex_to_rgb(INDIAN_RED));
	if (i == 1)
		return (hex_to_rgb(SALMON));
	if (i == 2)
		return (hex_to_rgb(RED));
	if (i == 3)
		return (hex_to_rgb(PINK));
	if (i == 4)
		return (hex_to_rgb(DEEP_PINK));
	if (i == 5)
		return (hex_to_rgb(CORAL));
	if (i == 6)
		return (hex_to_rgb(ORANGE));
	if (i == 7)
		return (hex_to_rgb(GOLD));
	if (i == 8)
		return (hex_to_rgb(YELLOW));
	return (hex_to_rgb(WHITE));
}

static t_color	color_picker_b(int i)
{
	if (i == 9)
		return (hex_to_rgb(ORCHID));
	if (i == 10)
		return (hex_to_rgb(MAGENTA));
	if (i == 11)
		return (hex_to_rgb(BLUE_VIOLET));
	if (i == 12)
		return (hex_to_rgb(INDIGO));
	if (i == 13)
		return (hex_to_rgb(SLATE_GRAY));
	if (i == 14)
		return (hex_to_rgb(WHITE));
	if (i == 15)
		return (hex_to_rgb(LIME));
	if (i == 16)
		return (hex_to_rgb(GREEN));
	return (hex_to_rgb(WHITE));
}

static t_color	color_picker_c(int i)
{
	if (i == 17)
		return (hex_to_rgb(YELLOW_GREEN));
	if (i == 18)
		return (hex_to_rgb(CYAN));
	if (i == 19)
		return (hex_to_rgb(LIGHT_SKY_BLUE));
	if (i == 20)
		return (hex_to_rgb(DARK_BLUE));
	if (i == 21)
		return (hex_to_rgb(BURLY_WOOD));
	if (i == 22)
		return (hex_to_rgb(BROWN));
	if (i == 23)
		return (hex_to_rgb(LIGHT_GRAY));
	if (i == 24)
		return (hex_to_rgb(BLACK));
	return (hex_to_rgb(WHITE));
}

t_color	color_picker(int i)
{
	if (i >= 0 && i <= 8)
		return (color_picker_a(i));
	if (i >= 9 && i <= 16)
		return (color_picker_b(i));
	if (i >= 17 && i <= 24)
		return (color_picker_c(i));
	printf("color_picker() bad value (%d)\n", i);
	return (hex_to_rgb(WHITE));
}
