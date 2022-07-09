# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: chaejkim <chaejkim@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/08 13:41:40 by chaejkim          #+#    #+#              #
#    Updated: 2022/07/08 13:42:17 by chaejkim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc
CFLAGS = -Wall -Werror -Wextra
SAN_FLAG = -g3 -fsanitize=address

INC = -Iinclude

SRC = src/
OBJ = $(patsubst src%, obj%, $(SRC:.c=.o))

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^

obj/%.o : src/%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

all: obj $(NAME)

clean:
	rm -rf obj

fclean: clean
	@rm -rf $(NAME)

obj:
	@mkdir -p obj

re: fclean all

.PHONY: all clean fclean re
