/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:50:48 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/14 20:52:07 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(t_game *game, int x, int y)
{
	char	next;

	next = game->map[y][x];
	if (next == '1')
		return ;
	if (next == 'C')
		game->collect--;
	if (next == 'E')
	{
		if (game->collect == 0)
		{
			ft_printf("You win!");
			close_game(game);
		}
		return ;
	}
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[y][x] = 'P';
	game->pl_x = x;
	game->pl_y = y;
	game->moves++;
	ft_printf("%d\n", game->moves);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	int x;
	int y;

	x = game->pl_x;
	y = game->pl_y;
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		y--;
	else if (keycode == XK_s || keycode == XK_Down)
		y++;
	else if (keycode == XK_a || keycode == XK_Left)
		x--;
	else if (keycode == XK_d || keycode == XK_Right)
		x++;
	move_player(game, x, y);
	return (0);
}
