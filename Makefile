NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I includes

SRC_DIR     = src
SRC         = $(SRC_DIR)/main.c $(SRC_DIR)/parser.c $(SRC_DIR)/stack_utils.c $(SRC_DIR)/utils.c \
							$(SRC_DIR)/sort_small.c $(SRC_DIR)/sort_three.c $(SRC_DIR)/operations_push.c \
							$(SRC_DIR)/operations_swap.c $(SRC_DIR)/operations_rotate.c $(SRC_DIR)/operations_reverserotate.c \

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