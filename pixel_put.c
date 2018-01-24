/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/27 15:56:28 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 15:56:33 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	pixel_put(t_wolf *w, int x, int y, int color)
{
	int offset;

	offset = x * 4;
	offset += y * w->img.sline;
	*(int*)(w->img.str + offset) = color;
}
