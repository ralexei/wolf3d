/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blabla.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:13:58 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 16:37:29 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_walls(t_wolf *w)
{
	int x;

	x = 0;
	while (x < SCR_WID)
	{
		prep_data_for_x(w, x);
		calc_dists(w);
		process_dda(w);
		calc_wall_sizes(w);
		texture_coord(w, x);
		floor_to_wall_directions(w);
		draw_floor_cell(w, x);
		x++;
	}
}

void	calc_sizes(t_wolf *w, int i)
{
	w->sprite.x = w->sprites[w->sprite_order[i]].x - w->p_pos.x;
	w->sprite.y = w->sprites[w->sprite_order[i]].y - w->p_pos.y;
	w->inv_det = 1.0 / (w->plane.x * w->p_dir.y - w->p_dir.x * w->plane.y);
	w->transform.x = w->inv_det * (w->p_dir.y * w->sprite.x - w->p_dir.x *
					w->sprite.y);
	w->transform.y = w->inv_det * (-w->plane.y * w->sprite.x + w->plane.x *
					w->sprite.y);
	w->spritescreenx = (int)((SCR_WID / 2) * (1 + w->transform.x /
					w->transform.y));
	w->vmovescreen = (int)(VMOVE / w->transform.y);
	w->sprite.y = abs((int)(SCR_HGT / (w->transform.y))) / VDIV;
	w->draw_start_vec.y = -w->sprite.y / 2 + SCR_HGT / 2 + w->vmovescreen;
	if (w->draw_start_vec.y < 0)
		w->draw_start_vec.y = 0;
	w->draw_end_vec.y = w->sprite.y / 2 + SCR_HGT / 2 + w->vmovescreen;
	if (w->draw_end_vec.y >= SCR_HGT)
		w->draw_end_vec.y = SCR_HGT - 1;
	w->sprite.x = abs((int)(SCR_HGT / (w->transform.y))) / UDIV;
	w->draw_start_vec.x = -w->sprite.x / 2 + w->spritescreenx;
	if (w->draw_start_vec.x < 0)
		w->draw_start_vec.x = 0;
	w->draw_end_vec.x = w->sprite.x / 2 + w->spritescreenx;
	if (w->draw_end_vec.x >= SCR_WID)
		w->draw_end_vec.x = SCR_WID - 1;
}

void	draw_sprite(t_wolf *w, int i)
{
	int	stripe;
	int	y;
	int	color;

	stripe = w->draw_start_vec.x;
	while (stripe < w->draw_end_vec.x)
	{
		w->tex.x = (int)(256 * (stripe - (-w->sprite.x / 2 +
					w->spritescreenx)) * TEX_WID / w->sprite.x) / 256;
		if (w->transform.y > 0 && stripe > 0 && stripe < SCR_WID &&
				w->transform.y < w->zbuffer[stripe])
			y = w->draw_start_vec.y;
		while (y < w->draw_end_vec.y)
		{
			w->d = (y - w->vmovescreen) * 256 - SCR_HGT * 128 +
				w->sprite.y * 128;
			w->tex.y = ((w->d * TEX_HGT) / w->sprite.y) / 256;
			color = w->textures[w->sprites[w->sprite_order[i]].texture_id]
					[TEX_WID * w->tex.y + w->tex.x];
			if ((color & 0x00FFFFFF) != 0)
				pixel_put(w, stripe, y, color);
			y++;
		}
		stripe++;
	}
}

void	render_sprites(t_wolf *w)
{
	int	i;

	i = 0;
	while (i < w->sprite_nr)
	{
		w->sprite_order[i] = i;
		w->sprite_distance[i] = ((w->p_pos.x - w->sprites[i].x) * (w->p_pos.x -
		w->sprites[i].x) + (w->p_pos.y - w->sprites[i].y) * (w->p_pos.y -
		w->sprites[i].y));
		i++;
	}
	comb_sort(w->sprite_order, w->sprite_distance, w->sprite_nr);
	i = 0;
	while (i < w->sprite_nr)
	{
		calc_sizes(w, i);
		draw_sprite(w, i);
		i++;
	}
}
