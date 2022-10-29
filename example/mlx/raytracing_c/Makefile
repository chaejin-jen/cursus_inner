NAME = buildupRT

CC = cc
FLAGS = -Wall -Werror -Wextra

LFT = libft/libft.a
MLX = mlx/libmlx.a

INC = -Iinclude -Ilibft
LIB = -Llibft -lft -lmlx -framework OpenGL -framework AppKit

#  INC = -Ivector -Ilibft -Imlx
#  LIB = -Llibft -lft -Lmlx -lmlx -framework OpenGL -framework AppKit

MAIN_SRC = $(addprefix src/main/, 6main.c)
SCENE_SRC = $(addprefix src/scene/, camera.c hit_record.c hit_sphere.c hit.c object.c ray.c scene.c)
VECTOR_SRC = $(addprefix src/vector/, length.c op_scalar.c op_vec.c product.c vector.c)

SRC = $(MAIN_SRC) $(SCENE_SRC) $(VECTOR_SRC)
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

clean:
	rm -rf obj

fclean: clean
	@rm -rf $(NAME)

$(LFT):
	@$(MAKE) -s -C libft
$(MLX):
	@$(MAKE) -s -C mlx

# clean:
# 	@$(MAKE) -s -C libft $@
# 	rm -rf obj

# fclean: clean
# 	@$(MAKE) -s -C libft $@
# 	@rm -rf $(NAME)

obj:
	@mkdir -p obj
	@mkdir -p obj/main
	@mkdir -p obj/scene
	@mkdir -p obj/vector

re: fclean all
