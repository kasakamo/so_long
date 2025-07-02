/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:45:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/02 18:20:21 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	map;
	int		i;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	map.gird = load_map(av[1], &map.height);
	if (!map.grid)
	{
		ft_printf("Error: failed to load map.\n");
		return (1);
	}
	if (!is_valid_map(&map))
	{
		ft_printf("Error: invalid map.\n");
		return (1);
	}
	ft_printf("Map is valid!\n");
	i = 0;
	while (i < map.height)
		ft_printf("%s", map.grid[i++]);
}
