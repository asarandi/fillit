/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:01:15 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/09 17:14:02 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	quit(char *s)
{
	ft_putstr(s);
	exit(0);
}

int		main(int ac, char **av)
{
	char	*input;
	int		size;
	int		*puzzle;
	char	*output;

	if (ac != 2)
		quit("usage: fillit <input.file>\n");
	if ((size = getfilesize(av[1])) == -1)
		quit("error\n");
	if ((input = getfilecontents(av[1])) == NULL)
		quit("error\n");
	if ((validate(input, size)) != 1)
		quit("error\n");
	if ((puzzle = identify(input, size)) == NULL)
		quit("error\n");
	free(input);
	output = solve(puzzle);
	free(puzzle);
	ft_putstr(output);
	free(output);
	return (0);
}
