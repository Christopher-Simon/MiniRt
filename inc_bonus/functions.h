/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:44:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 16:47:57 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

# include "types.h"

//MATRIX 4
void	print_matrix4(t_matx4 m);
void	fill_matrix4(t_matx4 *m, double M[4][4]);
t_matx4	m_prod(t_matx4 A, t_matx4 B);
t_matx4	identity_matrice(void);
t_matx4	transpose_matrice(t_matx4 m);

//MATRIX 3
t_matx3	submatrix4(t_matx4 m, int row, int col);
void	print_matrix3(t_matx3 m);
void	fill_matrix3(t_matx3 *m, double M[3][3]);
double	minor(t_matx3 M, int row, int col);
double	cofactor_3(t_matx3 M, int row, int col);
double	determinant_3(t_matx3 M, int row);

//MATRIX 2
t_matx2	submatrix3(t_matx3 m, int row, int col);
void	fill_matrix2(t_matx2 *m, double M[2][2]);
double	determinant_2(t_matx2 m);
void	print_matrix2(t_matx2 m);

/**
 * 		matrices/transformations.c
 */
t_matx4	translation(double x, double y, double z);
t_matx4	scaling(double x, double y, double z);
t_tuple	prod_matx_tuple(t_matx4 M, t_tuple tup);
t_tuple	reflect(t_tuple	in, t_tuple	normal);

/**
 * 		matrices/rotations.c
 */
t_matx4	rotation_x(double r);
t_matx4	rotation_y(double r);
t_matx4	rotation_z(double r);
t_matx4	m_rotation(t_tuple degrees);
t_matx4	m_rotate_align(t_tuple v1, t_tuple v2);
t_matx4	m_rot_vec_y(t_tuple vec);

/**
 * 		matrices/inverse_matrix.c
 */
double	cofactor_4(t_matx4 M, int row, int col);
double	determinant_4(t_matx4 M, int row);
int		is_invertible(t_matx4 M);
t_matx4	inverse_matrix(t_matx4	M);

/**
 * 		matrices/shearing.c
 **/
t_shx	shx(double x_y, double x_z);
t_shy	shy(double y_x, double y_z);
t_shz	shz(double z_x, double z_y);
t_matx4	shear(t_shx shx, t_shy shy, t_shz shz);

/******************************************************************************
 **                                TUPLES
 *****************************************************************************/
/**
 * 		tuples/colors_op.c
 */
t_color	calibrate_rgb(t_color color);
t_color	sub_colors(t_color t1, t_color t2);
t_color	add_colors(t_color t1, t_color t2);
t_color	prod_colors(t_color t1, t_color t2);
t_color	scale_colors(t_color t1, double scalar);
t_color	color_picker(int i);			//tmp
t_color	hex_to_rgb(int hex);
t_color	norm_color(t_color color);

/**
 * 		tuples/neg_tuple.c
 */
t_tuple	scalar_tuples(t_tuple t1, double scalar);
t_tuple	add_tuples(t_tuple t1, t_tuple t2);
t_tuple	sub_tuples(t_tuple t1, t_tuple t2);
t_tuple	negating_tuple(t_tuple t1);

/**
 * 		tuples/set_tuples.c
 */
t_tuple	color(double x, double y, double z);
t_tuple	pos(double x, double y, double z);
t_tuple	sc(double x, double y, double z);
t_tuple	set_vector(double x, double y, double z);
t_tuple	vec(double x, double y, double z);

/**
 * 		tuples/tuples.c
 */
double	magnitude(t_tuple t);
t_tuple	normalisation(t_tuple t);
double	dot_prdt(t_tuple t1, t_tuple t2);
t_tuple	cross_prdt(t_tuple t1, t_tuple t2);

/******************************************************************************
 **                                CAMERA
 *****************************************************************************/
t_ray	get_ray(t_tuple	origin, t_tuple direction);
t_tuple	position(t_ray ray, double t);
t_ray	transform_ray(t_ray ray, t_matx4 M);
t_ray	ray_to_pixel(t_cam cam, int x, int y);

void	obj_transform(t_obj *obj, t_matx4 M);
t_matx4	view_transform(t_tuple from, t_tuple forward);

/******************************************************************************
 **                                MECANISM
 *****************************************************************************/

void	the_return(t_rt *f);
t_color	manage_lighting(t_rt *f, t_obj *obj, t_ray ray);
void	raytracing_each_pixel(t_rt *f);
t_obj	*get_hit_obj(t_obj *root, t_ray ray);

/******************************************************************************
 **                                LINKED LISTS
 *****************************************************************************/
t_cam	*cam_lst_new_camera(t_rt *f, t_element e);
void	sc_cam_list_destroy(t_cam **lst);
size_t	cam_lst_size(t_cam *ob);

t_obj	*olst_new_obj(t_rt *f, t_element e);
void	set_infinity(t_obj *obj);
void	sc_shape_list_destroy(t_rt *f, t_obj **lst);
size_t	olst_size(t_obj *ob);
void	obj_lst_getxpm(t_rt *f, t_obj *ob);

void	sc_light_list_destroy(t_light **lst);
size_t	llst_size(t_light *ob);

/******************************************************************************
 **                                  TESTS
 *****************************************************************************/
void	assert_matrix(char *id, t_matx4 a, t_matx4 b);
void	assert_tuple(char *id, t_tuple a, t_tuple b);
void	test_matrices_diff(void);

void	test_cub_normal(void);
void	test_cub_intersection(void);

void	test_cyl_normal(void);
void	test_cyl_intersection(void);

void	test_cone_intersection(void);
void	test_cone_caps_intersection(void);
void	test_cone_normal(void);

/******************************************************************************
 **                                SCENES
 *****************************************************************************/
void	space_view(t_rt *f, int seed);
void	the_lines(t_rt *f);

/******************************************************************************
 **                                SHAPE
 *****************************************************************************/
/**		COMMON		*/
void	new_element(t_element *e);
t_mater	get_material(t_element e);
double	get_smallest_intersect(double i, double k);
bool	is_in_object(double hits[2]);
char	**check(t_rt *f, char *input, char *pattern);
t_tuple	normal_at(t_obj *obj, t_tuple world_pt, t_ray ray);
void	get_cone_hits(t_obj *obj);

/**		TEXTURE		*/
t_color	uv_2d_map(t_uv p, t_check checker);
t_check	get_checker(double width, double height, t_tuple rgb_1, t_tuple rgb_2);
t_check	add_checker(double w, double h, t_color rgb);
t_uv	cuboid_map(t_tuple p);
t_color	uv_color(t_img *img, t_uv uv);
t_tuple	uv_normal(t_img *img, t_uv uv, t_tuple normal);
void	manage_texture(t_obj *obj, t_tuple pos, t_tuple *normal);

/**		AMBIENT		*/
void	do_ambient(t_rt *f, double ratio, int color);
int		get_ambient(t_rt *f, char *input);
void	add_ambient(t_rt *f, t_element e);

/**		CAMERA		*/
void	do_camera(t_rt *f, t_tuple coord, t_tuple angle, int fov);
int		get_camera(t_rt *f, char *input);
void	add_camera(t_rt *f, t_element e);

/**		LIGHT		*/
void	do_light(t_rt *f, t_tuple coord, double ratio, int color);
int		get_light(t_rt *f, char *input);
void	add_light(t_rt *f, t_element e);

/**		SPHERE		*/
void	do_sphere(t_rt *f, t_tuple coord, double diameter, int color);
int		get_sphere(t_rt *f, char *input);
void	add_sphere(t_rt *f, t_element e);
bool	sphere_intersection(t_obj *obj, t_ray ray);
t_tuple	sphere_normal(t_obj *obj, t_tuple position);
t_uv	sphere_map(t_tuple p);

/**		PLANE		*/
void	do_plane(t_rt *f, t_tuple coord, t_tuple angle, int color);
int		get_plane(t_rt *f, char *input);
void	add_plane(t_rt *f, t_element e);
bool	plane_intersection(t_obj *obj, t_ray ray);
t_tuple	plane_normal(t_obj *obj, t_tuple p);
t_uv	plane_map(t_tuple p);

/**		CYLINDER	*/
void	do_cylinder(t_rt *f, t_tuple coord, t_tuple angle, double h);
int		get_cylinder(t_rt *f, char *input);
void	add_cylinder(t_rt *f, t_element e);
bool	cylinder_intersection(t_obj *obj, t_ray ray);
void	get_cyl_hits(t_obj *obj);
t_tuple	cylinder_normal(t_obj *obj, t_tuple p);
t_uv	cylinder_map(t_tuple p);

/**		ELLIPSOID	*/
void	do_ellipsoid(t_rt *f, t_tuple coord, t_tuple angle, t_tuple scale);
int		get_ellipsoid(t_rt *f, char *input);
void	add_ellipsoid(t_rt *f, t_element e);
bool	ellipsoid_intersection(t_obj *obj, t_ray ray);
t_tuple	ellipsoid_normal(t_obj *obj, t_tuple position);
t_uv	ellipsoid_map(t_tuple p);

/**		CUBOID		*/
void	do_cuboid(t_rt *f, t_tuple coord, t_tuple angle, t_tuple scale);
int		get_cuboid(t_rt *f, char *input);
void	add_cuboid(t_rt *f, t_element e);
bool	cuboid_intersection(t_obj *obj, t_ray ray);
t_tuple	cuboid_normal(t_obj *obj, t_tuple p);
t_uv	cuboid_map(t_tuple p);

/**		CONE		*/
void	do_cone(t_rt *f, t_tuple coord, t_tuple angle, double h);
int		get_cone(t_rt *f, char *input);
void	add_cone(t_rt *f, t_element e);
bool	cone_intersection(t_obj *obj, t_ray ray);
t_tuple	cone_normal(t_obj *obj, t_tuple p);
t_uv	cone_map(t_tuple p);

/**		LOG				*/
void	log_element(t_element e, char *name, t_name n);
void	log_printf(char *str, ...);
void	log_tuple(t_tuple tup);

/**		PARSER			*/
void	parser(t_rt *f, int ac, char **av);
t_tuple	atof3(char *x, char *y, char *z, int w);
bool	is_checker(char *str);
bool	is_skybox(char *str);
char	*is_file(char *str);

/**		MLX				*/
void	smlx_destroy(t_smlx *mlx);
int		smlx_init(t_smlx *mlx, int nb_img);
int		smlx_new_xpm(t_smlx *mlx, t_img *img);
int		smlx_loop(t_rt *f);
void	smlx_pixel(t_img *img, int x, int y, int hex_color);

/**		WCUBE		*/
void	hook_wcube_add_char(int keycode, t_rt *f);
void	hook_wcube_update(t_rt *f);

/**		MINI_RT EXIT	*/
void	rt_exit(t_rt *f, int code, char *msg);

#endif /* FUNCTIONS_H */
