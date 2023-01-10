/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 02:32:45 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:01:02 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	hook_abcdefghijkl(t_rt *f, t_3Dpoint *h, char c)
{
	if (c == 'a' && wcube_a(f, h))
		return ;
	if (c == 'b' && wcube_b(f, h))
		return ;
	if (c == 'c' && wcube_c(f, h))
		return ;
	if (c == 'd' && wcube_d(f, h))
		return ;
	if (c == 'e' && wcube_e(f, h))
		return ;
	if (c == 'f' && wcube_f(f, h))
		return ;
	if (c == 'g' && wcube_g(f, h))
		return ;
	if (c == 'h' && wcube_h(f, h))
		return ;
	if (c == 'i' && wcube_i(f, h))
		return ;
	if (c == 'j' && wcube_j(f, h))
		return ;
	if (c == 'k' && wcube_k(f, h))
		return ;
	if (c == 'l' && wcube_l(f, h))
		return ;
	return ;
}

void	hook_mnopqrstuvwx(t_rt *f, t_3Dpoint *h, char c)
{
	if (c == 'm' && wcube_m(f, h))
		return ;
	if (c == 'n' && wcube_n(f, h))
		return ;
	if (c == 'o' && wcube_o(f, h))
		return ;
	if (c == 'p' && wcube_p(f, h))
		return ;
	if (c == 'q' && wcube_q(f, h))
		return ;
	if (c == 'r' && wcube_r(f, h))
		return ;
	if (c == 's' && wcube_s(f, h))
		return ;
	if (c == 't' && wcube_t(f, h))
		return ;
	if (c == 'u' && wcube_u(f, h))
		return ;
	if (c == 'v' && wcube_v(f, h))
		return ;
	if (c == 'w' && wcube_w(f, h))
		return ;
	if (c == 'x' && wcube_x(f, h))
		return ;
	return ;
}

void	hook_0123456789(t_rt *f, t_3Dpoint *h, char c)
{
	if (c == '0' && wcube_0(f, h))
		return ;
	if (c == '1' && wcube_1(f, h))
		return ;
	if (c == '2' && wcube_2(f, h))
		return ;
	if (c == '3' && wcube_3(f, h))
		return ;
	if (c == '4' && wcube_4(f, h))
		return ;
	if (c == '5' && wcube_5(f, h))
		return ;
	if (c == '6' && wcube_6(f, h))
		return ;
	if (c == '7' && wcube_7(f, h))
		return ;
	if (c == '8' && wcube_8(f, h))
		return ;
	if (c == '9' && wcube_9(f, h))
		return ;
	return ;
}

//todo add // * , ; {} () # + = / . < >
void	hook_yz_and_punct(t_rt *f, t_3Dpoint *h, char c)
{
	if (c == 'y' && wcube_y(f, h))
		return ;
	if (c == 'z' && wcube_z(f, h))
		return ;
	if (c == '?' && wcube_quest(f, h))
		return ;
	if (c == '!' && wcube_excla(f, h))
		return ;
	if (c == '-' && wcube_minus(f, h))
		return ;
	if (c == ' ' && wcube_space(f, h))
		return ;
	return ;
}
