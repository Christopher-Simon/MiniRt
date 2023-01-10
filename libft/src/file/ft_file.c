/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 22:35:21 by sloquet           #+#    #+#             */
/*   Updated: 2022/10/24 22:38:56 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_file.h"

char	**ft_file(char *filename)
{
	char	**file;
	int		len;
	int		i;
	int		fd;

	len = ft_filelen(filename);
	file = ft_calloc(sizeof(char *) * (len + 1));
	if (!file)
		return (NULL);
	fd = open(filename, O_RDONLY);
	if (0 > fd)
		return (perror("open"), ft_arfree(file), NULL);
	i = 0;
	while (i < len)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
			break ;
		i++;
	}
	ft_close_gnl(fd);
	close(fd);
	return (file);
}
