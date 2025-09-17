/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:47:34 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/17 16:45:25 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "mlx.h"
# include "libft.h"
# include "ft_printf.h"
# include <X11/keysym.h>
# include <X11/X.h>

# define TILE_SIZE 32

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
	int		moves;
	void	*wall;
	void	*floor;
	void	*player;
	void	*exit;
	void	*collect;
}	t_game;

void	free_map(t_game *game);

int		load_map(const char *file, t_game *game);
int		is_valid_map(t_game *game);
int		is_rectangular(t_game *game);
int		check_walls(t_game *game);
int		check_elements(t_game *game);

void	init_game(t_game *game);
void	load_textures(t_game *game);

void	render_map(t_game *game);
void	put_tile(t_game *game, void *img, int x, int y);

int		handle_key(int keycode, t_game *game);
void	move_player(t_game *game, int x, int y);

int		close_game(t_game *game);

#endif
