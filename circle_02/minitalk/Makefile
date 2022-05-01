# NAME = minitalk
SERVER_EXE = server
CLIENT_EXE = client

CC = gcc
FLAGS = -Wall -Werror -Wextra
SAN_FLAG = -g3 -fsanitize=address

# LFT = lib/libft/libft.a

# INC = -Iinclude -Ilib/libft
# LIB = -Llib/libft -lft
SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c

SERVER_OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))
CLIENT_OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))



obj/%.o : src/%.c
	@$(CC) $(FLAGS) $(INC) -o $@ -c $<

# all: $(LFT) obj $(NAME)

# $(NAME) : $(OBJ)
# 	@$(CC) $(FLAGS) -o $@ $^ $(LIB)

# $(NAME) : $(OBJ)
# 	@$(CC) $(FLAGS) -o $@ $^ $(LIB)

$(SERVER_EXE) : $(SERVER_OBJ)
	@$(CC) $(FLAGS) -o $@ $^

$(CLIENT_EXE) : $(CLIENT_OBJ)
	@$(CC) $(FLAGS) -o $@ $^

# $(LFT):
# 	@$(MAKE) -s -C lib/libft bonus

clean:
	rm -rf obj
#	@$(MAKE) -s -C lib/libft $@

fclean: clean
#	@make -s -C lib/libft $@
#	@rm -rf $(NAME)

obj:
	@mkdir -p obj

re: fclean all

norm:
	@norminette $(SERVER_SRC) $(CLIENT_EXE)
#	@$(MAKE) -s -C lib/libft $@

.PHONY: all clean fclean re norm