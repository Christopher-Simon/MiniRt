/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_lst.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 15:46:46 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	sc_cam_list_destroy(t_cam **lst)
{
	t_cam	*tmp;

	if (!lst)
		log_printf("ERROR CAM LST DESTROY NO ROOT\n");
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst));
			*lst = tmp;
		}
	}
	*lst = NULL;
}

static t_cam	*cam_lst_new(void)
{
	t_cam	*new;

	new = ft_calloc(sizeof(t_cam));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

size_t	cam_lst_size(t_cam *ob)
{
	int	i;

	i = 0;
	while (ob)
	{
		ob = ob->next;
		i++;
	}
	return (i);
}

static int	cam_lst_add_back(t_cam **lst, t_cam *new)
{
	t_cam	*root;

	if (!lst)
		return (printf("ERROR CAM LLST_ADD_BACK NO ROOT\n"), FAILURE);
	if (!new)
		return (1);
	if (!*lst)
	{
		*lst = new;
		return (SUCCESS);
	}
	root = *lst;
	while (*lst && (*lst)->next)
		*lst = (*lst)->next;
	(*lst)->next = new;
	*lst = root;
	return (SUCCESS);
}

t_cam	*cam_lst_new_camera(t_rt *f, t_element e)
{
	t_cam	*cam;

	cam = cam_lst_new();
	if (!cam)
		rt_exit(f, 1, "malloc failed");
	cam->id = cam_lst_size(f->cam);
	cam_lst_add_back(&f->cam, cam);
	cam->position = e.coord;
	cam->fov = ft_deg_to_rad(e.cam_fov);
	return (cam);
}
