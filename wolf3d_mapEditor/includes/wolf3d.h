/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:11:44 by abadraja          #+#    #+#             */
/*   Updated: 2017/05/20 14:57:07 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include <math.h>

# include "keys.h"
# include "redpallete.h"

# define HEIGHT 950
# define WIDTH 1200

# define TEX_WID 64
# define TEX_HGT 64

# define TEX_SIZE 64*64

# define MOTION_NOTIFY 6
# define PTR_MOTION_MASK (1L << 6)

typedef struct	s_info
{
	int			color_pallete[15];
	int			icon_color[15];
	int			objselected;
	int			map[16][16];
	int			bitmap[16][16];
	int			row[16];
	int			textures[9][TEX_WID * TEX_HGT];
	void		*mlx;
	void		*win;
	void		*img;
	int			color;
	char		*str;
	int			endian;
	int			bpp;
	int			sline;
	int			y;
	int			x;
	int			i;
	int			cnt_x;
	int			cnt_y;
	int			key_x;
	int			key_y;
	int			option_value;
}				t_info;

typedef	struct	s_eco
{
	int			i;
	int			i2;
	int			j;
	int			j2;

}				t_eco;

typedef	struct	s_wolf3d
{
	t_info		info;
	t_eco		eco;
}				t_wolf3d;

int				ft_key_hook(int key, t_wolf3d *r);
int				ft_mouse_motion(int but, int x, int y, t_wolf3d *r);
void			mouse_motion_cycle2(int but, int x, int y, t_wolf3d *w3d);
void			mouse_motion_cycle(int but, int x, int y, t_wolf3d *w3d);

void			start(t_wolf3d *w3d);
void			fill_bitmap(t_wolf3d *r);
int				menu_delimitors(t_wolf3d *w3d);
void			prepare_mlx(t_wolf3d *w3d);

void			prepare_color_pallete(t_wolf3d *w3d);
void			prepare_bitmap(t_wolf3d *r);
void			prepare_map(t_wolf3d *r);
void			prepare_icon_color(t_wolf3d *r);

void			draw_pic(t_wolf3d *r, int x, int y, int color);
void			draw_frame2(t_wolf3d *w3d);
void			draw_frame(t_wolf3d *w3d);
void			draw_all_pics(t_wolf3d *r);
void			draw_data(t_wolf3d *w3d);
void			draw_data2(t_wolf3d *w3d);
void			draw_pic2(t_wolf3d *w3d, int color);

void			load_image(int *tex, char *path);
int				get_line(int fd, char *line);
void			draw_all_pics(t_wolf3d *w3d);
void			draw_texture(t_wolf3d *w3d, int *a, int x, int y);

#endif
