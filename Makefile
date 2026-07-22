NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I includes

SRC_DIR     = src
SRC         = $(SRC_DIR)/main.c
OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re