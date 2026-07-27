NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -I includes

LIBFT_DIR   = includes/libft
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src
SRC         = $(wildcard $(SRC_DIR)/*.c)
OBJ         = $(SRC:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re