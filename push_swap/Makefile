NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
SAN_FLAG = -g3 -fsanitize=address

INC = -Iinclude -Ilibft
LIB = -Llibft -lft

LFT = libft/libft.a
SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), main.c utils.c \
	  stack.c make_stack.c operate.c print_error.c \
	  sort.c sort_op.c sort_complex.c \
	  push_sort.c rotate_sort.c swap_sort.c \
	  merge.c merge_util.c \
	  )

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

all : $(LFT) obj $(NAME)

obj/%.o : src/%.c
	@ $(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(LIB) $^ -o $@

clean:
	@$(MAKE) -s -C libft $@
	rm -rf obj

fclean: clean
	@make -s -C libft $@
	@rm -rf $(NAME)

obj:
	@mkdir -p obj

$(LFT):
	@make -s -C libft bonus

re: fclean all

norm:
	@norminette src/ include/

libftnorm:
	@norminette libft/*/**.c
	@norminette libft/*.h

.PHONY: all clean fclean re
