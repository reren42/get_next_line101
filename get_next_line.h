/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 18:07:25 by reren             #+#    #+#             */
/*   Updated: 2024/12/29 20:09:31 by reren            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char    *get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_liberty(char *reads, char *buff);
size_t	ft_strlen(const char *s);
void	*ft_memcpy(void *dest, const void *src, size_t n);



#endif