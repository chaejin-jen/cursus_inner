NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra

MLX = lib/mlx/libmlx.a
LFT = lib/libft/libft.a
GNL = lib/gnl/libgnl.a

INC = -Iinclude -Ilib/mlx -Ilib/libft -Ilib/gnl
#INC = -Iinclude -Ilib/libft -Ilib/gnl
#LIB = -Llib/libft -lft -Llib/gnl -lgnl -lmlx -framework OpenGL -framework AppKit
LIB = -Llib/libft -lft -Llib/gnl -lgnl -Llib/mlx -lmlx -framework OpenGL -framework AppKit

SRC = src/main.c src/error.c src/event_exit.c src/utils.c\
	  src/map_parse.c src/map_init.c src/map_set.c src/map_valid.c \
	  src/game_init.c src/mmap_imgs.c src/render_map.c \
	  src/keypress.c src/set_player.c src/replay.c \
	  src/update.c src/move_event.c

OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

obj/%.o : src/%.c
	@ $(CC) $(INC) -o $@ -c $<
#	$(CC) $(FLAGS) $(INC) -o $@ -c $<

all: $(LFT) $(GNL) $(MLX) obj $(NAME)
#all: obj $(NAME)
#	@$(MAKE) -C lib
#	@$(MAKE) -s -C mlx

$(NAME) : $(OBJ)
	@$(CC) -g3 -fsanitize=address -o $@ $^ $(LIB)
#	@$(CC) -o $@ $^ $(LIB)
#	$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(LFT):
	@$(MAKE) -s -C lib/libft bonus

$(GNL):
	@$(MAKE) -s -C lib/gnl

#$(MLX):
#	@$(MAKE) -s -C lib/mlx

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

re: fclean all

norm:
	@norminette src/ include/

libftnorm:
	@norminette lib/libft/*/**.c
	@norminette lib/libft/*.h

gnlnorm:
	@norminette lib/gnl/*/**.c
	@norminette lib/gnl/*.h

play :
	./$(NAME) maps/err_no_collect.ber
	./$(NAME) maps/err_no_exit.ber
	./$(NAME) maps/err_no_player.ber
	./$(NAME) maps/err_players.ber
	./$(NAME) maps/err_not_rectangle_map.ber
	./$(NAME) maps/err_not_rectangle_wall.ber
	./$(NAME) maps/simple00.ber
	./$(NAME) maps/simple01.ber
	./$(NAME) maps/my00.ber

.PHONY: all clean fclean re obj norm libftnorm gnlnorm play
