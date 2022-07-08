# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/30 18:28:57 by chaejkim          #+#    #+#              #
#    Updated: 2022/07/01 15:57:33 by chaejkim         ###   ########.fr        #
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

SERVER_SRC = src/server.c src/server_sigaction.c src/exception.c \
			 src/set_sigaction.c
CLIENT_SRC = src/client.c src/client_sigaction.c src/exception.c \
			 src/set_sigaction.c

SERVER_OBJ = $(patsubst src%, obj%, $(SERVER_SRC:.c=.o))
CLIENT_OBJ = $(patsubst src%, obj%, $(CLIENT_SRC:.c=.o))

SERVER_BSRC = bsrc/server_bonus.c bsrc/server_sigaction_bonus.c \
			  bsrc/exception_bonus.c bsrc/set_sigaction_bonus.c
CLIENT_BSRC = bsrc/client_bonus.c bsrc/client_sigaction_bonus.c \
			  bsrc/exception_bonus.c bsrc/set_sigaction_bonus.c

SERVER_BOBJ = $(patsubst bsrc%, bobj%, $(SERVER_BSRC:.c=.o))
CLIENT_BOBJ = $(patsubst bsrc%, bobj%, $(CLIENT_BSRC:.c=.o))

ifdef IS_BONUS
	OBJS_DIR = bobj
	OBJS_SERVER = $(SERVER_BOBJ)
	OBJS_CLIENT = $(CLIENT_BOBJ)
else
	OBJS_DIR = obj
	OBJS_SERVER = $(SERVER_OBJ)
	OBJS_CLIENT = $(CLIENT_OBJ)
endif

$(NAME) : $(LFT) $(OBJS_DIR) $(SERVER_EXE) $(CLIENT_EXE)

obj/%.o : src/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

bobj/%.o : bsrc/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: $(NAME)

$(LFT):
	@$(MAKE) -s -C lib/libft bonus

bonus :
	@$(MAKE) IS_BONUS=1 $(NAME)

	
$(SERVER_EXE) : $(OBJS_SERVER)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

$(CLIENT_EXE) : $(OBJS_CLIENT)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIB)

clean:
	rm -rf obj bobj
	@$(MAKE) -s -C lib/libft $@

fclean: clean
	@make -s -C lib/libft $@
	@rm -rf $(SERVER_EXE) $(CLIENT_EXE)

obj:
	@mkdir -p obj

bobj:
	@mkdir -p bobj

re: fclean all

norm:
	@norminette \
	$(SERVER_SRC) $(CLIENT_SRC) $(SERVER_BSRC) $(CLIENT_BSRC) \
	include/minitalk.h include/minitalk_bonus.h
	@$(MAKE) -s -C lib/libft $@

.PHONY: all clean fclean re bonus norm
