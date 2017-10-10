/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:04:27 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/09 17:43:36 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
