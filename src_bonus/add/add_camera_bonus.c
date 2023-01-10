/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 07:06:16 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/20 15:39:06 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

/**
 * 	do_camera		:	dev wrapper for add_()
 * 						to make an object directly in the code
 * 						params		->	e_element
 *
 * 	get_camera		:	find a valid object in the input line,
 * 						fill a struct e_element, then call add_()
 * 						char *		->	e_element
 *
 * 	add_camera		:	add an object to the destination list
 * 						with all specs and compute the object matrix
 * 						e_element	->	t_cam *
 **/

void	do_camera(t_rt *f, t_tuple coord, t_tuple angle, int fov)
{
	t_element	e;

	new_element(&e);
	e.coord = coord;
	e.angle = angle;
	e.cam_fov = fov;
	add_camera(f, e);
}

int	get_camera(t_rt *f, char *input)
{
	t_element	e;
	char		**info;

	if (cam_lst_size(f->cam))
		return (0);
	new_element(&e);
	info = check(f, input, TX_PATTERN_CAMERA);
	e.coord = atof3(info[1], info[2], info[3], POINT);
	e.angle = atof3(info[4], info[5], info[6], VECTOR);
	e.cam_fov = ft_atof(info[7]);
	ft_arfree(info);
	add_camera(f, e);
	return (1);
}

void	add_camera(t_rt *f, t_element e)
{
	t_cam	*cam;
	double	aspect;

	log_element(e, "CAMERA", E_CAMERA);
	if (cam_lst_size(f->cam))
		rt_exit(f, 1, "too many add_camera()");
	cam = cam_lst_new_camera(f, e);
	cam->hsize = WIN_SIZE_X;
	cam->vsize = WIN_SIZE_Y;
	cam->m = identity_matrice();
	cam->half_view = tan(cam->fov / 2);
	aspect = cam->hsize / cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = cam->half_view;
		cam->half_height = cam->half_view / aspect;
	}
	else
	{
		cam->half_width = cam->half_view * aspect;
		cam->half_height = cam->half_view;
	}
	cam->pixel_size = (cam->half_width * 2) / cam->hsize;
	cam->m = view_transform(e.coord, normalisation(e.angle));
	cam->inv_m = inverse_matrix(cam->m);
}
