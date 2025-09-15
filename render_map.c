/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 19:30:27 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/15 03:10:48 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map(t_game *game)
{
	int		x;
	int		y;
	char	c;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (x < game->width)
		{
			c = hame->map[y][x];
			put_tile(game, game->floor, x, y);
			if (c == '1')
				put_tile(game, game->wall, x, y);
			else if (c == 'P')
				put_tile(game, game->player, x, y);
			else if (c == 'E')
				put_tile(game, game->exit, x, y);
			else if (c == 'C')
				put_tile(game, game->collect, x, y);
			x++;
		}
		y++;
	}
}
