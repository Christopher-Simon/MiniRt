/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tx_get_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloquet <sloquet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 03:40:48 by sloquet           #+#    #+#             */
/*   Updated: 2022/11/03 09:25:17 by sloquet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hsl_tx.h"

#undef TX_NAME
#define TX_NAME	"tx_get_file"

//todo get file with tx pattern instead extension

static void	tx_log_get_file(char *pathname, char *extension)
{
	if (!TX_VERBOSE)
		return ;
	printf("pathname         : %s\n", pathname);
	printf("extension        : %s\n", extension);
}

static int	tx_filelen(const char *pathname)
{
	char	*tmp;
	int		len;
	int		fd;

	tmp = NULL;
	len = 0;
	fd = open(pathname, O_RDONLY);
	if (0 > fd)
		return (perror(TX_NAME), -1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		len++;
	}
	close(fd);
	return (len);
}

static char	**_tx_get_file_extract(int fd, int len)
{
	char	**file;
	int		i;

	file = ft_calloc(sizeof(char *) * (len + 1));
	if (!file)
		return (NULL);
	i = 0;
	while (i < len)
	{
		file[i] = get_next_line(fd);
		if (!file[i])
			break ;
		i++;
	}
	ft_close_gnl(fd);
	return (file);
}

char	**tx_get_file(char *pathname, char *extension)
{
	char	**file;
	int		len;
	int		fd;

	tx_log_get_file(pathname, extension);
	if (ft_is_extension(pathname, extension) == 0)
		return (NULL);
	len = tx_filelen(pathname);
	if (len == -1)
		return (NULL);
	fd = open(pathname, O_RDONLY);
	if (0 > fd)
		return (perror(TX_NAME), NULL);
	file = _tx_get_file_extract(fd, len);
	close(fd);
	if (!file)
		return (NULL);
	return (file);
}
