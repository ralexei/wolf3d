/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:18:45 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 18:15:34 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		error(void)
{
	write(1, "Wrong usage or map not found\n", 29);
	exit(1);
}

static void	read_map(char *path, t_wolf *w)
{
	int		fd;
	char	c[2];
	int		i;
	int		j;

	c[1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		error();
	i = -1;
	while ((read(fd, c, 1)))
	{
		if (c[0] >= '0' && c[0] <= '9')
		{
			if (j % 16 == 0)
			{
				j = 0;
				i++;
			}
			w->world_map[i][j++] = c[0] - 48;
		}
	}
}

static void	start(t_wolf *w)
{
	w->p_dir.x = -1.0;
	w->p_dir.y = 0;
	w->plane.x = 0;
	w->plane.y = 0.66;
	w->time = 0;
	w->old_time = 0;
	w->sprite_nr = 0;
	w->img.img = mlx_new_image(w->mlx, SCR_WID, SCR_HGT);
	w->img.str = mlx_get_data_addr(w->img.img, &w->img.bpp, &w->img.sline,
				&w->img.endian);
	load_image(w->textures[0], "textures/blue_stone.txtex");
	load_image(w->textures[1], "textures/eaglewall.txtex");
	load_image(w->textures[2], "textures/greystone.txtex");
	load_image(w->textures[3], "textures/redbrick.txtex");
	load_image(w->textures[4], "textures/wood.txtex");
	load_image(w->textures[5], "textures/barrel.txtex");
	load_image(w->textures[6], "textures/lamp.txtex");
	load_image(w->textures[7], "textures/pillar.txtex");
}

/*
** printf ("FPS: %lf\n", (1.0 / w->delta_time));
*/

int			wolf(t_wolf *w)
{
	int		x;

	x = 0;
	draw_walls(w);
	render_sprites(w);
	mlx_put_image_to_window(w->mlx, w->win, w->img.img, 0, 0);
	w->old_time = w->time;
	w->time = (double)clock();
	w->delta_time = (w->time - w->old_time) / (double)CLOCKS_PER_SEC;
	w->move_speed = MOVE_DIST * w->delta_time;
	w->rotation_speed = ROT_DEG * w->delta_time;
	return (0);
}

int			main(int ac, char **av)
{
	t_wolf	w;

	if (ac != 2)
		error();
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, SCR_WID, SCR_HGT, "WOLF");
	start(&w);
	read_map(av[1], &w);
	(void)ac;
	read_sprites(&w);
	mlx_loop_hook(w.mlx, wolf, &w);
	mlx_hook(w.win, KEY_PRESS, KEY_PRESS_MASK, keyboard_input, &w);
	mlx_loop(w.mlx);
	return (0);
}
