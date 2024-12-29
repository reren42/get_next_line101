/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 16:50:48 by reren             #+#    #+#             */
/*   Updated: 2024/12/29 06:57:03 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
#ifndef BUFFER_SIZE
#  define BUFFER_SIZE 11
#endif

#include <stddef.h>

size_t ft_strlen(char const *s);
char	*ft_strdup(const char *s);
char *ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char    *ft_strchr(const char *s, int c);
static int ft_thatsit(char *s, int fd);
static char	*ft_hold(char *hold, char *buf);
static char	*ft_line_size(char *hold);
static char	*ft_recreate(char *hold);
char	*get_next_line(int fd);





#endif