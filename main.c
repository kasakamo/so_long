/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:45:36 by kasakamo          #+#    #+#             */
/*   Updated: 2025/06/30 19:24:00 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	char	**map;
	int		height;
	int		i;

	if (ac != 2)
	{
		ft_printf("Usage: ./so_long map.ber\n");
		return (1);
	}
	mao = load_map(av[1], &height);
	if (!map)
	{
		ft_printf("Error: failed to load map.\n");
		return (1);
	}
	i = 0;
	while (i < height)
		ft_printf("%s", map[i++]);
}
