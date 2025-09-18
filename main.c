/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:45:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/19 05:08:28 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	find_player(t_game *game)
{
	int x;
	int y;

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

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: mlx_init failed\n");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, \
		game->width * TILE_SIZE, \
		game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_printf("Error: mlx_new_window failed\n");
		exit(1);
	}
	find_player(game);
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_printf("Usage: %s map.ber\n", av[0]), 1);
	if (!(load_map(av[1], &game)))
	{
		free_map(&game);
		return (ft_printf("Error: Invalid map.\n"), 1);
	}
	init_game(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L<<0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
}
