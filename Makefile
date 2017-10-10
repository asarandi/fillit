# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asarandi <asarandi@student.42.us.org>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 14:29:00 by asarandi          #+#    #+#              #
#    Updated: 2017/10/09 18:29:00 by asarandi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fillit
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

SRC			= ft_memalloc.c \
			  ft_memcpy.c \
			  ft_putchar.c \
			  ft_strlen.c \
			  ft_putstr.c \
			  shape.c \
			  getfilecontents.c \
			  main.c \
			  validate.c \
			  recursion.c \
			  solve.c \
			  identify.c

OBJ			= $(SRC:%.c=%.o)
DEPS		= fillit.h

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

debug: fclean
	$(CC) -g -c $(SRC)
	$(CC) -g  $(OBJ) -o $(NAME)
norm:
	norminette $(SRC) $(DEPS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
