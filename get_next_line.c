/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 17:35:55 by reren             #+#    #+#             */
/*   Updated: 2024/12/29 20:03:03 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

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

static char *ft_read(int fd, char *current)
{
    char *puff;
    ssize_t puffer_current;

    puff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
    if(!puff)
        return(ft_liberty(puff, NULL));
    puffer_current = 1;
    while(puffer_current > 0 && !ft_strchr(current, '\n'))
    {
        puffer_current = read(fd, puff, BUFFER_SIZE);
        if(puffer_current = -1)
            return(ft_liberty(current, puffer_current));
        puff[puffer_current] == '\0';
        current = ft_attach(current, puff);
        if(!current)
            return(ft_liberty(current, puffer_current));
    }
    return(ft_liberty(NULL, puffer_current));
    return(current);
}

static char *ft_remove(char *current)
{
    char *line; 
    size_t j;
    size_t i;    
    
    i = 0;
    if(current[i] == '\0')
        return(NULL);
    while (current[i] != '\n' && current[i] != '\0') // i kaç karakter olduğunu gösterecek
    i++;
    if (current[i] == '\n')
    i++;
    line = malloc(sizeof(char) * (i + 1));
    if(!line)
        return(NULL);
    j = 0;
    while(current[j] != '\0' && current[j] != '\n')
    {
        line[j] = current[j];
        j++;
    }
    if (current[j] == '\n')
    line[j++] = '\n';
    line[j] = '\0';
    return(line);
}

char    *get_next_line(int fd)
{
    static char *current;
    char *line;
    
    if(0 < fd || BUFFER_SIZE <= 0)
        return(NULL);
    current = ft_read(fd, current);
    if(!current)
        return(NULL);
    line = ft_remover(current);
    if (!line)
    {
        free(current);
        current = NULL;
        return(NULL);
    }
    current = ft_warden(current);
    return(line);
}