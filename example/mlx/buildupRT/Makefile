NAME = buildupRT

CC = cc
FLAGS = -Wall -Werror -Wextra

LFT = libft/libft.a
MLX = mlx/libmlx.a

#INC = -Ivector -Ilibft
#LIB = -Llibft -lft -lmlx -framework OpenGL -framework AppKit

 INC = -Ivector -Ilibft -Imlx
 LIB = -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

SRC = src/hit.c src/object.c src/object_utils.c src/sphere.c src/scene.c src/operat.c src/product.c src/ray.c src/vec_utils.c src/sphere02_phong_lighting.c
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	$(CC) $(INC) -o $@ -c $<
#	$(CC) $(FLAGS) $(INC) -o $@ -c $<

# all: obj $(NAME)
all: $(LFT) obj $(NAME)
#all: $(LFT) $(MLX) obj $(NAME)

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)
#	$(CC) $(FLAGS) -o $@ $^ $(LIB)

# clean:
# 	rm -rf obj

# fclean: clean
# 	@rm -rf $(NAME)

$(LFT):
	@$(MAKE) -s -C libft
$(MLX):
	@$(MAKE) -s -C mlx

clean:
	@$(MAKE) -s -C libft $@
	rm -rf obj

fclean: clean
	@$(MAKE) -s -C libft $@
	@rm -rf $(NAME)

obj:
	@mkdir -p obj

re: fclean all
