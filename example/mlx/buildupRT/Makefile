NAME = buildupRT

CC = cc
FLAGS = -Wall -Werror -Wextra

LFT = libft/libft.a

INC = -Ivector -Ilibft
LIB = -Llibft -lft -lmlx -framework OpenGL -framework AppKit

SRC = vector/operat.c vector/product.c vector/ray.c vector/vec_utils.c vector_draw_with_cam.c 
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	$(CC) $(INC) -o $@ -c $<
#	$(CC) $(FLAGS) $(INC) -o $@ -c $<

all: $(LFT) obj $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)
#	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(LFT):
	@$(MAKE) -s -C libft

clean: 
	@$(MAKE) -s -C libft $@
	rm -rf obj

fclean: clean
	@make -s -C libft $@
	@rm -rf $(NAME)

re: fclean all

obj:
	@mkdir -p obj