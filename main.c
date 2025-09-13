/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:45:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/11 20:00:38 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_textures(t_game *game)
{
	game->textures->floor = load_image(game->mlx, "textures/floor.xpm");
	game->textures->wall = load_image(game->mlx, "textures/wall.xpm");
	game->textures->player = load_image(game->mlx, "textures/player.xpm");
	game->textures->exit = load_image(game->mlx, "textures/exit.xpm");
	game->textures->collectible = load_image(game->mlx, "textures/collectible.xpm");
}

static void	*load_image(void *mlx, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		ft_printf("Error: load_texture failed");
		exit(1);
	}
	return (img);
}

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		ft_printf("Error: mlx_init failed");
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "so_long");
	if (!game->win)
	{
		ft_printf("Error: mlx_new_window failed");
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

int	main(int ac, char **av)
{
	t_game	game;
	int i;

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
}
