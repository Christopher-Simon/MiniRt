/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 05:17:39 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/29 08:49:22 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_write.h"

static size_t	st_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putx_fd(int fd, int n, char *s)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, s, st_strlen(s));
		i++;
	}
}

void	ft_putxnl_fd(int fd, int n, char *s)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(fd, s, st_strlen(s));
		i++;
	}
	ft_putnl_fd(fd);
}

void	ft_putrep_fd(int fd, char *s, char old, char new)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == old)
			ft_putchar_fd(new, fd);
		else
			ft_putchar_fd(s[i], fd);
		i++;
	}
}
