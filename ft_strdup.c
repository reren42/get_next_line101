/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:48:32 by reren             #+#    #+#             */
/*   Updated: 2024/12/16 12:27:17 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

size_t erjhon_strlen(char const *s)
{
    size_t length;
    length = 0;
    printf("Baslangıc:%u\n", length);
    while (s[length])          
    {
        length++;                  
    }    
    printf("Sonuc:%u\n", length);
    return(length);
}
char	*erjhon_strdup(const char *s)
{
    char *res;
    char *res2;
    
    res = malloc(erjhon_strlen(s) + 1);
    res2 = res;
    while (*s)
    {
        *res = *s;
        res++;
        s++;
    }
    *res = '\0';
    return (res2);
}
char *erjhon_strjoin(char const *s1, char const *s2)
{
    char *s3;
    if (!s1 || !s2)
        return NULL;
    s3 = malloc(sizeof(char) * (erjhon_strlen(s1) + erjhon_strlen(s2) + 1));
    if (!s3)
        return NULL;
    char *start;
    *start = s3;
    while (*s1)
    {
        *s3++ = *s1++;
    }
    while (*s2)
    {
        *s3++ = *s2++;
    }
    *s3 = '\0';
    return start;
}

char	*erjhon_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
    
    char	*erjhon_strchr(char *s, int c)
    {
        
        size_t i;
        if(!s)
            return(NULL);
        i = 0;
        while(s[i])
        {
            if(s[i] == (char)c)
                return(&c);
            i++;
        }
        return(NULL);
    }

int main()
{  
    printf("%s", erjhon_strjoin("ercan", "eren"));   
}