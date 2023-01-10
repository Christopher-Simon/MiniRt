r		=	"\033[0m"
n		=	$(NAME)"       "
bn		=	$(NAME_BN)"       "
cr		=	echo $(r)"\033[1;31m   - \033[0;31m"$(n)
cg		=	$(r)"\033[1;32m   + \033[0;32m"$(n)
cg_bn	=	$(r)"\033[1;32m   + \033[0;32m"$(bn)
cb		=	echo "\n"$(r)"\033[1;34m   > \033[0;34m"$(n)
cm		=	echo $(r)"\033[1;35m   > \033[0;35m"$(n)
e_src	=	$(shell ls $(SRC_DIR)/*.c 2>/dev/null | wc -l | tr -d '\n')" sources"
e_obj	=	$(shell ls $(OBJ_DIR)/*.o 2>/dev/null | wc -l | tr -d '\n')" objects"
#-auto-sources-##############211514201122#
SRC = $(addsuffix .c, \
	tests/test_cub \
	tests/test_matrices \
	tests/test_cone \
	tests/scenes_in_code/scene_the_lines \
	tests/assert \
	tests/test_cylinder \
	objects_utils/light_lst \
	objects_utils/object_lst \
	objects_utils/obj_common \
	objects_utils/set_infinity \
	objects_utils/objlst_getxpm \
	objects_utils/cam_lst \
	lighting \
	main \
	smlx/smlx_pixel \
	smlx/minirt_exit \
	smlx/smlx_init \
	smlx/smlx_wcube \
	smlx/smlx_new_xpm \
	smlx/smlx_loop \
	smlx/smlx_destroy \
	parser/parser \
	parser/parser_utils \
	checker_map/sphere_map \
	checker_map/cylinder_map \
	checker_map/cuboid_map \
	checker_map/plane_map \
	checker_map/cone_map \
	checker_map/ellipsoid_map \
	texture/manage_texture \
	texture/checker \
	texture/uv_normal \
	texture/uv_color \
	the_return \
	intersection/inter_plane \
	intersection/get_hits \
	intersection/inter_cuboid \
	intersection/inter_cone \
	intersection/inter_ellipsoid \
	intersection/inter_cylinder \
	intersection/inter_sphere \
	rays \
	log \
	add/add_ambient \
	add/add_light \
	add/add_cuboid \
	add/add_plane \
	add/add_cylinder \
	add/add_sphere \
	add/add_cone \
	add/add_ellipsoid \
	add/add_camera \
	each_pixel \
	basic/tuples/color \
	basic/tuples/neg_tuple \
	basic/tuples/color_picker \
	basic/tuples/tuples \
	basic/tuples/color_op \
	basic/tuples/set_tuples \
	basic/matrices/rotations \
	basic/matrices/transformations \
	basic/matrices/mat3 \
	basic/matrices/shearing \
	basic/matrices/mat2 \
	basic/matrices/inverse_matrix \
	basic/matrices/view_transform \
	basic/matrices/rotations_2 \
	basic/matrices/mat4 \
	basic/wcube/wcube_klmno \
	basic/wcube/wcube_z \
	basic/wcube/wcube_pqrst \
	basic/wcube/wcube__putstr \
	basic/wcube/wcube_01234 \
	basic/wcube/wcube__setup \
	basic/wcube/wcube_uvwxy \
	basic/wcube/wcube_fghij \
	basic/wcube/wcube_abcde \
	basic/wcube/wcube_56789 \
	basic/wcube/wcube__utils \
	basic/wcube/wcube_hook \
	normal/normal_cone \
	normal/normal_ellipsoid \
	normal/normal_sphere \
	normal/normal_at \
	normal/normal_cuboid \
	normal/normal_plane \
	normal/normal_cylinder \
	)
#-auto-sources-##############211514201122#

SRC_BN = $(addsuffix _bonus.c, \
	tests/test_cub \
	tests/test_matrices \
	tests/test_cone \
	tests/scenes_in_code/scene_the_lines \
	tests/assert \
	tests/test_cylinder \
	objects_utils/light_lst \
	objects_utils/object_lst \
	objects_utils/obj_common \
	objects_utils/set_infinity \
	objects_utils/objlst_getxpm \
	objects_utils/cam_lst \
	lighting \
	main \
	smlx/smlx_pixel \
	smlx/minirt_exit \
	smlx/smlx_init \
	smlx/smlx_wcube \
	smlx/smlx_new_xpm \
	smlx/smlx_loop \
	smlx/smlx_destroy \
	parser/parser \
	parser/parser_utils \
	checker_map/sphere_map \
	checker_map/cylinder_map \
	checker_map/cuboid_map \
	checker_map/plane_map \
	checker_map/cone_map \
	checker_map/ellipsoid_map \
	texture/manage_texture \
	texture/checker \
	texture/uv_normal \
	texture/uv_color \
	the_return \
	intersection/inter_plane \
	intersection/get_hits \
	intersection/inter_cuboid \
	intersection/inter_cone \
	intersection/inter_ellipsoid \
	intersection/inter_cylinder \
	intersection/inter_sphere \
	rays \
	log \
	add/add_ambient \
	add/add_light \
	add/add_cuboid \
	add/add_plane \
	add/add_cylinder \
	add/add_sphere \
	add/add_cone \
	add/add_ellipsoid \
	add/add_camera \
	each_pixel \
	basic/tuples/color \
	basic/tuples/neg_tuple \
	basic/tuples/color_picker \
	basic/tuples/tuples \
	basic/tuples/color_op \
	basic/tuples/set_tuples \
	basic/matrices/rotations \
	basic/matrices/transformations \
	basic/matrices/mat3 \
	basic/matrices/shearing \
	basic/matrices/mat2 \
	basic/matrices/inverse_matrix \
	basic/matrices/view_transform \
	basic/matrices/rotations_2 \
	basic/matrices/mat4 \
	basic/wcube/wcube_klmno \
	basic/wcube/wcube_z \
	basic/wcube/wcube_pqrst \
	basic/wcube/wcube__putstr \
	basic/wcube/wcube_01234 \
	basic/wcube/wcube__setup \
	basic/wcube/wcube_uvwxy \
	basic/wcube/wcube_fghij \
	basic/wcube/wcube_abcde \
	basic/wcube/wcube_56789 \
	basic/wcube/wcube__utils \
	basic/wcube/wcube_hook \
	normal/normal_cone \
	normal/normal_ellipsoid \
	normal/normal_sphere \
	normal/normal_at \
	normal/normal_cuboid \
	normal/normal_plane \
	normal/normal_cylinder \
	)

INC_DIR	=	inc
SRC_DIR	=	src
SRC_PATH=	$(addprefix $(SRC_DIR)/, $(SRC))
OBJ_DIR	=	obj
OBJ		=	$(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))
DEPS	=	$(OBJ:.o=.d)

INC_DIR_BN	=	inc_bonus
SRC_DIR_BN	=	src_bonus
SRC_PATH_BN =	$(addprefix $(SRC_DIR_BN)/, $(SRC_BN))
OBJ_DIR_BN	=	obj_bonus
OBJ_BN		=	$(addprefix $(OBJ_DIR_BN)/, $(SRC_BN:.c=.o))
DEPS_BN	=	$(OBJ_BN:.o=.d)

PATH_MLX=	mlx_linux
MAKEMLX =	$(MAKE) $(MFG) -C $(PATH_MLX)

PATH_LIB=	libft/
LIB 	=	libft.a
INC_LIB	=	libft
MAKELIB =	$(MAKE) $(MFG) -C $(PATH_LIB)

NAME	=	miniRT
NAME_BN	=	miniRT_bonus

CC		=	@cc
CFLAGS 	=	-Wall -Wextra -Werror -O3 -I $(INC_DIR) -I $(INC_LIB)
CFLAGS_BN=	-Wall -Wextra -Werror -O3 -I $(INC_DIR_BN) -I $(INC_LIB)

MLX		=	-Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MKDIR	=	@mkdir -p
RM		=	rm -rf
MFG 	=	--no-print-directory

#########################################

all: 	$(NAME)

$(OBJ_DIR)/%.o:$(SRC_DIR)/%.c
		$(MKDIR) $(dir $@)
		$(CC) -MMD $(CFLAGS) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#\

		@echo $(cg)"(@) "$@" (<) "$<

$(OBJ_DIR_BN)/%.o:$(SRC_DIR_BN)/%.c
		$(MKDIR) $(dir $@)
		$(CC) -MMD $(CFLAGS_BN) -I/usr/include -Imlx_linux -O3 -c $< -o $@
#\

		@echo $(cg)"(@) "$@" (<) "$<

mlx:
		@$(MAKEMLX)

$(LIB):
		$(MAKELIB)

$(NAME):mlx $(LIB) $(OBJ)
		$(CC) $(CFLAGS) -o $(NAME) $(SRC_PATH) $(PATH_LIB)$(LIB) $(MLX)
		echo -n $(cg) && du -bh $(NAME) | tr -d '$(NAME)' && echo -n $(r)

bonus:mlx $(LIB) $(OBJ_BN)
		$(CC) $(CFLAGS_BN) -o $(NAME_BN) $(SRC_PATH_BN) $(PATH_LIB)$(LIB) $(MLX)
		echo -n $(cg_bn) && du -bh $(NAME_BN) | tr -d '$(NAME_BN)' && echo -n $(r)

clean:
		$(MAKELIB) clean
		$(RM) $(OBJ_DIR) $(OBJ_DIR_BN)
		$(RM) "$(NAME).d"
		$(RM) "$(NAME_BN).d"
		$(cr)$(e_obj)

fclean: clean_mlx
		$(MAKELIB) fclean
		$(RM) $(OBJ_DIR) $(OBJ_DIR_BN) $(NAME) $(NAME_BN)
		$(RM) "$(NAME).d"
		$(RM) "$(NAME_BN).d"
		$(cr)$(e_obj) && echo -n $(r)

clean_mlx:
		@$(MAKEMLX) clean

re:	fclean
	make all

re_bonus:	fclean
			make bonus

#########################################
-include $(DEPS)
-include $(DEPS_BN)

.PHONY:	all clean fclean re  re_bonus mlx clean_mlx bonus
.SILENT: all clean fclean re re_bonus mlx clean_mlx bonus $(NAME) $(LIB)
