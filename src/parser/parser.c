/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 05:38:10 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/20 15:33:37 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

static void	exit_error_status(t_rt *f, int c, int i)
{
	printf("Error\n");
	printf("Line %i: ", i);
	printf("invalid symbol: Hex[%x] Dec[%d]\n", c, c);
	rt_exit(f, 2, "error rt file");
}

static int	key(char *key, char *input)
{
	if (0 == ft_strncmp(input, key, ft_strlen(key)))
		return (1);
	return (0);
}

static void	parse_line(t_rt *f, char *line, int i)
{
	f->index_line = i + 1;
	if (line[0] == '#' || line[0] == '\n')
		return ;
	if (key("A", line) && get_ambient(f, line))
		return ;
	if (key("C", line) && get_camera(f, line))
		return ;
	if (key("L", line) && get_light(f, line))
		return ;
	if (key("sp", line) && get_sphere(f, line))
		return ;
	if (key("pl", line) && get_plane(f, line))
		return ;
	if (key("cy", line) && get_cylinder(f, line))
		return ;
	if (key("el", line) && get_ellipsoid(f, line))
		return ;
	if (key("cu", line) && get_cuboid(f, line))
		return ;
	if (key("co", line) && get_cone(f, line))
		return ;
	exit_error_status(f, line[0], f->index_line);
}

void	parser(t_rt *f, int ac, char **av)
{
	int	i;

	if (MRT_FILE_MODE == 0)
		return ;
	if (ac != 2)
	{
		printf("Error\nInvalid input file : [%s]\n", av[1]);
		printf("BONUS %i\n", BONUS);
		exit(EXIT_FAILURE);
	}
	f->file = tx_get_file(av[1], ".rt");
	if (!f->file)
	{
		printf("Error\nInvalid input file : [%s]\n", av[1]);
		printf("BONUS %i\n", BONUS);
		exit(EXIT_FAILURE);
	}
	i = 0;
	while (f->file[i])
	{
		parse_line(f, f->file[i], i);
		i++;
	}
	ft_arfree(f->file);
	f->file = NULL;
}
