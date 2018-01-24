/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_drawer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 13:43:08 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 16:37:54 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	prep_data_for_x(t_wolf *w, int x)
{
	w->camera_x = 2 * x / (double)SCR_WID - 1;
	w->r_pos.x = w->p_pos.x;
	w->r_pos.y = w->p_pos.y;
	w->r_dir.x = w->p_dir.x + w->plane.x * w->camera_x;
	w->r_dir.y = w->p_dir.y + w->plane.y * w->camera_x;
	w->map.x = (int)w->r_pos.x;
	w->map.y = (int)w->r_pos.y;
	w->delta_dist.x = sqrt(1 + (w->r_dir.y * w->r_dir.y) /
		(w->r_dir.x * w->r_dir.x));
	w->delta_dist.y = sqrt(1 + (w->r_dir.x * w->r_dir.x) /
		(w->r_dir.y * w->r_dir.y));
}

void	calc_dists(t_wolf *w)
{
	if (w->r_dir.x < 0)
	{
		w->step.x = -1;
		w->side_dist.x = (w->r_pos.x - w->map.x) * w->delta_dist.x;
	}
	else
	{
		w->step.x = 1;
		w->side_dist.x = (w->map.x + 1.0 - w->r_pos.x) * w->delta_dist.x;
	}
	if (w->r_dir.y < 0)
	{
		w->step.y = -1;
		w->side_dist.y = (w->r_pos.y - w->map.y) * w->delta_dist.y;
	}
	else
	{
		w->step.y = 1;
		w->side_dist.y = (w->map.y + 1.0 - w->r_pos.y) * w->delta_dist.y;
	}
}

void	process_dda(t_wolf *w)
{
	w->hit = 0;
	while (w->hit == 0)
	{
		if (w->side_dist.x < w->side_dist.y)
		{
			w->side_dist.x += w->delta_dist.x;
			w->map.x += w->step.x;
			w->side = 0;
		}
		else
		{
			w->side_dist.y += w->delta_dist.y;
			w->map.y += w->step.y;
			w->side = 1;
		}
		if (w->world_map[w->map.x][w->map.y] > 0)
			w->hit = 1;
	}
}

void	calc_wall_sizes(t_wolf *w)
{
	if (w->side == 0)
		w->perp_wall_dist = (w->map.x - w->r_pos.x + (1 - w->step.x) / 2) /
							w->r_dir.x;
	else
		w->perp_wall_dist = (w->map.y - w->r_pos.y + (1 - w->step.y) / 2) /
							w->r_dir.y;
	w->line_hgt = (int)(SCR_HGT / w->perp_wall_dist);
	w->draw_start = -w->line_hgt / 2 + SCR_HGT / 2;
	if (w->draw_start < 0)
		w->draw_start = 0;
	w->draw_end = w->line_hgt / 2 + SCR_HGT / 2;
	if (w->draw_end >= SCR_HGT)
		w->draw_end = SCR_HGT - 1;
	w->tex_num = w->world_map[w->map.x][w->map.y] - 1;
	if (w->side == 0)
		w->wall_x = w->r_pos.y + w->perp_wall_dist * w->r_dir.y;
	else
		w->wall_x = w->r_pos.x + w->perp_wall_dist * w->r_dir.x;
	w->wall_x -= floor((w->wall_x));
}

void	texture_coord(t_wolf *w, int x)
{
	int	y;
	int color;

	w->tex.x = (int)(w->wall_x * (double)TEX_WID);
	if (w->side == 0 && w->r_dir.x > 0)
		w->tex.x = TEX_WID - w->tex.x - 1;
	if (w->side == 1 && w->r_dir.y < 0)
		w->tex.x = TEX_WID - w->tex.x - 1;
	y = w->draw_start;
	while (y < w->draw_end)
	{
		w->d = y * 256 - SCR_HGT * 128 + w->line_hgt * 128;
		w->tex.y = ((w->d * TEX_HGT) / w->line_hgt) / 256;
		color = w->textures[w->tex_num][TEX_WID * w->tex.y + w->tex.x];
		if (w->side == 1)
			color = (color >> 1) & 8355711;
		pixel_put(w, x, y, color);
		y++;
	}
	w->zbuffer[x] = w->perp_wall_dist;
}
