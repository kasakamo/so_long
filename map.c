/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:44:52 by kasakamo          #+#    #+#             */
/*   Updated: 2025/10/09 20:01:36 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

char	*read_join(const char *file)
{
	int		fd;
	char	*map_str;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (NULL);
	map_str = ft_strdup("");
	if (!map_str)
		return (NULL);
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(map_str, line);
		free(map_str);
		map_str = tmp;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (map_str);
}

int	load_map(const char *file, t_game *game)
{
	char	*map_str;

	map_str = read_join(file);
	if (!map_str || !check_nl(map_str))
		return (game->map = NULL, free(map_str), 0);
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map || !is_valid_map(game))
		return (0);
	return (1);
}
