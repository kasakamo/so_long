/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_route.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:31:17 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/19 22:27:30 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map_dup(char **map, int height)
{
	int	y;

	y = 0;
	while (y < height)
		free(map[y++]);
	free(map);
}

void	flood_fill(char **map, int y, int x, t_game *game)
{
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	if (map[y][x] == 'C')
		game->cl_fnd++;
	if (map[y][x] == 'E')
	{
		game->ex_fnd = 1;
		return ;
	}
	map[y][x] = 'F';
	flood_fill(map, y + 1, x, game);
	flood_fill(map, y - 1, x, game);
	flood_fill(map, y, x + 1, game);
	flood_fill(map, y, x - 1, game);
}

void	find_player(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			if (game->map[y][x] == 'P')
			{
				game->pl_y = y;
				game->pl_x = x;
				game->moves = 0;
				return ;
			}
			x++;
		}
		y++;
	}
	ft_printf("Error: Player not found\n");
	exit (1);
}

char	**dup_map(char **map, int height)
{
	char	**dup;
	int		y;

	dup = malloc(sizeof(char *) * (height + 1));
	if (!dup)
		return (NULL);
	y = 0;
	while (y < height)
	{
		dup[y] = ft_strdup(map[y]);
		if (!dup[y])
		{
			while (y > 0)
				free(dup[y--]);
			free(dup);
			return (NULL);
		}
		y++;
	}
	return (dup);
}

int	check_route(t_game *game)
{
	char	**map;
	int		found_c;
	int		found_e;

	map = dup_map(game->map, game->height);
	if (!map)
		return (0);
	game->cl_fnd = 0;
	game->ex_fnd = 0;
	find_player(game);
	flood_fill(map, game->pl_y, game->pl_x, game);
	free_map_dup(map, game->height);
	if (found_c != game->cl_cnt || found_e == 0)
		return (0);
	return (1);
}
