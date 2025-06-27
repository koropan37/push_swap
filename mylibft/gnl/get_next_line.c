/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skimura <skimura@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 19:26:08 by skimura           #+#    #+#             */
/*   Updated: 2025/06/27 11:37:54 by skimura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static ssize_t	ft_read_buf(int fd, char **buffer)
{
	ssize_t	bytes;

	*buffer = malloc(BUFFER_SIZE + 1);
	if (!*buffer)
		return (-1);
	bytes = read(fd, *buffer, BUFFER_SIZE);
	if (bytes >= 0)
		(*buffer)[bytes] = '\0';
	return (bytes);
}

static char	*ft_read_enter(int fd, char *enter)
{
	ssize_t	bytes;
	char	*buffer;

	buffer = NULL;
	bytes = 1;
	while (!ft_check_nl(enter) && bytes > 0)
	{
		bytes = ft_read_buf(fd, &buffer);
		if (bytes == -1)
		{
			free(buffer);
			free(enter);
			return (NULL);
		}
		if (bytes == 0)
			return (free(buffer), enter);
		enter = ft_strjoin_free(enter, buffer);
		free(buffer);
		buffer = NULL;
		if (!enter)
			return (NULL);
	}
	return (enter);
}

static char	*ft_get_newline(char *enter)
{
	size_t	i;

	if (!enter || !*enter)
		return (NULL);
	i = 0;
	while (enter[i] && enter[i] != '\n')
		i++;
	if (enter[i] == '\n')
		i++;
	return (ft_substr(enter, 0, i));
}

static char	*ft_trim_newline(char *enter)
{
	size_t	i;
	char	*newline;

	if (!enter)
		return (NULL);
	i = 0;
	while (enter[i] && enter[i] != '\n')
		i++;
	if (!enter[i])
	{
		free(enter);
		return (NULL);
	}
	newline = ft_strdup(enter + i + 1);
	free(enter);
	return (newline);
}

char	*get_next_line(int fd)
{
	static char	*files[FD_MAX];
	char		*line;

	if (fd < 0 || fd >= FD_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	files[fd] = ft_read_enter(fd, files[fd]);
	if (!files[fd] || !*files[fd])
	{
		free(files[fd]);
		files[fd] = NULL;
		return (NULL);
	}
	line = ft_get_newline(files[fd]);
	if (!line)
	{
		free(files[fd]);
		files[fd] = NULL;
		return (NULL);
	}
	files[fd] = ft_trim_newline(files[fd]);
	return (line);
}
