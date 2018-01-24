/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abadraja <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 13:58:35 by abadraja          #+#    #+#             */
/*   Updated: 2017/05/20 14:27:03 by abadraja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			get_line(int fd, char *line)
{
	char	c[2];
	char	len;
	int		i;

	c[1] = '\0';
	len = 0;
	i = 0;
	while ((read(fd, c, 1)) > 0)
	{
		if (c[0] == '\n')
			return (len);
		line[i++] = c[0];
		len++;
	}
	return (0);
}

void		load_image(int *tex, char *path)
{
	int		fd;
	int		i;
	char	line[8];

	i = 0;
	line[7] = '\0';
	if ((fd = open(path, O_RDONLY)) < 0)
		return ;
	while (i < TEX_SIZE)
	{
		get_line(fd, line);
		tex[i] = atoi(line);
		memset(line, '\0', 8);
		i++;
	}
	close(fd);
}

void		draw_texture(t_wolf3d *w3d, int *a, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	while (i < 32)
	{
		j = 0;
		while (j < 32)
		{
			mlx_pixel_put(w3d->info.mlx, w3d->info.win,
				x + i, y + j, a[j * 32 + i]);
			j++;
		}
		i++;
	}
}
