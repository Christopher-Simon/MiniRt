/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chsimon <chsimon@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 06:41:10 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/21 18:15:03 by chsimon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_rt.h"

t_tuple	atof3(char *x, char *y, char *z, int w)
{
	t_tuple	new;

	new.x = ft_atof(x);
	new.y = ft_atof(y);
	new.z = ft_atof(z);
	new.w = w;
	if (new.x == 0 && new.y == 0 && new.z == 0 && new.w == 0)
	{
		log_printf("\033[33mzero angle found (0, 0, 0) -> (0, 0, 1)\033[0m\n");
		new = vec(0, 0, 1);
	}
	return (new);
}

bool	is_checker(char *str)
{
	return (str[9] == 'n');
}

bool	is_skybox(char *str)
{
	return (str[8] == 'n');
}

char	*is_file(char *str)
{
	char	*file;

	if (str[0] == '"' && str[1] == '"')
		return (NULL);
	file = ft_strldup(str + 1, ft_strlen(str) - 1);
	if (!file)
		return (NULL);
	return (file);
}
