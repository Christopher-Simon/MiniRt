/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:59:14 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 18:59:21 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	manage_texture(t_obj *obj, t_tuple pos, t_tuple *normal)
{
	t_uv	uv;

	if (obj->sh == E_SPHERE || obj->sh == E_CONE || obj->sh == E_ELLIPSOID)
	{
		uv = obj->checker_fnct(prod_matx_tuple(obj->m_inverse, pos));
		if (obj->texture.id)
			obj->material.color = uv_color(&obj->texture, uv);
		if (obj->bumpmap.id && obj->is_skybox == false)
			*normal = uv_normal(&obj->bumpmap, uv, *normal);
	}
}
