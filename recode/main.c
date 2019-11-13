/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:22:29 by asarandi          #+#    #+#             */
/*   Updated: 2019/10/08 23:25:55 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	error(void)
{
	write(1, "error\n", 6);
	return (1);
}

int	main(int ac, char **av)
{
	int			fd;
	int			size;
	static int	tetriminos[26 + 1];
	static char	buf[BUF_SIZE];

	if (ac != 2)
		return (error());
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (error());
	size = read(fd, buf, BUF_SIZE);
	close(fd);
	if ((size < 20) || (size > MAX_FILE_SIZE))
		return (error());
	if (!is_valid(buf, size, tetriminos))
		return (error());
	solve(tetriminos);
	return (0);
}
