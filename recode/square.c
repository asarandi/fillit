/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:22:46 by asarandi          #+#    #+#             */
/*   Updated: 2019/10/08 23:25:09 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		**make_square(int size)
{
	char	**res;
	int		i;
	int		j;

	res = malloc((size + 1) * (sizeof(char *)));
	i = -1;
	while (++i < size)
	{
		res[i] = malloc(size + 2);
		j = -1;
		while (++j < size)
			res[i][j] = '.';
		res[i][j] = '\n';
		res[i][j + 1] = 0;
	}
	res[size] = NULL;
	return (res);
}

void		destroy_square(char **square)
{
	int		i;

	i = -1;
	while (square[++i])
		free(square[i]);
	free(square);
}

void		print_square(char **square)
{
	int		i;
	int		j;

	i = -1;
	while (square[++i])
	{
		j = -1;
		while (square[i][++j])
			write(1, &square[i][j], 1);
	}
}
