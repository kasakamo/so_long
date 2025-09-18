/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:26:30 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/19 04:19:57 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!read_and_stash(&stash, fd))
		return (NULL);
	line = extr_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = updt_stash(stash);
	return (line);
}

char	*read_and_stash(char **stash, int fd)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(*stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (free(buf), free(*stash), *stash = NULL, NULL);
		buf[bytes] = '\0';
		*stash = ft_strjoin_gnl(*stash, buf);
		if (!*stash)
			return (free(buf), NULL);
	}
	free(buf);
	return (*stash);
}

char	*extr_line(char *stash)
{
	size_t	i;

	if (!stash || stash[0] == '\0')
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		i++;
	return (ft_substr_gnl(stash, 0, i));
}

char	*updt_stash(char *stash)
{
	char	*newline;
	char	*new_stash;
	size_t	start;

	newline = ft_strchr(stash, '\n');
	if (!newline)
		return (free(stash), NULL);
	start = (newline - stash) + 1;
	new_stash = ft_substr_gnl(stash, start, ft_strlen(stash) - start);
	free(stash);
	if (!new_stash)
		return (NULL);
	return (new_stash);
}
