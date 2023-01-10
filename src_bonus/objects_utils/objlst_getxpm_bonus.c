/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objlst_getxpm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 19:18:00 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:18:05 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	obj_lst_getxpm(t_rt *f, t_obj *ob)
{
	while (ob)
	{
		if (smlx_new_xpm(&f->mlx, &ob->texture))
			rt_exit(f, 5, "olst_new_obj() smlx_new_xpm() failed");
		if (smlx_new_xpm(&f->mlx, &ob->bumpmap))
			rt_exit(f, 5, "olst_new_obj() smlx_new_xpm() failed");
		ob = ob->next;
	}
}
