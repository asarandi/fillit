/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   identify.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 16:04:21 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/09 19:27:07 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	identify_piece(char *m)
{
	int	f;
	int	x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			f = 0;
			while (f < 19)
			{
				if ((check(PACK(5, x, y), f, m, '#')) == 4)
					return (f);
				f++;
			}
			y++;
		}
		x++;
	}
	return (-1);
}

int	*identify(char *mem, int size)
{
	int		i;
	int		f;
	int		*map;
	char	*tmp;

	if ((size + 1) / 21 > 26)
		return (NULL);
	map = (int *)ft_memalloc((((size + 1) / 21) + 1) * sizeof(int));
	if (!map)
		return (NULL);
	i = 0;
	while (i < (size + 1) / 21)
	{
		tmp = ft_memcpy(ft_memalloc(40), &mem[i * 21], 20);
		f = identify_piece(tmp);
		free(tmp);
		if (f == -1)
		{
			free(map);
			return (NULL);
		}
		map[i++] = f;
	}
	map[i] = -1;
	return (map);
}
