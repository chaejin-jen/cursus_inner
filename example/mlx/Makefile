NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra

MLX = lib/mlx/libmlx.a
LFT = lib/libft/libft.a
GNL = lib/gnl/libgnl.a

INC = -Iinclude -Ilib/mlx -Ilib/libft -Ilib/gnl
LIB = -Llib/libft -lft -Llib/gnl -lgnl -Llib/mlx -lmlx -framework OpenGL -framework AppKit

SRC = src/so_long.c src/init.c src/draw.c src/key_event.c src/map.c 
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	$(CC) $(INC) -o $@ -c $<
#	$(CC) $(FLAGS) $(INC) -o $@ -c $<

all: $(LFT) $(GNL) $(MLX) obj $(NAME)
#all: obj $(NAME)
#	@$(MAKE) -C lib
#	@$(MAKE) -s -C mlx

$(NAME) : $(OBJ)
	$(CC) -o $@ $^ $(LIB)
#	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(LFT):
	@$(MAKE) -s -C lib/libft

$(GNL):
	@$(MAKE) -s -C lib/gnl

#$(MLX):
#	@$(MAKE) -s -C lib/mlx

#	@$(MAKE) -s -C lib/mlx $@

clean: 
	@$(MAKE) -s -C lib/libft $@
	@$(MAKE) -s -C lib/gnl $@
	rm -rf obj

fclean: clean
	@make -s -C lib/libft $@
	@make -s -C lib/gnl $@
	@rm -rf $(NAME)

obj:
	@mkdir -p obj



