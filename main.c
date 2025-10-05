/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:45:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/10/05 18:08:24 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_putstr_fd("Error\nmlx_init failed\n", 2);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, \
		game->width * TILE_SIZE, \
		game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_putstr_fd("Error\nmlx_new_window failed\n", 2);
		exit(1);
	}
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

int	is_ber(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 5)
		return (0);
	if (ft_strncmp(file + len - 4, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac != 2)
		return (ft_putstr_fd("Error\nInvalid args count.\n", 2), 1);
	if (!is_ber(av[1]))
		return (ft_putstr_fd("Error\nMap file must have .ber\n", 2), 1);
	if (!(load_map(av[1], &game)))
	{
		free_map(&game);
		return (ft_putstr_fd("Error\nInvalid map.\n", 2), 1);
	}
	init_game(&game);
	load_textures(&game);
	render_map(&game);
	mlx_hook(game.win, 2, 1L << 0, handle_key, &game);
	mlx_hook(game.win, 17, 0, close_game, &game);
	mlx_loop(game.mlx);
}
