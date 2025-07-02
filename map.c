/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:44:52 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/30 19:10:19 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

char	**load_map(const char *file, int *height)
{
	int		fd;
	char	**map;
	char	*line;
	int		i;

	fd = open(file, O_RDONLY);
	map = malloc(sizeof(char *) * 100000);
	if (!map || fd < 0)
		return (NULL);
	i = 0;
	while ((line = get_next_line(fd)))
		map[i++] = line;
	map[i] = '\0';
	*height = i;
	close(fd);
	return (map);
}
