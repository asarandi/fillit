CFLAGS = -Wall -Werror -Wextra
SRC = main.c solve.c square.c validate.c
OBJ = $(SRC:%.c=%.o)

NAME = fillit

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ): $(SRC)
	$(CC) -c $(CFLAGS) $^

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
