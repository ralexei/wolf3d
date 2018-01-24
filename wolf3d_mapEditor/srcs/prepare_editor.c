/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_editor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:00:58 by abadraja          #+#    #+#             */
/*   Updated: 2017/06/27 18:09:18 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		prepare_color_pallete(t_wolf3d *w3d)
{
	w3d->info.color_pallete[0] = CL5;
	w3d->info.color_pallete[1] = CL6;
	w3d->info.color_pallete[2] = CL7;
	w3d->info.color_pallete[3] = CL8;
	w3d->info.color_pallete[4] = CL9;
	w3d->info.color_pallete[5] = CL10;
	w3d->info.color_pallete[6] = CL11;
	w3d->info.color_pallete[7] = CL12;
	w3d->info.color_pallete[8] = CL13;
	w3d->info.color_pallete[9] = CL14;
	w3d->info.color_pallete[10] = CL15;
}

void		prepare_bitmap(t_wolf3d *w3d)
{
	w3d->eco.i = 0;
	while (w3d->eco.i < 16)
	{
		w3d->eco.j = 0;
		while (w3d->eco.j < 16)
		{
			w3d->info.bitmap[w3d->eco.i][w3d->eco.j] = 0;
			w3d->eco.j++;
		}
		w3d->eco.i++;
	}
}

void		prepare_icon_color(t_wolf3d *w3d)
{
	w3d->eco.i = 0;
	while (w3d->eco.i < 15)
	{
		w3d->info.icon_color[w3d->eco.i] = w3d->info.color_pallete[w3d->eco.i];
		w3d->eco.i++;
	}
}

void		prepare_map(t_wolf3d *w3d)
{
	int		lel;

	lel = 0;
	w3d->eco.i = 0;
	while (w3d->eco.i < 16)
	{
		w3d->eco.j = 0;
		while (w3d->eco.j < 16)
		{
			w3d->info.map[w3d->eco.i][w3d->eco.j] = lel;
			lel++;
			w3d->eco.j++;
		}
		w3d->eco.i++;
	}
	lel = 1;
	w3d->eco.i = 0;
	while (w3d->eco.i < 16)
	{
		w3d->info.row[w3d->eco.i] = lel;
		lel++;
		w3d->eco.i++;
	}
}

void		draw_all_pics(t_wolf3d *w3d)
{
	w3d->info.option_value = 0;
	draw_texture(w3d, w3d->info.textures[0], 970, 60);
	draw_texture(w3d, w3d->info.textures[1], 970, 115);
	draw_texture(w3d, w3d->info.textures[2], 970, 165);
	draw_texture(w3d, w3d->info.textures[3], 970, 220);
	draw_texture(w3d, w3d->info.textures[4], 970, 270);
	draw_texture(w3d, w3d->info.textures[5], 970, 330);
	draw_texture(w3d, w3d->info.textures[6], 970, 380);
	draw_texture(w3d, w3d->info.textures[7], 970, 425);
	draw_texture(w3d, w3d->info.textures[8], 970, 475);
}
