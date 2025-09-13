/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:47:34 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/12 01:30:47 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

# define TILE_SIZE 32

typedef struct s_textures
{
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collectible;
} t_textures;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	int		width;
	int		height;
	int		pl_x;
	int		pl_y;
	int		pl_cnt;
	int		ex_cnt;
	int		cl_cnt;
	t_textures	textures;
}	t_game;

void	free_map(t_game *game);

int		load_map(const char *file, t_game *game);
int		is_valid_map(t_game *game);
int		is_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_elements(t_game *game);

void	init_game(t_game *game);
void	load_textures(t_game *game);

#endif
