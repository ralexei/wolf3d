/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:58:35 by abadraja          #+#    #+#             */
/*   Updated: 2017/06/27 18:09:03 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		draw_pic(t_wolf3d *w3d, int x, int y, int color)
{
	int		i5;
	int		j5;

	w3d->eco.i2 = x;
	w3d->eco.j2 = y;
	i5 = x + 64;
	j5 = y + 64;
	if (w3d->info.option_value == 1)
	{
		i5 = x + 32;
		j5 = y + 32;
	}
	while (w3d->eco.i2 < i5)
	{
		w3d->eco.j2 = y;
		while (w3d->eco.j2 < j5)
		{
			mlx_pixel_put(w3d->info.mlx, w3d->info.win, w3d->eco.i2,
				w3d->eco.j2, color);
			w3d->eco.j2++;
		}
		w3d->eco.i2++;
	}
}

void		draw_frame2(t_wolf3d *w3d)
{
	if (w3d->eco.j == HEIGHT - 26 || w3d->eco.i == WIDTH - 26 ||
			w3d->eco.j == 25 || w3d->eco.i == 25 ||
			w3d->eco.i == WIDTH / 1.25 ||
			menu_delimitors(w3d))
	{
		w3d->info.x = w3d->eco.i;
		w3d->info.y = w3d->eco.j;
		mlx_pixel_put(w3d->info.mlx, w3d->info.win,
				w3d->info.x, w3d->info.y,
				w3d->info.color);
	}
	if ((((w3d->eco.i < WIDTH / 23) || (w3d->eco.j < HEIGHT / 18)) ||
		((w3d->eco.i > WIDTH / 1.356) ||
			(w3d->eco.j > HEIGHT / 1.074))) && w3d->eco.i < WIDTH / 1.25)
	{
		w3d->info.x = w3d->eco.i;
		w3d->info.y = w3d->eco.j;
		mlx_pixel_put(w3d->info.mlx, w3d->info.win,
				w3d->info.x, w3d->info.y,
				BLACK);
	}
}

void		draw_frame(t_wolf3d *w3d)
{
	w3d->eco.i = 25;
	w3d->eco.j = 25;
	while (w3d->eco.i < WIDTH - 25)
	{
		w3d->eco.j = 25;
		while (w3d->eco.j < HEIGHT - 25)
		{
			draw_frame2(w3d);
			w3d->eco.j++;
		}
		w3d->eco.i++;
	}
}

void		draw_data(t_wolf3d *w3d)
{
	mlx_string_put(w3d->info.mlx, w3d->info.win, 970, 27,
		w3d->info.color, "== Map Maker Demo ==");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 67,
		w3d->info.color_pallete[0], "BlueStone");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 120,
		w3d->info.color_pallete[1], "Eagle");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 170,
		w3d->info.color_pallete[2], "GreyStone");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 220,
		w3d->info.color_pallete[3], "RedBrick");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 273,
		w3d->info.color_pallete[4], "Wood");
	draw_data2(w3d);
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1015, 863,
		0x00FFFFFF, "== SAVE ==");
	draw_all_pics(w3d);
}

void		draw_data2(t_wolf3d *w3d)
{
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 325,
		w3d->info.color_pallete[5], "Barrel");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 380,
		w3d->info.color_pallete[6], "GreenLight");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 430,
		w3d->info.color_pallete[7], "Pillar");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 485,
		w3d->info.color_pallete[8], "Player");
	mlx_string_put(w3d->info.mlx, w3d->info.win, 1025, 535,
		w3d->info.color_pallete[9], "Delete");
}
