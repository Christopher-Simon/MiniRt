/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube__putstr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 06:53:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:00:36 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

//todo pointeur sur fonction
void	wcube_putstr(t_rt *f, char *str, t_wcube_mode mode)
{
	t_3Dpoint	h;
	char		c;

	h = wcube_setup(f, str, mode);
	if (!str || str[0] == ' ')
	{
		wcube_quest(f, &h);
		return ;
	}
	while (*str)
	{
		h.x += 1;
		c = *str;
		if (c >= 'A' && c <= 'Z')
			c += 32;
		if (c >= 'a' && c <= 'l')
			hook_abcdefghijkl(f, &h, c);
		else if (c >= 'm' && c <= 'x')
			hook_mnopqrstuvwx(f, &h, c);
		else if (c >= '0' && c <= '9')
			hook_0123456789(f, &h, c);
		else
			hook_yz_and_punct(f, &h, c);
		str++;
	}
}
