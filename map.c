/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:44:52 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/14 20:45:36 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <fcntl.h>

int	check_elements(t_game *game)
{
	int	i;
	int	j;

	game->pl_cnt = 0;
	game->ex_cnt = 0;
	game->cl_cnt = 0;
	i = -1;
	while (++i < game->height)
	{
		j = -1;
		while (++j < game->width)
		{
			if (game->map[i][j] == 'P')
				game->pl_cnt++;
			else if (game->map[i][j] == 'E')
				game->ex_cnt++;
			else if (game->map[i][j] == 'C')
				game->cl_cnt++;
			else if (game->map[i][j] != '0' && game->map[i][j] != '1')
				return (0);
		}
	}
	return (game->pl_cnt == 1 && game->ex_cnt == 1 && game->cl_cnt > 0);
}

int	check_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if ((i == 0 || i == game->height - 1
					|| j == 0 || j == game->width - 1)
				&& game->map[i][j] != '1')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rectangular(t_game *game)
{
	int	i;
	int	len;

	game->height = 0;
	game->width = ft_strlen(game->map[0]);
	while (game->map[game->height])
		game->height++;
	i = 0;
	while (i < game->height)
	{
		len = ft_strlen(game->map[i++]);
		if (len != game->width)
			return (0);
	}
	return (1);
}

int	is_valid_map(t_game *game)
{
	if (!is_rectangular(game))
		return (0);
	if (!check_walls(game))
		return (0);
	if (!check_elements(game))
		return (0);
	return (1);
}

int	load_map(const char *file, t_game *game)
{
	int		fd;
	char	*line;
	char	*map_str;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (0);
	map_str = ft_strdup("");
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
	game->map = ft_split(map_str, '\n');
	free(map_str);
	if (!game->map || !(is_valid_map(game)))
		return (0);
	return (1);
}
