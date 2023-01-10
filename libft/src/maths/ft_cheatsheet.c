/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cheatsheet.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 02:47:27 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/24 03:58:01 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_maths.h"

void	cheatsheet_radians(void)
{
	printf("\n");
	printf("\033[1m Degrees (°) | Radians (rad) |   Radians (rad)\033[0m\n");
	printf("          0° |         0 rad |            0 rad \n");
	printf("         30° |       π/6 rad | 0.5235987756 rad \n");
	printf("         45° |       π/4 rad | 0.7853981634 rad \n");
	printf("         60° |       π/3 rad | 1.0471975512 rad \n");
	printf("         90° |       π/2 rad | 1.5707963268 rad \n");
	printf("        120° |      2π/3 rad | 2.0943951024 rad \n");
	printf("        135° |      3π/4 rad | 2.3561944902 rad \n");
	printf("        150° |      5π/6 rad | 2.6179938780 rad \n");
	printf("        180° |         π rad | 3.1415926536 rad \n");
	printf("        270° |      3π/2 rad | 4.7123889804 rad \n");
	printf("        360° |        2π rad | 6.2831853072 rad \n");
	printf("\
https://www.rapidtables.com/convert/number/radians-to-degrees.html \n");
	printf("\n");
}

void	cheatsheet_types(void)
{
	printf("\n");
	printf("\033[1m    Type    | Format |        Range\033[0m\n");
	printf("   CHAR_MIN |     %%c | %20hi  \n", CHAR_MIN);
	printf("   CHAR_MAX |     %%c | %20hi  \n", CHAR_MAX);
	printf("  UCHAR_MAX |     %%c | %20hu  \n", UCHAR_MAX);
	printf("\n");
	printf("   SHRT_MIN |    %%hi | %20hi  \n", SHRT_MIN);
	printf("   SHRT_MAX |    %%hi | %20hi  \n", SHRT_MAX);
	printf("  USHRT_MAX |    %%hu | %20hu  \n", USHRT_MAX);
	printf("\n");
	printf("    INT_MIN |     %%i | %20i   \n", INT_MIN);
	printf("    INT_MAX |     %%i | %20i   \n", INT_MAX);
	printf("   UINT_MAX |     %%u | %20u   \n", UINT_MAX);
	printf("\n");
	printf("   LONG_MIN |    %%li | %20li  \n", LONG_MIN);
	printf("   LONG_MAX |    %%li | %20li  \n", LONG_MAX);
	printf("  ULONG_MAX |    %%lu | %20lu  \n", ULONG_MAX);
	printf("\n");
	printf("  LLONG_MIN |   %%lli | %20lli \n", LLONG_MIN);
	printf("  LLONG_MAX |   %%lli | %20lli \n", LLONG_MAX);
	printf(" ULLONG_MAX |   %%llu | %20llu \n", ULLONG_MAX);
	printf("https://en.wikipedia.org/wiki/C_data_types \n");
	printf("\n");
}

void	cheatsheet_matrice_rotations(void)
{
	printf("\n");
	printf("\033[1m Basic matrix rotations\033[0m\n");
	printf("        |    1    |    0    |    0    | \n");
	printf(" x(θ) = |    0    |  cos(θ) | -sin(θ) | \n");
	printf("        |    0    |  sin(θ) |  cos(θ) | \n");
	printf("\n");
	printf("        |  cos(θ) |    0    |  sin(θ) | \n");
	printf(" y(θ) = |    0    |    1    |    0    | \n");
	printf("        | -sin(θ) |    0    |  cos(θ) | \n");
	printf("\n");
	printf("        |  cos(θ) | -sin(θ) |    0    | \n");
	printf(" z(θ) = |  sin(θ) |  cos(θ) |    0    | \n");
	printf("        |    0    |    0    |    1    | \n");
	printf("https://en.wikipedia.org/wiki/Rotation_matrix \n");
	printf("\n");
}
