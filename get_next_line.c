#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"
#include <stdbool.h>
#include <stdio.h>
#include <fcntl.h>

char	*buffer_settings(char **buffer, bool set)
{
	if (set)
	{
		(*buffer) = malloc(1);
		if (!(*buffer))
			return (NULL);
		(*buffer)[0] = '\0';
	}
	else
	{
		free(*buffer);
		*buffer = NULL;
	}
	return ("K");
}

ssize_t meter(char *a)
{
    ssize_t counter;

    counter = 0;
    while (a[counter])
        counter++;
    return (counter);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (n--)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}
void	setstr(char **a, char **b, ssize_t start)
{
	ssize_t	counter;

	counter = 0;
	while (counter < meter(*b))
	{
		(*a)[counter + start] = (*b)[counter];
		counter++;
	}
}

char	*unity(char **buffer, char **append)
{
	char	*temp;

	temp = malloc(meter(*buffer) + meter(*append) + 1);
	if (temp == NULL)
		return (NULL);
	setstr(&temp, buffer, 0);
	setstr(&temp, append, meter(*buffer));
	temp[meter(*buffer) + meter(*append)] = '\0';
	free(*buffer);
	(*buffer) = temp;
	return (*buffer);
}
char	*trim_buffer(char **buffer, ssize_t trim_size)
{
	char	*res;
	ssize_t	counter;

	if ((*buffer)[0] == '\0')
		return (buffer_settings(buffer, false), NULL);
	res = malloc(meter(*buffer) - trim_size + 1);
	if (!(res))
		return (NULL);
	counter = 0;
	while ((*buffer)[counter + trim_size])
	{
		res[counter] = (*buffer)[counter + trim_size];
		counter++;
	}
	res[counter] = '\0';
	free(*buffer);
	(*buffer) = res;
	return ("OK");
}

char *get_line(char *current)
{
    ssize_t i;
    ssize_t i2;
    char *buffer;
    bool eof;

    eof = false;
    i = 0;
    while (current[i] && current[i] != '\n')
        i++;
    if (current[i] == '\n') 
    {
        i++;
        eof = true;
    }
    buffer = malloc(i + 1);
    i2 = 0;
    while (i2 < i)
    {
        buffer[i2] = current[i2];
        i2++;
    }
    buffer[i2] = '\0';
    trim_buffer(&current, i + 1);
    return (buffer);
}

bool	in(char *str, char c)
{
	ssize_t	counter;

	counter = 0;
	while (str[counter])
	{
		if (str[counter] == c)
			return (true);
		counter++;
	}
	return (false);
}
char *get_next_line(int fd)
{
    static char *mem = NULL;
    char *buffer;
    ssize_t read_size;
    
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (buffer_settings(&mem, 1) == NULL)
        return (NULL);
    buffer = malloc(BUFFER_SIZE + 1);
    if (!buffer)
        return (NULL);
    read_size = 1;
    while (!(in(mem, '\n')) && read_size > 0)
    {
        read_size = read(fd, buffer, BUFFER_SIZE);
        if (read_size == -1)
            return (free(buffer), NULL);
        buffer[read_size] = '\0';
        mem = unity(&mem, &buffer);
        if (!mem)
            return (free(buffer), free(mem), NULL);
    }
    free(buffer);
    return (get_line(mem));
}
int main()
{
    int fd1 = open("asd", O_RDWR, 777);
    char *q;
    q = get_next_line(fd1);
    printf("%s", q);
    q = get_next_line(fd1);
    printf("%s", q);
    q = get_next_line(fd1);
    printf("%s", q);
    q = get_next_line(fd1);
    printf("%s", q);
    q = get_next_line(fd1);
    printf("%s", q);
    q = get_next_line(fd1);
    printf("%s", q);
}