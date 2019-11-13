/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:22:51 by asarandi          #+#    #+#             */
/*   Updated: 2019/10/08 23:22:52 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const int g_valid_tetriminos[] = {
	0xe400,
	0x4c40,
	0x4e00,
	0x8c80,
	0x44c0,
	0x8e00,
	0xc880,
	0xe200,
	0x88c0,
	0xe800,
	0xc440,
	0x2e00,
	0x8888,
	0xf000,
	0x6c00,
	0x8c40,
	0xc600,
	0x4c80,
	0xcc00,
};

static int	tetrimino_to_int(char *s)
{
	int	i;
	int	res;

	res = 0;
	i = -1;
	while (++i < 20)
	{
		if ((i + 1) % 5)
		{
			res <<= 1;
			res |= (s[i] == '#');
		}
	}
	return (res);
}

static int	is_valid_tetrimino(char *s)
{
	int i;
	int j;
	int t;

	t = tetrimino_to_int(s);
	i = -1;
	while (++i < 19)
	{
		j = -1;
		while (++j < 16)
		{
			if (g_valid_tetriminos[i] == t)
				return (t);
			t = ((t << 1) | ((t >> 15) & 1)) & 0xffff;
		}
	}
	return (0);
}

static int	is_proper(char *s)
{
	int		i;
	int		dots;
	int		hashtags;

	dots = 0;
	hashtags = 0;
	i = -1;
	while (++i < 20)
	{
		if ((s[i] == '\n') && (!((i + 1) % 5)))
			continue ;
		if (!((s[i] == '.') || (s[i] == '#')))
			return (0);
		dots = (s[i] == '.') ? dots + 1 : dots;
		hashtags = (s[i] == '#') ? hashtags + 1 : hashtags;
	}
	return ((dots == 12) && (hashtags == 4));
}

int			is_valid(char *buf, int size, int *t)
{
	while (1)
	{
		if (!is_proper(buf))
			return (0);
		if (!(*(t++) = is_valid_tetrimino(buf)))
			return (0);
		if (!(size - 20))
			break ;
		if (buf[20] != '\n')
			return (0);
		buf += 21;
		size -= 21;
		if (size < 20)
			return (0);
	}
	return (1);
}
