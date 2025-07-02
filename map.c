/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:44:52 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/02 19:04:28 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>

int	is_surrounded_by_walls()
{
	
}

int	check_line_chars(t_map *map, char *line, int y)
{
	int	x;

	map->pl_cnt = 0;
	map->ex_cnt = 0;
	map->cl_cnt = 0;
	x = 0;
	while (line[x] && line[x] != '\n')
	{
		if (line[x] == 'P')
		{
			map->pl_cnt++;
			map->pl_x = x;
			map->pl_y = y;
		}
		else if (line[x] == 'E')
			map->ex_cnt++;
		else if (line[x] == 'C')
			map->cl_cnt++;
		else if (line[x] != '0' && line[x] != '1')
			return (0);
		x++;
	}
	return (x == map->width);
}

int	is_valid_map(t_map *map)
{
	int	i;

	if (!map->grid || map->height <= 0)
		return (0);
	map->width = 0;
	while (map->grid[0][map->width] && map->grid[0][map->width] != '\n')
		map->width++;
	i = 0;
	while (i < map->height)
	{
		if (!check_line_chars(map, map->grid[i], i))
			return (0);
		i++;
	}
	if (!is_surrounded_by_walls())
		return (0);
	if (map->pl_cnt != 1 || map->ex_cnt != 1 || map->cl_cnt < 1)
		return (0);
	return (1);
}

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
	line = get_next_line(fd);
	while (line)
	{
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = '\0';
	*height = i;
	close(fd);
	return (map);
}
