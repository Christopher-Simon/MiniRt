/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 04:18:35 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/22 15:18:51 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/******************************************************************************
 **                        	         CONFIG
 *****************************************************************************/

# define WIN_SIZE_X				1920
# define WIN_SIZE_Y				1011
# define WIN_TITLE				"MiniRT_bonus"

# define MRT_FILE_MODE			1
# define MRT_CODE_MODE			0
# define MRT_PUTS_MODE			0

# define BONUS					1
# define VERBOSE				0

# define WCUBE_MODE				WCUBE_STRAIGHT
// # define WCUBE_MODE				WCUBE_STARWARS
// # define WCUBE_MODE				WCUBE_DEFAULT

/******************************************************************************
 **                      WARNING DO NOT MODIFY THIS SECTION
 *****************************************************************************/
typedef enum e_name
{
	E_AMBIENT,
	E_LIGHT,
	E_SPHERE,
	E_CAMERA,
	E_PLANE,
	E_CYLINDER,
	E_ELLIPSOID,
	E_CUBOID,
	E_CONE
}	t_name;

# define SUCCESS		0
# define FAILURE		1
# define ERR_MALLOC		-1

# define VECTOR			0
# define POINT			1
# define COLOR			1

# define ESCAPE			65307
# define ENTER			65293
# define TAB			65289

# if MRT_PUTS_MODE == 1
#  undef BONUS
#  define BONUS	1
# endif

# if MRT_CODE_MODE == 1
#  undef BONUS
#  define BONUS	1
# endif

#endif /* DEFINES_H */
