/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:11:08 by abadraja          #+#    #+#             */
/*   Updated: 2017/06/27 18:09:11 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void		prepare_mlx(t_wolf3d *w3d)
{
	w3d->info.mlx = mlx_init();
	w3d->info.win = mlx_new_window(w3d->info.mlx,
		WIDTH, HEIGHT, "Wolf3d_map");
	w3d->info.img = mlx_new_image(w3d->info.mlx, WIDTH, HEIGHT);
	w3d->info.str = ft_strnew(1);
	w3d->info.str = mlx_get_data_addr(w3d->info.img, &w3d->info.bpp,
		&w3d->info.sline, &w3d->info.endian);
	w3d->info.color = 0x00FFFFFF;
	load_image(w3d->info.textures[0], "assets/bluestone32.txtex");
	load_image(w3d->info.textures[1], "assets/eagle32.txtex");
	load_image(w3d->info.textures[2], "assets/greystone32.txtex");
	load_image(w3d->info.textures[3], "assets/redbrick32.txtex");
	load_image(w3d->info.textures[4], "assets/wood32.txtex");
	load_image(w3d->info.textures[5], "assets/barrel32.txtex");
	load_image(w3d->info.textures[6], "assets/greenlight32.txtex");
	load_image(w3d->info.textures[7], "assets/pillar32.txtex");
	load_image(w3d->info.textures[8], "assets/kek.txtex");
}

int			menu_delimitors(t_wolf3d *w3d)
{
	if (!(w3d->eco.j % 52) && w3d->eco.i > WIDTH / 1.25 &&
		w3d->eco.j < HEIGHT - 100)
		return (1);
	if ((!(w3d->eco.j % 52) || !(w3d->eco.i % 52)) &&
		w3d->eco.i < WIDTH / 1.341)
		return (1);
	return (0);
}

void		fill_bitmap(t_wolf3d *w3d)
{
	FILE		*fileid;

	fileid = fopen("exp.txt", "w");
	w3d->eco.i = 0;
	w3d->eco.j = 0;
	while (w3d->eco.i < 16)
	{
		w3d->eco.j = 0;
		while (w3d->eco.j < 16)
		{
			fprintf(fileid, "%3d", w3d->info.bitmap[w3d->eco.i][w3d->eco.j]);
			w3d->eco.j++;
		}
		fprintf(fileid, "\n");
		w3d->eco.i++;
	}
	fclose(fileid);
}

void		start(t_wolf3d *w3d)
{
	prepare_mlx(w3d);
	prepare_map(w3d);
	prepare_bitmap(w3d);
	prepare_color_pallete(w3d);
	prepare_icon_color(w3d);
	draw_frame(w3d);
	draw_data(w3d);
	mlx_mouse_hook(w3d->info.win, ft_mouse_motion, w3d);
	mlx_key_hook(w3d->info.win, ft_key_hook, w3d);
	mlx_loop(w3d->info.mlx);
}

int			main(int ac, char **av)
{
	t_wolf3d	w3d;

	ft_putnbr(ac);
	ft_putendl(av[0]);
	start(&w3d);
	return (0);
}
