NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror -c
SAN_FLAG = -g3 -fsanitize=address

INC = -Iinclude -Ilibft
LIB = -Llibft -lft

LFT = libft/libft.a
SRC_DIR = src/

SRC = $(addprefix $(SRC_DIR), main.c \
	  argv_to_lst.c stack.c  \
	  print_error.c test_print.c operate.c)
#push.c
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

all : $(LFT) obj $(NAME)

obj/%.o : src/%.c
	@ $(CC) $(INC) -o $@ -c $<

$(NAME) : $(OBJ)
	@$(CC) $(SAN_FLAG) -o $@ $^ $(LIB)

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
