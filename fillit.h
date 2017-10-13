/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 00:42:34 by asarandi          #+#    #+#             */
/*   Updated: 2017/10/13 13:01:21 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define PACK(a, b, c) ((a << 16) + (b << 8) + c)
# define N0X(i) ((i >> 28) & 0xf)
# define N0Y(i) ((i >> 24) & 0xf)
# define N1X(i) ((i >> 20) & 0xf)
# define N1Y(i) ((i >> 16) & 0xf)
# define N2X(i) ((i >> 12) & 0xf)
# define N2Y(i) ((i >> 8) & 0xf)
# define N3X(i) ((i >> 4 )& 0xf)
# define N3Y(i) (i & 0xf)

typedef	unsigned char	t_uc;
typedef unsigned int	t_ui;

void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	*ft_memalloc(size_t size);
char	*newsquare(int size);
char	*solve(int *map);
int		identify_piece(char *m);
int		*identify(char *mem, int size);
int		check(t_ui colxy, int f, char *s, char c);
int		getfilesize(char *filename);
int		place(t_ui colxy, int f, char *s, char c);
int		recursion(char *s, int i, int f, int *map);
int		shape(int i);
int		shape2(int i);
int		validate(char *mem, size_t size);
int		validate_block(char *m);
int		validate_line(char *m, int *d, int *h);
void	*getfilecontents(char *filename);
void	quit(char *s, int e);

#endif
