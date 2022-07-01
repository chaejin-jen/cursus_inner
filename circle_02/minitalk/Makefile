# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 18:28:57 by chaejkim          #+#    #+#              #
#    Updated: 2022/07/01 09:58:19 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk
SERVER_EXE = server
CLIENT_EXE = client

CC = clang
CFLAGS = -Wall -Werror -Wextra
SAN_FLAG = -g3 -fsanitize=address

LFT = lib/libft/libft.a

INC = -Iinclude -Ilib/libft
LIB = -Llib/libft -lft

SERVER_SRC = src/server.c src/server_sigaction.c src/exception.c src/set_sigaction.c
CLIENT_SRC = src/client.c src/client_sigaction.c src/exception.c src/set_sigaction.c

SERVER_OBJ = $(patsubst src%, obj%, $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(patsubst src%, obj%, $(CLIENT_SRC:.c=.o))

obj/%.o : src/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: $(NAME)

$(NAME) : $(LFT) obj $(SERVER_EXE) $(CLIENT_EXE)

$(SERVER_EXE) : $(SERVER_OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(CLIENT_EXE) : $(CLIENT_OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(LFT):
	@$(MAKE) -s -C lib/libft bonus

clean:
	rm -rf obj
	@$(MAKE) -s -C lib/libft $@

fclean: clean
	@make -s -C lib/libft $@
	@rm -rf $(SERVER_EXE) $(CLIENT_EXE)

obj:
	@mkdir -p obj

re: fclean all

norm:
	@norminette $(SERVER_SRC) $(CLIENT_SRC)
	@$(MAKE) -s -C lib/libft $@

.PHONY: all clean fclean re norm
