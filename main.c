/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 11:38:48 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/13 11:38:51 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			getfilesize(char *filename)
{
	int		fd;
	int		size;
	int		r;
	char	buf;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	size = 0;
	while ((r = read(fd, &buf, 1)) == 1)
		size++;
	close(fd);
	if (r == 0)
		return (size);
	else
		return (-1);
}

void		*getfilecontents(char *filename)
{
	int		size;
	int		r;
	int		fd;
	t_uc	*mem;

	if ((size = getfilesize(filename)) == -1)
		return (NULL);
	if ((mem = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)))
	{
		r = read(fd, mem, size);
		close(fd);
		if (r == size)
			return (mem);
	}
	free(mem);
	return (NULL);
}

void	quit(char *s)
{
	ft_putstr(s);
	exit(1);
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
