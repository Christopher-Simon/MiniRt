/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:37:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/18 19:08:27 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

/******************************************************************************
 **                              	   MLX
 *****************************************************************************/

typedef struct s_img
{
	int		idn;
	char	*title;
	void	*id;
	void	*addr;
	int		end;
	int		len;
	int		bpp;
	int		height;
	int		width;
}	t_img;
// (end endian) (len line_length) (bpp bits_per_pixel)

typedef struct s_smlx
{
	void	*id;
	void	*win;
	int		win_x;
	int		win_y;
	t_img	*img;
	int		nb_img;

}	t_smlx;

/******************************************************************************
 **                                MATRICES
 *****************************************************************************/
typedef struct s_matx4
{
	double	m[4][4];
}	t_matx4;

typedef struct s_matx3
{
	double	m[3][3];
}	t_matx3;

typedef struct s_matx2
{
	double	m[2][2];
}	t_matx2;

typedef struct s_shx
{
	double	y;
	double	z;
}	t_shx;

typedef struct s_shy
{
	double	x;
	double	z;
}	t_shy;

typedef struct s_shz
{
	double	x;
	double	y;
}	t_shz;

/******************************************************************************
 **                                TUPLES
 *****************************************************************************/
typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}		t_tuple;

typedef struct s_tbn
{
	t_tuple	t;
	t_tuple	b;
}	t_tbn;

typedef t_tuple			t_color;
// typedef	t_tuple t_point;
// typedef	t_tuple t_vector;

/******************************************************************************
 **                                LIGHTS
 *****************************************************************************/
typedef struct s_ambt
{
	double	ratio;
	t_color	color;
	bool	active;
}	t_ambt;

typedef struct s_light	t_light;

typedef struct s_light
{
	int		id;
	t_tuple	position;
	double	ratio;
	t_color	color;
	t_light	*next;
}	t_light;

/******************************************************************************
 **                                CAMERA + RAY
 *****************************************************************************/
typedef struct s_cam	t_cam;

typedef struct s_cam
{
	int		id;
	double	hsize;
	double	vsize;
	double	half_view;
	double	half_width;
	double	half_height;
	double	pixel_size;
	t_tuple	position;
	double	fov;
	t_matx4	m;
	t_matx4	inv_m;
	t_cam	*next;
}	t_cam;

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	dir;
}	t_ray;

/******************************************************************************
 **                                TEXTURES
 *****************************************************************************/

typedef struct s_check
{
	double	width;
	double	height;
	t_color	rgb_1;
	t_color	rgb_2;
}	t_check;

typedef struct s_uv
{
	double	u;
	double	v;
}	t_uv;

/******************************************************************************
 **                                SHAPES
 *****************************************************************************/

typedef int				t_shape;

typedef struct s_material
{
	t_color	color;
	double	diffuse;
	double	specular;
	double	shiny;
}	t_mater;

typedef struct s_element
{
	t_tuple	coord;
	double	ratio;
	double	cam_fov;
	t_tuple	angle;
	t_tuple	scale;
	double	diameter;
	double	height;
	t_color	color;
	double	diffuse;
	double	specular;
	double	shiny;
	bool	checker;
	char	*texfile;
	char	*bumfile;
	bool	skybox;
}	t_element;

typedef struct s_obj	t_obj;
typedef bool			t_intersection(t_obj *, t_ray);
typedef t_tuple			t_normal(t_obj *, t_tuple);
typedef t_uv			t_checker(t_tuple);

typedef struct s_obj
{
	int				id;
	t_shape			sh;
	double			hit;
	double			hits[2];
	double			tmp_hits[4];
	bool			in_object;
	double			height;
	t_matx4			m;
	t_matx4			m_inverse;
	t_mater			material;
	t_intersection	*inter_fnct;
	t_normal		*normal_fnct;
	t_checker		*checker_fnct;
	bool			is_checker;
	bool			is_skybox;
	t_check			checker_specs;
	t_img			texture;
	t_img			bumpmap;
	t_obj			*next;
}	t_obj;

typedef struct s_wcube
{
	char	*txt_buffer;
	char	*txt_buffer_old;
}	t_wcube;

/******************************************************************************
 **                              MINI_RT MAIN STRUCT
 *****************************************************************************/
typedef struct s_rt
{
	t_smlx	mlx;
	char	**file;
	t_wcube	wcub;
	t_ambt	ambient;
	t_cam	*cam;
	t_light	*li;
	t_obj	*ob;
	int		index_line;
}	t_rt;

#endif /* TYPES_H */
