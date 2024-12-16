/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reren <reren@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 11:53:35 by reren             #+#    #+#             */
/*   Updated: 2024/12/16 12:42:17 by reren            ###   ########.fr       */
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
    while(s[i])
    {
    }
}