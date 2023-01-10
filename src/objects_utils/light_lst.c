/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 02:13:50 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 15:46:54 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

void	sc_light_list_destroy(t_light **lst)
{
	t_light	*tmp;

	if (!lst)
		log_printf("ERROR LIGHT LST DESTROY NO ROOT\n");
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

static t_light	*llst_new(void)
{
	t_light	*new;

	new = ft_calloc(sizeof(t_light));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

size_t	llst_size(t_light *ob)
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

static int	llst_add_back(t_light **lst, t_light *new)
{
	t_light	*root;

	if (!lst)
		return (printf("ERROR LIGHT LLST_ADD_BACK NO ROOT\n"), FAILURE);
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

void	add_light(t_rt *f, t_element e)
{
	t_light	*li;

	if (llst_size(f->li) && !BONUS)
		rt_exit(f, 1, "too many add_light()");
	log_element(e, "LIGHT", E_LIGHT);
	li = llst_new();
	if (!li)
		rt_exit(f, 1, "add_light() malloc failed");
	li->id = llst_size(f->li);
	llst_add_back(&f->li, li);
	li->position = e.coord;
	li->ratio = e.ratio;
	li->color = norm_color(e.color);
}
