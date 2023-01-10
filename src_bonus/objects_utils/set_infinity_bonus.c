/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_infinity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 14:22:37 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/20 14:22:50 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	set_infinity(t_obj *obj)
{
	obj->hits[0] = INFINITY;
	obj->hits[1] = INFINITY;
	obj->tmp_hits[0] = INFINITY;
	obj->tmp_hits[1] = INFINITY;
	obj->tmp_hits[2] = INFINITY;
	obj->tmp_hits[3] = INFINITY;
}
