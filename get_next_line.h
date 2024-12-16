/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:50:48 by reren             #+#    #+#             */
/*   Updated: 2024/12/16 12:26:02 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
#endif

#include <stddef.h>

size_t erjhon_strlen(char const *s);
char	*erjhon_strdup(const char *s);
char *erjhon_strjoin(char const *s1, char const *s2);
char	*erjhon_substr(const char *s, unsigned int start, size_t len);
char	*erjhon_strchr(const char *s, int c);


#endif