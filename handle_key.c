/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 13:50:48 by kasakamo          #+#    #+#             */
/*   Updated: 2025/09/19 05:20:54 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_move(t_game *game, char next)
{
	if (next == '1')
		return (0);
	if (next == 'C')
		game->cl_cnt--;
	if (next == 'E')
	{
		if (game->cl_cnt == 0)
		{
			game->moves++;
			ft_printf("%d\n", game->moves);
			ft_printf("You win!\n");
			close_game(game);
		}
		return (0);
	}
	return (1);
}

void	move_player(t_game *game, int dx, int dy)
{
	int		new_x;
	int		new_y;
	char	next;

	new_x = game->pl_x + dx;
	new_y = game->pl_y + dy;
	next = game->map[new_y][new_x];
	if (!check_move(game, next))
		return ;
	game->map[game->pl_y][game->pl_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->pl_x = new_x;
	game->pl_y = new_y;
	game->moves++;
	ft_printf("%d\n", game->moves);
	render_map(game);
}

int	handle_key(int keycode, t_game *game)
{
	if (keycode == XK_Escape)
		close_game(game);
	else if (keycode == XK_w || keycode == XK_Up)
		move_player(game, 0, -1);
	else if (keycode == XK_s || keycode == XK_Down)
		move_player(game, 0, 1);
	else if (keycode == XK_a || keycode == XK_Left)
		move_player(game, -1, 0);
	else if (keycode == XK_d || keycode == XK_Right)
		move_player(game, 1, 0);
	return (0);
}
