/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:50:48 by reren             #+#    #+#             */
/*   Updated: 2024/12/15 02:52:07 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <stddef.h>

size_t erjhon_strlen(char const *s);
char	*erjhon_strdup(const char *s);
char *erjhon_strjoin(char const *s1, char const *s2);
char	*erjhon_substr(const char *s, unsigned int start, size_t len);

#endif