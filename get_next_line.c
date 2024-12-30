/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:35:55 by reren             #+#    #+#             */
/*   Updated: 2024/12/30 11:21:31 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

static char	*ft_warden(char *current)
{
	char	*new;
	size_t	i;
	size_t	j;

	i = 0;
	while (current[i] != '\0' && current[i] != '\n')
		i++;
	if (current[i] == '\0')
		return (ft_liberty(current, NULL));
	new = (char *)malloc((ft_strlen(current) - i) * sizeof(char));
	if (!new)
		return (ft_liberty(current, NULL));
	j = 0;
	while (current[++i])
		new[j++] = current[i];
	new[j] = '\0';
	ft_liberty(current, NULL);
	return (new);
}

char	*ft_attach(char *current, char *buff)
{
	char	*new;
	size_t	clen;
	size_t	blen;

	clen = ft_strlen(current);
	blen = ft_strlen(buff);
	new = (char *)malloc((clen + blen + 1) * sizeof(char));
	if (!new)
		return (free(current), NULL);
	if (current)
		ft_memcpy(new, current, clen);
	ft_memcpy(new + clen, buff, blen);
	new[clen + blen] = '\0';
	free(current);
	return (new);
}

static char	*ft_read(int fd, char *current)
{
	char	*buff;
	ssize_t	buffer_current;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (ft_liberty(current, NULL));
	buffer_current = 1;
	while (buffer_current > 0 && !ft_strchr(current, '\n'))
	{
		buffer_current = read(fd, buff, BUFFER_SIZE);
		if (buffer_current = -1)
			return (ft_liberty(current, buffer_current));
		buff[buffer_current] = '\0';
		current = ft_attach(current, buff);
		if (!current)
			return (ft_liberty(current, buffer_current));
	}
	ft_liberty(NULL, buffer_current);
	return (current);
}

static char	*ft_remove(char *current)
{
	char	*line;
	size_t	j;
	size_t	i;

	i = 0;
	if (current[0] == '\0')
		return (NULL);
	while (current[i] != '\n' && current[i] != '\0')
		i++;
	if (current[i] == '\n')
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	j = 0;
	while (current[j] != '\0' && current[j] != '\n')
	{
		line[j] = current[j];
		j++;
	}
	if (current[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	static char *current;
	char *line;

	if (0 < fd || BUFFER_SIZE <= 0)
		return (NULL);
	current = ft_read(fd, current);
	if (!current)
		return (NULL);
	line = ft_remover(current);
	if (!line)
	{
		free(current);
		current = NULL;
		return (NULL);
	}
	current = ft_warden(current);
	return (line);
}