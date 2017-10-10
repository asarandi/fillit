/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getfilecontents.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 14:17:46 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/09 13:16:51 by asarandi         ###   ########.fr       */
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

	if (!(size = getfilesize(filename)))
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
