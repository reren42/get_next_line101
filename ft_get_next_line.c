/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:53:35 by reren             #+#    #+#             */
/*   Updated: 2024/12/29 06:58:18 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_thatsit(char *s, int fd)
{
    size_t i;
    char *temp;
    temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if(!s)
        return(NULL);
    i = -1;
	while (s[++i] != '\0')
		if (s[i] == '\n')
			return (1);
	return (0);
}

static char	*ft_hold(char *hold, char *buf)
{
	char	*res;

	res = 0;
	if (!hold && buf)
	{
		res = ft_strdup(buf);
		if (!res)
			return (NULL);
		return (res);
	}
	res = ft_strjoin(hold, buf);
	free(hold);
	return (res);
}

static char	*ft_line_size(char *hold)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	if (!hold)
		return (0);
	while (hold[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (0);
	j = 0;
	while (j < i + 1)
	{
		line[j] = hold[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
// artık veri line'a kopyalandı.
static char	*ft_recreate(char *hold)
{
	size_t	i;
	char	*res;

	i = 0;
	if (!hold)
		return (NULL);
	while (hold[i] != '\n')
		i++;
	if (hold[i + 1] == '\0')
		return (free(hold));
	res = ft_substr(hold, i + 1, ft_strlen(hold));
	if (!res)
	{
		free(hold);
		return (NULL);
	}
	free(hold);
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	long		bytes_read;
	static char	*hold = NULL;
	char		*line;

	line = 0;
	bytes_read = BUFFER_SIZE;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(hold));
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if ((bytes_read <= 0 && !hold) || bytes_read == -1)
			return (free(hold));
		buf[bytes_read] = '\0';
		hold = ft_hold(hold, buf);
		if (ft_thatsit(hold, 0))
		{
			line = ft_line_size(hold);
			if (!line)
				return (free(hold));
			return (hold = ft_recreate(hold), line);
		}
	}
	return (free(hold));
}
