/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:46:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:31:58 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	sphere_normal(t_obj *obj, t_tuple position)
{
	return (sub_tuples(position, pos(0, 0, 0)));
	(void)obj;
}
