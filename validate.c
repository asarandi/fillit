/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:34:40 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/13 11:34:46 by asarandi         ###   ########.fr       */
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

int	validate_line(char *m, int *d, int *h)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (m[i] == '.')
			*d += 1;
		else if (m[i] == '#')
			*h += 1;
		else
			return (0);
		i++;
	}
	if (m[i] != '\n')
		return (0);
	return (1);
}

int	validate_block(char *m)
{
	int	i;
	int d;
	int h;

	i = 0;
	d = 0;
	h = 0;
	while (i < 4)
	{
		if (!validate_line(&m[i * 5], &d, &h))
			return (0);
		i++;
	}
	if ((d == 12) && (h == 4))
		return (1);
	return (0);
}

int	validate(char *mem, size_t size)
{
	size_t	i;

	if (size < 20)
		return (-1);
	i = 0;
	while (i < size)
	{
		if (!validate_block(&mem[i]))
			return (-1);
		i += 20;
		if (i == size)
			return (1);
		else if (((i + 20) < size) && (mem[i] == '\n'))
		{
			if ((mem[i + 1] == '.') || (mem[i + 1] == '#'))
				i++;
			else
				return (-1);
		}
		else
			return (-1);
	}
	return (-1);
}
