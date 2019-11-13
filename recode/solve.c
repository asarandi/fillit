/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:22:40 by asarandi          #+#    #+#             */
/*   Updated: 2019/10/08 23:28:38 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check(char **square, int size, int i, int t)
{
	int		count;
	int		y;
	int		x;
	int		j;

	j = i & 0xff;
	i >>= 8;
	count = 0;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (!((t >> (15 - (y * 4 + x))) & 1))
				continue ;
			if ((i + y >= size) || (j + x >= size))
				return (0);
			if ((square[i + y][j + x] != '.'))
				return (0);
			++count;
		}
	}
	return (count == 4);
}

static void	place(char **square, int i, int t, int k)
{
	int		y;
	int		x;
	int		j;

	j = i & 0xff;
	i >>= 8;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if ((t >> (15 - (y * 4 + x))) & 1)
				square[i + y][j + x] = (char)k;
		}
	}
}

static int	recursion(char **square, int size, int *t, int k)
{
	int		i;
	int		j;

	if (!(*t))
		return (1);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (!check(square, size, (i << 8) | j, *t))
				continue ;
			place(square, (i << 8) | j, *t, k);
			if (recursion(square, size, t + 1, k + 1))
				return (1);
			place(square, (i << 8) | j, *t, '.');
		}
	}
	return (0);
}

void		solve(int *t)
{
	int		idx;
	int		done;
    int     count;
	char	**square;

    count = -1;
    while (t[++count])
        ;
	idx = 2;
	while (idx * idx < (count << 2))
		++idx;
	done = 0;
	while (!done)
	{
		square = make_square(idx);
		if ((done = recursion(square, idx, t, 'A')))
			print_square(square);
		destroy_square(square);
		++idx;
	}
}
