/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 16:39:16 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 16:39:18 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# include <math.h>
# include <string.h>
# include <stdio.h>
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <time.h>
# include "keys.h"

# define MOVE_DIST 13
# define ROT_DEG 12
# define SCR_WID 500
# define SCR_HGT 500
# define TEX_WID 64
# define TEX_HGT 64
# define TEX_SIZE 64*64
# define MAP_WID 16
# define MAP_HGT 16
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define UDIV 1
# define VDIV 1
# define VMOVE 0.0

typedef struct	s_vecd
{
	double		x;
	double		y;
}				t_vecd;

typedef struct	s_vec
{
	int			x;
	int			y;
}				t_vec;

typedef struct	s_sprite
{
	double		x;
	double		y;
	int			texture_id;
}				t_sprite;

typedef struct	s_img
{
	void		*img;
	char		*str;
	int			endian;
	int			bpp;
	int			sline;
}				t_img;

typedef struct	s_wolf
{
	void		*mlx;
	void		*win;
	t_img		img;
	int			world_map[MAP_WID][MAP_HGT];
	int			textures[8][TEX_WID * TEX_HGT];
	int			sprite_nr;
	int			sprite_order[MAP_WID * MAP_HGT];
	double		sprite_distance[MAP_WID * MAP_HGT];
	t_sprite	sprites[MAP_WID * MAP_HGT];
	t_vecd		p_pos;
	t_vecd		p_dir;
	t_vecd		plane;
	t_vecd		r_pos;
	t_vecd		r_dir;
	t_vecd		delta_dist;
	t_vecd		side_dist;
	t_vecd		floor2wall;
	t_vecd		current_floor;
	t_vecd		sprite;
	t_vecd		transform;
	t_vec		floor_tex;
	t_vec		sprite_scale;
	t_vec		draw_start_vec;
	t_vec		draw_end_vec;
	t_vec		step;
	t_vec		map;
	t_vec		tex;
	int			side;
	int			hit;
	int			line_hgt;
	int			draw_start;
	int			draw_end;
	int			tex_num;
	int			d;
	int			vmovescreen;
	double		spritescreenx;
	double		inv_det;
	double		zbuffer[SCR_WID];
	double		time;
	double		old_time;
	double		delta_time;
	double		camera_x;
	double		perp_wall_dist;
	double		wall_x;
	double		dist_wall;
	double		dist_player;
	double		current_dist;
	double		weight;
	double		move_speed;
	double		rotation_speed;
}				t_wolf;

int				ft_atoi(const char *str);
void			*ft_memset(void *s, int c, size_t n);
void			load_image(int *tex, char *path);
void			pixel_put(t_wolf *w, int x, int y, int color);
void			comb_sort(int *order, double *dist, int amount);
int				wolf(t_wolf *w);
void			move(t_wolf *w, int dir);
void			rotate(t_wolf *w, int dir);
int				keyboard_input(int key, t_wolf *w);
void			draw_walls(t_wolf *w);
void			calc_sizes(t_wolf *w, int i);
void			draw_sprite(t_wolf *w, int i);
void			render_sprites(t_wolf *w);
void			swapd(double *a, double *b);
void			swap(int *a, int *b);
void			comb_sort(int *order, double *dist, int amount);
void			prep_data_for_x(t_wolf *w, int x);
void			calc_dists(t_wolf *w);
void			process_dda(t_wolf *w);
void			calc_wall_sizes(t_wolf *w);
void			texture_coord(t_wolf *w, int x);
void			floor_to_wall_directions(t_wolf *w);
void			draw_floor_cell(t_wolf *w, int x);
void			read_sprites(t_wolf *w);
#endif
