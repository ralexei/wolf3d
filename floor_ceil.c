/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:44:39 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 15:56:21 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	floor_to_wall_directions(t_wolf *w)
{
	if (w->side == 0 && w->r_dir.x > 0)
	{
		w->floor2wall.x = w->map.x;
		w->floor2wall.y = w->map.y + w->wall_x;
	}
	else if (w->side == 0 && w->r_dir.x < 0)
	{
		w->floor2wall.x = w->map.x + 1.0;
		w->floor2wall.y = w->map.y + w->wall_x;
	}
	else if (w->side == 1 && w->r_dir.y > 0)
	{
		w->floor2wall.x = w->map.x + w->wall_x;
		w->floor2wall.y = w->map.y;
	}
	else
	{
		w->floor2wall.x = w->map.x + w->wall_x;
		w->floor2wall.y = w->map.y + 1.0;
	}
}

void	draw_floor_cell(t_wolf *w, int x)
{
	int	y;

	w->dist_wall = w->perp_wall_dist;
	w->dist_player = 0.0;
	if (w->draw_end < 0)
		w->draw_end = SCR_HGT;
	y = w->draw_end + 1;
	while (y < SCR_HGT)
	{
		w->current_dist = SCR_HGT / (2.0 * y - SCR_HGT);
		w->weight = (w->current_dist - w->dist_player) /
					(w->dist_wall - w->dist_player);
		w->current_floor.x = w->weight * w->floor2wall.x + (1.0 - w->weight) *
							w->p_pos.x;
		w->current_floor.y = w->weight * w->floor2wall.y + (1.0 - w->weight) *
							w->p_pos.y;
		w->floor_tex.x = (int)(w->current_floor.x * TEX_WID) % TEX_WID;
		w->floor_tex.y = (int)(w->current_floor.y * TEX_HGT) % TEX_HGT;
		pixel_put(w, x, y, (w->textures[4][TEX_WID * w->floor_tex.y +
			w->floor_tex.x] >> 1) & 8355711);
		pixel_put(w, x, SCR_HGT - y, w->textures[2][TEX_WID * w->floor_tex.y +
			w->floor_tex.x]);
		y++;
	}
}
