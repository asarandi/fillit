/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 23:30:14 by asarandi          #+#    #+#             */
/*   Updated: 2019/10/08 23:30:30 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# define BUF_SIZE 1024
# define MAX_FILE_SIZE ((21 * 26) - 1)

int			is_valid(char *buf, int size, int *t);
char		**make_square(int size);
void		destroy_square(char **square);
void		print_square(char **square);
void		solve(int *t);

#endif
