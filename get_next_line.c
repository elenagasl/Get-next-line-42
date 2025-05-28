/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elengarc <elengarc@student.42Madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 16:35:48 by elengarc          #+#    #+#             */
/*   Updated: 2025/04/18 16:35:49 by elengarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	gnl_checks(int fd, char **readed)
{
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	if (!*readed)
	{
		*readed = malloc(1);
		if (!*readed)
			return (0);
		*readed[0] = '\0';
	}
	return (1);
}

static char	*gnl_return(char **readed, size_t len, char *end)
{
	char	*line;
	char	*tmp;

	if (*readed[0] == '\0')
		return (free(*readed), *readed = NULL, NULL);
	if (!end)
	{
		line = ft_substr_gnl(*readed, 0, len);
		free(*readed);
		*readed = NULL;
		return (line);
	}
	line = ft_substr_gnl(*readed, 0, end - *readed + 1);
	if (!line)
		return (free (*readed), *readed = NULL, NULL);
	tmp = *readed;
	*readed = ft_substr_gnl(tmp, end - tmp + 1, len - (end - tmp + 1));
	free(tmp);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*readed;
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		reading;
	size_t		len;
	char		*end;

	if (!gnl_checks(fd, &readed))
		return (NULL);
	reading = 1;
	len = ft_strlen_gnl(readed);
	end = NULL;
	while (!end && reading > 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (reading == -1)
			return (free(readed), readed = NULL, NULL);
		buffer[reading] = '\0';
		readed = ft_strjoin_gnl(readed, buffer, len, reading);
		if (!readed)
			return (NULL);
		len = len + reading;
		end = ft_strchr_gnl(readed, '\n');
	}
	return (gnl_return(&readed, len, end));
}
