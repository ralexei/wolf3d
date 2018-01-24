/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrusu <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 14:13:54 by alrusu            #+#    #+#             */
/*   Updated: 2017/06/27 17:31:35 by alrusu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void				*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char*)s;
	while (i < n)
		str[i++] = c;
	return (str);
}

void				swapd(double *a, double *b)
{
	int				c;

	c = *a;
	*a = *b;
	*b = c;
}

void				swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void				comb_sort(int *order, double *dist, int amount)
{
	int				var[4];

	var[2] = var[3] + var[0];
	var[0] = amount;
	var[1] = 0;
	while (var[0] > 1 || var[1])
	{
		var[0] = (var[0] * 10) / 13;
		if (var[0] == 9 || var[0] == 10)
			var[0] = 11;
		if (var[0] < 1)
			var[0] = 1;
		var[1] = 0;
		var[3] = 0;
		while (var[3] < amount - var[0])
		{
			if (dist[var[3]] < dist[var[2]])
			{
				swapd(&dist[var[3]], &dist[var[2]]);
				swap(&order[var[3]], &order[var[2]]);
				var[1] = 1;
			}
			var[3]++;
		}
	}
}
