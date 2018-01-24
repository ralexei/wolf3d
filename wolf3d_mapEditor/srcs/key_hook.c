/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 18:13:26 by abadraja          #+#    #+#             */
/*   Updated: 2017/06/27 18:12:02 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			ft_key_hook(int key, t_wolf3d *w3d)
{
	if (key == KEY_ESC)
		exit(1);
	(void)w3d;
	return (0);
}

int			ft_mouse_motion(int but, int x, int y, t_wolf3d *w3d)
{
	w3d->info.cnt_x = 0;
	w3d->info.cnt_y = 0;
	w3d->info.key_x = x - w3d->eco.i;
	w3d->info.key_y = y - w3d->eco.j;
	w3d->eco.i = 55;
	w3d->eco.j = 55;
	while (w3d->info.key_x > 50)
	{
		w3d->info.cnt_x++;
		w3d->info.key_x -= 52;
	}
	while (w3d->info.key_y > 50)
	{
		w3d->info.cnt_y++;
		w3d->info.key_y -= 52;
	}
	mouse_motion_cycle(but, x, y, w3d);
	return (0);
}

void		mouse_motion_cycle2(int but, int x, int y, t_wolf3d *w3d)
{
	(void)x;
	(void)y;
	if (w3d->info.cnt_x - 1 == w3d->eco.i && w3d->info.cnt_y - 1 == w3d->eco.j)
	{
		w3d->info.bitmap[w3d->eco.i][w3d->eco.j] =
			w3d->info.objselected;
		w3d->info.option_value = 1;
		draw_pic2(w3d, w3d->info.objselected);
	}
	if (((w3d->info.cnt_y - 1 > 14) && (w3d->info.cnt_y - 1 < 17)) &&
			((w3d->info.cnt_x - 1 < 23) && (w3d->info.cnt_x - 1 >= 17)))
	{
		ft_putendl("Save!");
		ft_putnbr(but);
		fill_bitmap(w3d);
		exit(1);
	}
	else if ((w3d->info.cnt_y - 1 == w3d->eco.j) && (w3d->info.cnt_x - 1 <= 22)
			&& (w3d->info.cnt_x - 1 >= 18))
	{
		w3d->info.objselected = w3d->info.row[w3d->eco.j];
		if (w3d->info.row[w3d->eco.j] >= 10 &&
			w3d->info.row[w3d->eco.j] <= 15)
			w3d->info.objselected = 0;
	}
}

void		mouse_motion_cycle(int but, int x, int y, t_wolf3d *w3d)
{
	w3d->eco.i = 0;
	w3d->eco.j = 0;
	while (w3d->eco.i < 16)
	{
		w3d->eco.j = 0;
		while (w3d->eco.j < 16)
		{
			mouse_motion_cycle2(but, x, y, w3d);
			w3d->eco.j++;
		}
		w3d->eco.i++;
	}
}

void		draw_pic2(t_wolf3d *w3d, int color)
{
	int		i6;
	int		j6;
	int		temp_cnt_x;
	int		temp_cnt_y;

	temp_cnt_y = 1;
	temp_cnt_x = 1;
	i6 = 55;
	j6 = 55;
	while (temp_cnt_x < w3d->info.cnt_x)
	{
		i6 += 52;
		temp_cnt_x++;
	}
	while (temp_cnt_y < w3d->info.cnt_y)
	{
		j6 += 52;
		temp_cnt_y++;
	}
	if (color)
		draw_texture(w3d, w3d->info.textures[color - 1], i6 + 8, j6 + 8);
	else
		draw_pic(w3d, i6 + 8, j6 + 8, BLACK);
}
