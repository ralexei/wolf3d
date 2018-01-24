/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_loader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:36:22 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 15:56:05 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static int		if_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\f'
			|| c == '\v')
		return (1);
	return (0);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			neg;
	int			rez;

	i = 0;
	neg = 1;
	rez = 0;
	while (if_space(str[i]))
		i++;
	if ((str[i] == '-' || str[i] == '+') && str[i + 1] >= '0' &&
		str[i + 1] <= '9')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		rez *= 10;
		rez += str[i] - '0';
		i++;
	}
	return (neg * rez);
}

int				get_line(int fd, char *line)
{
	char		c[2];
	char		len;
	int			i;

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

void			load_image(int *tex, char *path)
{
	int			fd;
	int			i;
	char		line[8];

	line[7] = '\0';
	i = 0;
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
