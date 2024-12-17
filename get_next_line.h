/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:50:48 by reren             #+#    #+#             */
/*   Updated: 2024/12/17 18:06:04 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
#endif

#include <stddef.h>

size_t ft_strlen(char const *s);
char	*ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strchr(const char *s, int c);


#endif