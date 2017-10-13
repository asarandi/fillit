/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:36:05 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/13 11:36:11 by asarandi         ###   ########.fr       */
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

char	*newsquare(int size)
{
	char	*square;
	int		i;

	square = ft_memalloc((size * size) + size + 21);
	i = 0;
	while (i < (size * size) + size)
	{
		square[i] = '.';
		i++;
		if (i % (size + 1) == 0)
			square[i - 1] = '\n';
	}
	return (square);
}

char	*solve(int *map)
{
	int		i;
	int		sqsize;
	char	*sq;

	i = 0;
	while (map[i] != -1)
		i++;
	sqsize = i * 4;
	i = 1;
	while (i * i < sqsize)
		i++;
	sq = newsquare(i);
	while ((recursion(sq, i, 0, map)) == 0)
	{
		i++;
		free(sq);
		sq = newsquare(i);
	}
	return (sq);
}
