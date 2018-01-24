/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:42 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 15:55:55 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		move(t_wolf *w, int dir)
{
	if (w->world_map[(int)(w->p_pos.x + w->p_dir.x * w->move_speed)]
		[(int)w->p_pos.y] == 0)
		w->p_pos.x += dir * w->p_dir.x * w->move_speed;
	if (w->world_map[(int)w->p_pos.x]
		[(int)(w->p_pos.y + w->p_dir.y * w->move_speed)] == 0)
		w->p_pos.y += dir * w->p_dir.y * w->move_speed;
}

void		rotate(t_wolf *w, int dir)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = w->p_dir.x;
	w->p_dir.x = w->p_dir.x * cos(-w->rotation_speed * dir) - w->p_dir.y *
				sin(-w->rotation_speed * dir);
	w->p_dir.y = old_dir_x * sin(-w->rotation_speed * dir) + w->p_dir.y *
				cos(-w->rotation_speed * dir);
	old_plane_x = w->plane.x;
	w->plane.x = w->plane.x * cos(-w->rotation_speed * dir) - w->plane.y *
				sin(-w->rotation_speed * dir);
	w->plane.y = old_plane_x * sin(-w->rotation_speed * dir) + w->plane.y *
				cos(-w->rotation_speed * dir);
}

int			keyboard_input(int key, t_wolf *w)
{
	if (key == K_UP)
		move(w, 1);
	else if (key == K_DOWN)
		move(w, -1);
	if (key == K_RIGHT)
		rotate(w, 1);
	else if (key == K_LEFT)
		rotate(w, -1);
	if (key == K_ESC)
	{
		mlx_destroy_window(w->mlx, w->win);
		exit(0);
	}
	return (0);
}
