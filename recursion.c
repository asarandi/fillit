/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:04:33 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/09 17:42:45 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	recursion(char *s, int i, int f, int *map)
{
	int	x;
	int	y;

	if (map[f] == -1)
		return (1);
	x = 0;
	while (x < i)
	{
		y = 0;
		while (y < i)
		{
			if ((check(PACK((i + 1), x, y), map[f], s, '.')) == 4)
			{
				place(PACK((i + 1), x, y), map[f], s, f + 'A');
				if (recursion(s, i, ++f, map))
					return (1);
				else
					place(PACK((i + 1), x, y), map[--f], s, '.');
			}
			y++;
		}
		x++;
	}
	return (0);
}
