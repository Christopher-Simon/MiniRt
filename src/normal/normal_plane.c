/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 00:10:23 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/03 14:23:41 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	plane_normal(t_obj *obj, t_tuple p)
{
	return (normalisation(set_vector(0, 1, 0)));
	(void)p;
	(void)obj;
}
