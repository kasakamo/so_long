/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kasakamo <kasakamo@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 18:47:34 by kasakamo          #+#    #+#             */
/*   Updated: 2025/07/02 18:42:20 by kasakamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
	int		pl_cnt;
	int		ex_cnt;
	int		cl_cnt;
	int		pl_x;
	int		pl_y;
}	t_map;

char	**loadmap(const char *file, int *height);

#endif
