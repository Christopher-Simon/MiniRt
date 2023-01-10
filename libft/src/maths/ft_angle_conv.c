/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_angle_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 08:29:01 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/24 02:47:48 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

double	ft_deg_to_rad(double degrees)
{
	return (degrees * 3.14159265358979323846 / 180.0);
}

double	ft_rad_to_deg(double radians)
{
	return (radians / 3.14159265358979323846 * 180.0);
}
