/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 15:49:01 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static t_obj	*olst_new(void)
{
	t_obj	*new;

	new = ft_calloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

void	sc_shape_list_destroy(t_rt *f, t_obj **lst)
{
	t_obj	*tmp;

	if (!lst)
		log_printf("ERROR OBJECT LST DESTROY NO ROOT\n");
	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			if ((*lst)->texture.id)
				mlx_destroy_image(f->mlx.id, (*lst)->texture.id);
			if ((*lst)->bumpmap.id)
				mlx_destroy_image(f->mlx.id, (*lst)->bumpmap.id);
			if ((*lst)->texture.title)
				free((*lst)->texture.title);
			if ((*lst)->bumpmap.title)
				free((*lst)->bumpmap.title);
			free((*lst));
			*lst = tmp;
		}
	}
	*lst = NULL;
}

size_t	olst_size(t_obj *ob)
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

static int	olst_add_back(t_obj **lst, t_obj *new)
{
	t_obj	*root;

	if (!lst)
		return (log_printf("ERROR NO ROOT OBJ OLST_ADD_BACK\n"), FAILURE);
	if (!new)
		return (FAILURE);
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

t_obj	*olst_new_obj(t_rt *f, t_element e)
{
	t_obj	*ob;

	ob = olst_new();
	if (!ob)
		rt_exit(f, 1, "olst_new_obj() malloc failed");
	ob->id = olst_size(f->ob);
	olst_add_back(&f->ob, ob);
	ob->m = identity_matrice();
	ob->hit = INFINITY;
	ob->hits[0] = INFINITY;
	ob->hits[1] = INFINITY;
	ob->height = 1;
	ob->material.color = norm_color(e.color);
	ob->material.diffuse = e.diffuse;
	ob->material.specular = e.specular;
	ob->material.shiny = e.shiny;
	ob->is_checker = e.checker;
	ob->is_skybox = e.skybox;
	ob->texture.title = ft_strdup(e.texfile);
	ob->bumpmap.title = ft_strdup(e.bumfile);
	free(e.texfile);
	free(e.bumfile);
	return (ob);
}
