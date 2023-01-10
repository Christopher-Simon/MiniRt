/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wcube.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 04:30:38 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/01 03:00:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WCUBE_H
# define WCUBE_H

# include "mini_rt.h"

# define WCUBE_TEXT_COLOR WHITE

typedef enum e_wcube_mode
{
	WCUBE_DEFAULT,
	WCUBE_STRAIGHT,
	WCUBE_STARWARS,
}	t_wcube_mode;

typedef struct s_3Dpoint
{
	double	x;
	double	y;
	double	z;
}	t_3Dpoint;

typedef struct s_2Dpoint
{
	double	x;
	double	y;
}	t_2Dpoint;

typedef struct s_2Dvector
{
	double	x;
	double	y;
}	t_2Dvector;

typedef double		t_lenght;

void		wcube_putstr(t_rt *f, char *str, t_wcube_mode mode);

t_3Dpoint	wcube_setup(t_rt *f, const char *str, t_wcube_mode mode);
void		row(t_rt *f, t_2Dpoint p, t_3Dpoint *head, t_lenght xlen);
void		col(t_rt *f, t_2Dpoint p, t_3Dpoint *head, t_lenght ylen);
void		one(t_rt *f, t_2Dpoint p, t_3Dpoint *head);
t_2Dpoint	p2(double x, double y);

void		hook_abcdefghijkl(t_rt *f, t_3Dpoint *h, char c);
void		hook_mnopqrstuvwx(t_rt *f, t_3Dpoint *h, char c);
void		hook_0123456789(t_rt *f, t_3Dpoint *h, char c);
void		hook_yz_and_punct(t_rt *f, t_3Dpoint *h, char c);

int			wcube_a(t_rt *f, t_3Dpoint *h);
int			wcube_b(t_rt *f, t_3Dpoint *h);
int			wcube_c(t_rt *f, t_3Dpoint *h);
int			wcube_d(t_rt *f, t_3Dpoint *h);
int			wcube_e(t_rt *f, t_3Dpoint *h);
int			wcube_f(t_rt *f, t_3Dpoint *h);
int			wcube_g(t_rt *f, t_3Dpoint *h);
int			wcube_h(t_rt *f, t_3Dpoint *h);
int			wcube_i(t_rt *f, t_3Dpoint *h);
int			wcube_j(t_rt *f, t_3Dpoint *h);
int			wcube_k(t_rt *f, t_3Dpoint *h);
int			wcube_l(t_rt *f, t_3Dpoint *h);
int			wcube_m(t_rt *f, t_3Dpoint *h);
int			wcube_n(t_rt *f, t_3Dpoint *h);
int			wcube_o(t_rt *f, t_3Dpoint *h);
int			wcube_p(t_rt *f, t_3Dpoint *h);
int			wcube_q(t_rt *f, t_3Dpoint *h);
int			wcube_r(t_rt *f, t_3Dpoint *h);
int			wcube_s(t_rt *f, t_3Dpoint *h);
int			wcube_t(t_rt *f, t_3Dpoint *h);
int			wcube_u(t_rt *f, t_3Dpoint *h);
int			wcube_v(t_rt *f, t_3Dpoint *h);
int			wcube_w(t_rt *f, t_3Dpoint *h);
int			wcube_x(t_rt *f, t_3Dpoint *h);
int			wcube_y(t_rt *f, t_3Dpoint *h);
int			wcube_z(t_rt *f, t_3Dpoint *h);
int			wcube_quest(t_rt *f, t_3Dpoint *h);
int			wcube_excla(t_rt *f, t_3Dpoint *h);
int			wcube_minus(t_rt *f, t_3Dpoint *h);
int			wcube_space(t_rt *f, t_3Dpoint *h);
int			wcube_0(t_rt *f, t_3Dpoint *h);
int			wcube_1(t_rt *f, t_3Dpoint *h);
int			wcube_2(t_rt *f, t_3Dpoint *h);
int			wcube_3(t_rt *f, t_3Dpoint *h);
int			wcube_4(t_rt *f, t_3Dpoint *h);
int			wcube_5(t_rt *f, t_3Dpoint *h);
int			wcube_6(t_rt *f, t_3Dpoint *h);
int			wcube_7(t_rt *f, t_3Dpoint *h);
int			wcube_8(t_rt *f, t_3Dpoint *h);
int			wcube_9(t_rt *f, t_3Dpoint *h);

#endif /* WCUBE_H */
