/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 04:48:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/19 04:49:50 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*load_image(void *mlx, char *path)
{
	int		w;
	int		h;
	void	*img;

	img = mlx_xpm_file_to_image(mlx, path, &w, &h);
	if (!img)
	{
		ft_printf("Error: load_texture failed [%s]\n", path);
		exit(1);
	}
	return (img);
}

void	load_textures(t_game *game)
{
	game->floor = load_image(game->mlx, "textures/floor.xpm");
	game->wall = load_image(game->mlx, "textures/wall.xpm");
	game->player = load_image(game->mlx, "textures/player.xpm");
	game->exit = load_image(game->mlx, "textures/exit.xpm");
	game->collect = load_image(game->mlx, "textures/collect.xpm");
}
