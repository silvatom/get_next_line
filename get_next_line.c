/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anjose-d <anjose-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/01 12:46:04 by anjose-d          #+#    #+#             */
/*   Updated: 2021/09/01 21:22:23 by anjose-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char **buffer_scan, char **line);
ssize_t	ft_idline(char **buffer_scan, char **buffer, char **line, int fd);

char	*get_next_line(int fd)
{
	static char	*buffer_scan = NULL;
	char		*buffer;
	char		*line;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (read(fd, buffer, 0) < 0)
	{
		free(buffer);
		return (NULL);
	}
	if (!buffer_scan)
		buffer_scan = ft_strdup("");
	n = ft_idline(&buffer_scan, &buffer, &line, fd);
	if (!line && !n)
		return (NULL);
	return (line);
}

ssize_t	ft_idline(char **buffer_scan, char **buffer, char **line, int fd)
{
	ssize_t	n;
	char	*fptr;

	n = 1;
	while (!ft_strchr(*buffer_scan, '\n') && n)
	{
		n = read(fd, *buffer, BUFFER_SIZE);
		(*buffer)[n] = '\0';
		fptr = *buffer_scan;
		*buffer_scan = ft_strjoin(fptr, *buffer);
		free(fptr);
	}
	free(*buffer);
	*buffer = NULL;
	*buffer_scan = get_line(buffer_scan, line);
	if (**line == '\0')
	{
		free(*line);
		*line = NULL;
	}
	return (n);
}

char	*get_line(char **buffer_scan, char **line)
{
	char	*new_buff;
	ssize_t	i;

	i = 0;
	new_buff = NULL;
	while (*(*buffer_scan + i) != '\n' && *(*buffer_scan + i) != '\0')
		i++;
	if (*(*buffer_scan + i) == '\n')
	{
		i++;
		*line = ft_substr(*buffer_scan, 0, i);
		new_buff = ft_strdup(*buffer_scan + i);
	}
	else
		*line = ft_strdup(*buffer_scan);
	free(*buffer_scan);
	*buffer_scan = NULL;
	return (new_buff);
}
