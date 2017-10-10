/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 15:18:09 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/08 17:48:47 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	shape2(int i)
{
	if (i <= 14)
	{
		if (i == 10)
			return (0x01112021);
		else if (i == 11)
			return (0x00010212);
		else if (i == 12)
			return (0x00011020);
		else if (i == 13)
			return (0x00101112);
		return (0x01101112);
	}
	if (i == 15)
		return (0x01101121);
	else if (i == 16)
		return (0x00010211);
	else if (i == 17)
		return (0x00101120);
	return (0x00011011);
}

int	shape(int i)
{
	if (i <= 9)
	{
		if (i <= 4)
		{
			if (i == 0)
				return (0x00102030);
			else if (i == 1)
				return (0x00010203);
			else if (i == 2)
				return (0x00011112);
			else if (i == 3)
				return (0x01101120);
			return (0x01021011);
		}
		else if (i == 5)
			return (0x00101121);
		else if (i == 6)
			return (0x00102021);
		else if (i == 7)
			return (0x02101112);
		else if (i == 8)
			return (0x00011121);
		return (0x00010210);
	}
	return (shape2(i));
}

int	check(t_ui colxy, int f, char *s, char c)
{
	t_uc	col;
	t_uc	x;
	t_uc	y;
	int		r;

	col = (colxy >> 16) & 0xff;
	x = (colxy >> 8) & 0xff;
	y = colxy & 0xff;
	f = shape(f);
	r = 0;
	if (((col * (x + N3X(f))) + y + N3Y(f)) > col * col)
		return (-1);
	if (s[col * (x + N0X(f)) + y + N0Y(f)] == c)
		r++;
	if (s[col * (x + N1X(f)) + y + N1Y(f)] == c)
		r++;
	if (s[col * (x + N2X(f)) + y + N2Y(f)] == c)
		r++;
	if (s[col * (x + N3X(f)) + y + N3Y(f)] == c)
		r++;
	return (r);
}

int	place(t_ui colxy, int f, char *s, char c)
{
	t_uc	col;
	t_uc	x;
	t_uc	y;

	col = (colxy >> 16) & 0xff;
	x = (colxy >> 8) & 0xff;
	y = colxy & 0xff;
	f = shape(f);
	s[col * (x + N0X(f)) + y + N0Y(f)] = c;
	s[col * (x + N1X(f)) + y + N1Y(f)] = c;
	s[col * (x + N2X(f)) + y + N2Y(f)] = c;
	s[col * (x + N3X(f)) + y + N3Y(f)] = c;
	return (0);
}
