/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:47:14 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 15:49:59 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	read_sprites(t_wolf *w)
{
	int i;
	int j;

	i = 0;
	while (i < MAP_HGT)
	{
		j = 0;
		while (j < MAP_WID)
		{
			if (w->world_map[i][j] == 9)
			{
				w->p_pos.y = i;
				w->p_pos.x = j;
				w->world_map[i][j] = 0;
			}
			if (w->world_map[i][j] >= 6)
			{
				w->sprites[w->sprite_nr++] = (t_sprite){j, i,
											(w->world_map[i][j] - 1)};
				w->world_map[i][j] = 0;
			}
			j++;
		}
		i++;
	}
}
